#include <iostream>
#include <memory>

#include "DrinkFactory.h"
using namespace std;

#include "HotDrink.h"

unique_ptr<HotDrink> make_drink(string type) {
    unique_ptr<HotDrink> drink;
    if (type == "tea") {
        drink = make_unique<Tea>();
        drink->prepare(200);
    }else {
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

int main() {
    //auto d = make_drink("coffee");
    DrinkFactory df;
    auto c = df.make_drink("coffee");
    return 0;
}