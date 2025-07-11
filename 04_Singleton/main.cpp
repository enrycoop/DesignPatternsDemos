#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

#include <boost/lexical_cast.hpp>

class SingletonDatabase
{
    SingletonDatabase()
    {
        cout << "Initialzing database\n";
        ifstream ifs("capitals.txt");
        string s, s2;
        while(std::getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
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

int main()
{
    string city = "Tokyo";
    cout << city << " has population " << SingletonDatabase::get().get_population(city) << endl;

    return 0;
}
