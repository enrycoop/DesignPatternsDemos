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

    friend std::ostream & operator<<(std::ostream &os, const Contact &obj) {
        return os
               << "name: " << obj.name
               << " addres: " << *obj.address;
    }
};


int main() {
    Contact john{"John Wick",new Address{"Every", "where", 123}};
    //Contact ballerina{"Ballerina",Address{"Every", "where", 13}};
    Contact ballerina = john;
    ballerina.name = "Ballerina";
    ballerina.address->suite = 13;

    cout << john << endl << ballerina << endl;

    delete john.address;
    return 0;
}