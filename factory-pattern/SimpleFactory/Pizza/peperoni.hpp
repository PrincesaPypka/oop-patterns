#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_PEPERONI_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_PEPERONI_HPP_

#include "interface.hpp"

class PeperoniPizza : public PizzaInterface {
 public:
  PeperoniPizza() {
      name_ = "Peperoni Pizza";
      dough_ = "Crust";
      sauce_ = "Marinara Sauce";
      toppings_.emplace_back("Sliced Peperoni");
      toppings_.emplace_back("Sliced onion");
      toppings_.emplace_back("Grated parmesan cheese");
  }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_PEPERONI_HPP_
