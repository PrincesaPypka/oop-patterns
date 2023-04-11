#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZASTORE_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZASTORE_HPP_

#include <iostream>
#include "simplePizzaFactory.hpp"

class PizzaStore {
 public:
  using PizzaType = SimplePizzaFactory::PizzaType;
  using PizzaInterfacePtr = PizzaInterface::PizzaInterfacePtr;
  PizzaStore() = delete;
  explicit PizzaStore(std::unique_ptr<SimplePizzaFactory> &factory) :
      factory_(std::move(factory)) {}
  std::shared_ptr<PizzaInterface> OrderPizza(PizzaType type) {
      PizzaInterfacePtr pizza = factory_->CreatePizza(type);
      std::cout << pizza->Prepare().str() << pizza->Bake().str();
      std::cout << pizza->Cut().str() << pizza->Box().str();
      return pizza;
  }
 private:
  std::unique_ptr<SimplePizzaFactory> factory_;
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZASTORE_HPP_
