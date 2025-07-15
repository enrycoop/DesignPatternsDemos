#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <gtest/gtest.h>

#include <boost/lexical_cast.hpp>


#define PATH "./capitals.txt"


class Database
{
    public:
    virtual ~Database() = default;
    virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase final : public Database
{
    SingletonDatabase()
    {
        std::cout << "Initialzing database\n";
        std::ifstream ifs(PATH);
        if (ifs.is_open()) {
            std::string s, s2;
            while(std::getline(ifs, s))
            {
                getline(ifs, s2);
                int pop = boost::lexical_cast<int>(s2);
                capitals[s] = pop;
            }
            if (capitals.empty())
                std::cout << "No capitals found\n";
        }else {
            std::cout << "Unable to open database file\n";
        }
    }
    std::map<std::string, int> capitals;
public:
    //cancelliamo il costruttore
    SingletonDatabase(SingletonDatabase const&) = delete;
    SingletonDatabase& operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase instance;
        return instance;
    }

    int get_population(const std::string& s) override
    {
        return capitals[s];
    }
};

class DummyDatabase : public Database
{
    std::map<std::string, int> capitals;
    public:
    DummyDatabase()
    {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["charlie"] = 3;
    }

    int get_population(const std::string& s) override
    {
        return capitals[s];
    }
};

struct SingletonRecordFinder {
    int total_population(const std::vector<std::string>& names) {
        int result{0};
        for (auto& name : names) {
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};

struct ConfigurableRecordFinder
{
    Database& db;

    explicit ConfigurableRecordFinder(Database& db) : db(db) {}

    int total_population(std::vector<std::string> names) {
        int result{0};
        for (auto& name : names) {
            result += db.get_population(name);
        }
        return result;
    }
};


//#######################################################//
// TESTS
//#######################################################//

TEST(RecordFinderTests, SingletonTotalPopulationTest) {
    SingletonRecordFinder finder;
    std::vector<std::string> names{"Tokyo","Seul"};
    int tp = finder.total_population(names);
    ASSERT_EQ(tp, 13960000+9776000);
}

TEST(RecordFinderTests, DependantTotalPopulationTest) {
    DummyDatabase db;
    ConfigurableRecordFinder finder(db);
    EXPECT_EQ(3, finder.total_population(std::vector<std::string>{"alpha","beta"}));
}



int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
