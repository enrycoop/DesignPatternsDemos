#include <iostream>
#include <boost/lexical_cast.hpp>
#include "di.h"

using namespace std;

struct IFoo
{
    virtual string name() = 0;
};

struct Foo : IFoo
{
    static int id;
    Foo() { ++id; }

    string name() override
    {
        return "Foo "s + boost::lexical_cast<string>(id);
    }
};

int Foo::id = 0;

struct Bar
{
    std::shared_ptr<IFoo> foo;
};

int main()
{
    // impostiamo il DI in modo da creare una singleton di Foo
    auto injector = boost::di::make_injector(
        boost::di::bind<IFoo>().to<Foo>().in(boost::di::singleton)
    );

    const auto bar1 = injector.create<std::shared_ptr<Bar>>();
    const auto bar2 = injector.create<std::shared_ptr<Bar>>();

    //ci assicuriamo che sia la stessa istanza
    std::cout << bar1->foo->name() << std::endl;
    std::cout << bar2->foo->name() << std::endl;

    std::cout << boolalpha
              << (bar1->foo.get() == bar2->foo.get())
              << std::endl;

    return 0;
}
