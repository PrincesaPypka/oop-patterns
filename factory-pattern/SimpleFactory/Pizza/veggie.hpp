#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_VEGGIE_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_VEGGIE_HPP_

#include "interface.hpp"

class VeggiePizza : public PizzaInterface {
 public:
  VeggiePizza() {
      name_ = "Veggie Pizza";
      dough_ = "Crust";
      sauce_ = "Marinara Sauce";
      toppings_.emplace_back("Fresh Mozzarella");
      toppings_.emplace_back("Diced onion");
      toppings_.emplace_back("Sliced mushrooms");
      toppings_.emplace_back("Sliced red pepper");
      toppings_.emplace_back("Black olives");
      toppings_.emplace_back("Grated Parmesan");
  }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_VEGGIE_HPP_
