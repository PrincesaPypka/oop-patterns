#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CLAM2_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CLAM2_HPP_

#include "clam.hpp"

class Clam2Pizza : public ClamPizza {
 public:
  Clam2Pizza() : ClamPizza() { name_ += "2"; }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_CLAM2_HPP_
