#ifndef FACTORY_PATTERN_FACTORY_PIZZASTORE_INTERFACE_HPP_
#define FACTORY_PATTERN_FACTORY_PIZZASTORE_INTERFACE_HPP_

#include <iostream>

#include "Pizza/interface.hpp"

class PizzaStoreInterface {
 public:
  enum class PizzaType : unsigned short {};

  using PizzaInterfacePtr = PizzaInterface::PizzaInterfacePtr;
  PizzaInterfacePtr OrderPizza(PizzaType type);
  virtual ~PizzaStoreInterface() = 0;

 protected:
  virtual PizzaInterfacePtr CreatePizza(PizzaType type) = 0;

};

#endif //FACTORY_PATTERN_FACTORY_PIZZASTORE_INTERFACE_HPP_
