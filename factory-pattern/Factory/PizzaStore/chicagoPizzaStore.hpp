#ifndef FACTORY_PATTERN_FACTORY_PIZZASTORE_CHICAGOPIZZASTORE_HPP_
#define FACTORY_PATTERN_FACTORY_PIZZASTORE_CHICAGOPIZZASTORE_HPP_

#include "interface.hpp"
#include "Pizza/veggie2.hpp"
#include "Pizza/cheese2.hpp"
#include "Pizza/clam2.hpp"
#include "Pizza/peperoni2.hpp"

class ChicagoPizzaStore : public PizzaStoreInterface {
 public:
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
          case PizzaType::VEGGIE:pizza = new Veggie2Pizza();
              break;
          case PizzaType::CHEESE:pizza = new Cheese2Pizza();
              break;
          case PizzaType::CLAM:pizza = new Clam2Pizza();
              break;
          case PizzaType::PEPERONI:pizza = new Peperoni2Pizza();
              break;
          default:pizza = nullptr;
              break;
      }
      return PizzaInterfacePtr(pizza);
  }
};

#endif //FACTORY_PATTERN_FACTORY_PIZZASTORE_CHICAGOPIZZASTORE_HPP_
