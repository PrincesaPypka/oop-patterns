#ifndef FACTORY_PATTERN_FACTORY_PIZZASTORE_CHICAGOPIZZASTORE_HPP_
#define FACTORY_PATTERN_FACTORY_PIZZASTORE_CHICAGOPIZZASTORE_HPP_

#include "interface.hpp"
#include "Pizza/veggie2.hpp"
#include "Pizza/cheese2.hpp"
#include "Pizza/clam2.hpp"
#include "Pizza/peperoni2.hpp"

class ChicagoPizzaStore : public PizzaStoreInterface {
  using PizzaInterfacePtr = PizzaStoreInterface::PizzaInterfacePtr;
  enum class PizzaType {
    VEGGIE,
    CHEESE,
    CLAM,
    PEPERONI
  };

  ~ChicagoPizzaStore() override = default;
 protected:
  PizzaInterfacePtr CreatePizza(PizzaStoreInterface::PizzaType type) override {
      auto type_t = static_cast<PizzaType>(type);
      PizzaInterface *pizza;
      switch (type_t) {
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

#endif //FACTORY_PATTERN_FACTORY_PIZZASTORE_CHICAGOPIZZASTORE_HPP_
