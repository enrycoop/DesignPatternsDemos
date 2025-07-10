#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <ostream>
using namespace std;

struct Address {
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite)
        : street(street),
          city(city),
          suite(suite) {
    }

    Address(const Address &other)
        : street {other.street}, city {other.city}, suite {other.suite} {}

    friend std::ostream & operator<<(std::ostream &os, const Address &obj) {
        return os
               << "street: " << obj.street
               << " city: " << obj.city
               << " suite: " << obj.suite;
    }
};


struct Contact {
    string name;
    Address* address;

    Contact(const string &name, Address *address)
        : name(name),
          address(address) {
    }

    // un modo per definire la deep copy e' con un costruttore di copia
    Contact(const Contact &other)
        : name {other.name}
        , address {new Address {*other.address}}
    {}

    friend std::ostream & operator<<(std::ostream &os, const Contact &obj) {
        return os
               << "name: " << obj.name
               << " addres: " << *obj.address;
    }
    ~Contact() {
        delete address;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee
        (const string &name, const int suite)
    {
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return new_employee(name, suite, p);
    }
private:
    static unique_ptr<Contact> new_employee(const string &name, const int suite, const Contact &prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

int main() {
    auto john = EmployeeFactory::new_main_office_employee("John", 123);


    cout << *john << endl;


    return 0;
}