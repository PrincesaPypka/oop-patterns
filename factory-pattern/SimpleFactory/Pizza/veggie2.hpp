#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_VEGGIE2_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_VEGGIE2_HPP_

#include "veggie.hpp"

class Veggie2Pizza : public VeggiePizza {
 public:
  Veggie2Pizza() : VeggiePizza() { name_ += "2"; }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_VEGGIE2_HPP_
