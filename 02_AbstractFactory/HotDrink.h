#pragma once
#include <iostream>

using namespace std;

struct HotDrink {
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
    void prepare(int volume) override{
        cout << "Take tea bag, boil water, pour" << volume
        << "ml, add some lemon\n";
    }
};

struct Coffee : HotDrink {
    void prepare(int volume) override{
        cout << "Grind some beans, boil water, pour " << volume
        << "ml, add cream, enjoy!\n";
    }
};
