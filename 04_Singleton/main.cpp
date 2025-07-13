#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

#include <boost/lexical_cast.hpp>


#define PATH "/home/enrico/CLionProjects/DesignPatternsDemos/04_Singleton/capitals.txt"


class SingletonDatabase
{
    SingletonDatabase()
    {
        cout << "Initialzing database\n";
        ifstream ifs(PATH);
        if (ifs.is_open()) {
            string s, s2;
            while(std::getline(ifs, s))
            {
                getline(ifs, s2);
                int pop = boost::lexical_cast<int>(s2);
                capitals[s] = pop;
            }
            if (capitals.empty())
                cout << "No capitals found\n";
        }else {
            cout << "Unable to open database file\n";
        }
    }
    map<string, int> capitals;
public:
    //cancelliamo il costruttore
    SingletonDatabase(SingletonDatabase const&) = delete;
    SingletonDatabase& operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase instance;
        return instance;
    }

    int get_population(const string& s)
    {
        return capitals[s];
    }
};

struct SingletonRecordFinder {
    int total_population(vector<string> names) {
        int result{0};
        for (auto& name : names) {
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};

TEST(RecordFinderTests, SingletonTotalPopulationTest) {
    SingletonRecordFinder finder;
    vector<string> names{"Tokyo","Seul"};
    int tp = finder.total_population(names);
    ASSERT_EQ(tp, 13960000+9776000);
}

int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();

    return 0;
}
