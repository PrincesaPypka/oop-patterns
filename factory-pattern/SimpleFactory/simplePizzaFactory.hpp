#ifndef FACTORY_PATTERN_SIMPLEFACTORY_SIMPLEPIZZAFACTORY_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_SIMPLEPIZZAFACTORY_HPP_

#include "Pizza/veggie.hpp"
#include "Pizza/cheese.hpp"
#include "Pizza/clam.hpp"
#include "Pizza/peperoni.hpp"

class SimplePizzaFactory {
 public:
  using PizzaInterfacePtr = PizzaInterface::PizzaInterfacePtr;
  enum PizzaType : unsigned short {
    VEGGIE,
    CHEESE,
    CLAM,
    PEPERONI
  };

  static PizzaInterfacePtr CreatePizza(PizzaType type) {
      PizzaInterface *pizza;
      switch (type) {
          case PizzaType::VEGGIE:pizza = new VeggiePizza();
              break;
          case PizzaType::CHEESE:pizza = new CheesePizza();
              break;
          case PizzaType::CLAM:pizza = new ClamPizza();
              break;
          case PizzaType::PEPERONI:pizza = new PeperoniPizza();
              break;
          default:pizza = nullptr;
              break;
      }
      return PizzaInterfacePtr(pizza);
  }
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_SIMPLEPIZZAFACTORY_HPP_
