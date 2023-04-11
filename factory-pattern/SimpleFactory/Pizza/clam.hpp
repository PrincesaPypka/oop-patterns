#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CLAM_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CLAM_HPP_

#include "interface.hpp"

class ClamPizza : public PizzaInterface {
 public:
  ClamPizza() {
      name_ = "Clam Pizza";
      dough_ = "Thin Crust";
      sauce_ = "White garlic Sauce";
      toppings_.emplace_back("Clams");
      toppings_.emplace_back("Grated parmesan cheese");
  }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CLAM_HPP_
