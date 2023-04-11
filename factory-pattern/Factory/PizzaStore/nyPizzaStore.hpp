#ifndef FACTORY_PATTERN_FACTORY_PIZZASTORE_NYPIZZASTORE_HPP_
#define FACTORY_PATTERN_FACTORY_PIZZASTORE_NYPIZZASTORE_HPP_

#include "interface.hpp"
#include "Pizza/veggie.hpp"
#include "Pizza/cheese.hpp"
#include "Pizza/clam.hpp"
#include "Pizza/peperoni.hpp"

class NYPizzaStore : public PizzaStoreInterface {
 public:
  using PizzaInterfacePtr = PizzaStoreInterface::PizzaInterfacePtr;
  enum PizzaType {
    VEGGIE,
    CHEESE,
    CLAM,
    PEPERONI
  };

  ~NYPizzaStore() override = default;
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

#endif //FACTORY_PATTERN_FACTORY_PIZZASTORE_NYPIZZASTORE_HPP_
