#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CHEESE_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CHEESE_HPP_

#include "interface.hpp"

class CheesePizza : public PizzaInterface {
 public:
  CheesePizza() {
      name_ = "Cheese Pizza";
      dough_ = "Regular Crust";
      sauce_ = "Marinara Pizza Sauce";
      toppings_.emplace_back("Parmesan");
      toppings_.emplace_back("Shredded Mozzarella");
  }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CHEESE_HPP_
