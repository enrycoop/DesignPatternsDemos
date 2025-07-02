#include <iostream>
#include <string>
#include <ostream>
#include <vector>
using namespace std;


class CodeBuilder;

class Class {
    friend class CodeBuilder;

    std::string name;
    vector<pair<string, string>> fields;
public:
    friend std::ostream& operator<<(std::ostream& os, const Class& obj)
    {
        os << "class " << obj.name << "\n{\n";

        for (const auto& field : obj.fields)
            os << "  " << field.second << " " << field.first << ";" <<endl;
        os << "};\n";
        return os;
    }
};

class CodeBuilder
{
    Class c;
public:
    explicit CodeBuilder(const string& class_name)
    {
        c.name = class_name;
        c.fields = {};
    }

    CodeBuilder& add_field(const string& name, const string& type)
    {
        c.fields.emplace_back(name, type);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << obj.c;
        return os;
    }
};


int main()
{
    auto cb = CodeBuilder{"Person"}
    .add_field("name", "string")
    .add_field("age", "int");
    std::cout << cb;
}