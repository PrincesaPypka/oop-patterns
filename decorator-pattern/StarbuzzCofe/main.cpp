#include "beverage/espresso.hpp"
#include "beverage/darkRoast.hpp"
#include "beverage/houseBlend.hpp"

#include "condiment/mocha.hpp"
#include "condiment/whip.hpp"
#include "condiment/soy.hpp"

#include <iostream>

int main() {
    BeverageInterface *beverage = new Espresso();
    std::cout << beverage->GetDescription() << " $" << beverage->Cost()
              << std::endl;
    delete beverage;

    beverage = new DarkRoast();
    beverage = new Mocha(beverage);
    beverage = new Mocha(beverage);
    beverage = new Whip(beverage);
    std::cout << beverage->GetDescription() << " $" << beverage->Cost()
              << std::endl;
    delete beverage;

    beverage = new HouseBlend();
    beverage = new Mocha(beverage);
    beverage = new Soy(beverage);
    beverage = new Whip(beverage);
    std::cout << beverage->GetDescription() << " $" << beverage->Cost()
              << std::endl;
    return 0;
}