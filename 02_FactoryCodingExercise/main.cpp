#include <string>
using namespace std;

struct Person
{
    int id;
    string name;
};

class PersonFactory
{
    int produced_persons;
public:
    PersonFactory() {
        produced_persons = 0;
    };

    Person create_person(const string& name)
    {
        Person p{produced_persons++, name};
        return p;
    }
};

int main() {
    PersonFactory factory;
    factory.create_person("Chris");
}