#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_PEPERONI2_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_PEPERONI2_HPP_

#include "peperoni.hpp"

class Peperoni2Pizza : public PeperoniPizza {
 public:
  Peperoni2Pizza() : PeperoniPizza() { name_ += "2"; }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_PEPERONI2_HPP_
