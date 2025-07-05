#pragma once
#include <memory>

#include "HotDrink.h"

struct HotDrinkFactory { // Abstract Factory
    virtual unique_ptr<HotDrink> make() const = 0;
    virtual ~HotDrinkFactory() = default;
};

struct TeaFactory : HotDrinkFactory { // Concrete Factory
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory { // CF
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};