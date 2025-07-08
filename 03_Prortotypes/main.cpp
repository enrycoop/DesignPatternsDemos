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


int main() {
    Contact john{"John Wick",new Address{"Every", "where", 123}};
    //Contact ballerina{"Ballerina",Address{"Every", "where", 13}};
    Contact ballerina{john}; // shallow copy
    ballerina.name = "Ballerina";
    ballerina.address->suite = 13;

    cout << john << endl << ballerina << endl;


    return 0;
}