#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CHEESE2_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CHEESE2_HPP_

#include "cheese.hpp"

class Cheese2Pizza : public CheesePizza {
 public:
  Cheese2Pizza() : CheesePizza() { name_ += "2"; }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CHEESE2_HPP_
