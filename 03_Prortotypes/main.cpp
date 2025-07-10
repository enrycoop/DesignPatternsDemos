#include <iostream>
#include <ostream>
#include <sstream>
#include <memory>
using namespace std;

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
using namespace boost;

struct Address {
    string street, city;
    int suite;
    Address() = default;

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

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & street;
        ar & city;
        ar & suite;

    }
};


struct Contact {

    string name;
    Address* address;

    Contact() : address(nullptr) {};
    Contact(const string &name, Address *address)
        : name(name),
          address(address) {
    }

    // un modo per definire la deep copy e' con un costruttore di copia
    Contact(const Contact &other)
        : name {other.name}
        , address {new Address {*other.address}}
    {}

    ~Contact() {delete address;}

    friend std::ostream & operator<<(std::ostream &os, const Contact &obj) {
        return os
               << "name: " << obj.name
               << " address: " << *obj.address;
    }
private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned version)
    {
        ar & name;
        ar & address;

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
    auto clone =[](const Contact& c)
    {
        ostringstream oss;
        archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();
        cout << s << endl;

        istringstream iss(s);
        archive::text_iarchive ia(iss);
        Contact result;
        ia >> result;
        return result;
    };

    auto john = EmployeeFactory::new_main_office_employee("John", 123);
    auto jane = clone(*john);
    jane.name = "Jane";
    cout << *john << endl << jane << endl;
    return 0;
}