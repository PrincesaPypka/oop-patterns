#ifndef FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_INTERFACE_HPP_
#define FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_INTERFACE_HPP_

#include <sstream>
#include <list>

class PizzaInterface {
 public:
  [[nodiscard]] std::string GetName() const { return name_; }
  [[nodiscard]] std::stringstream Prepare() const;
  [[nodiscard]] std::stringstream Bake() const;
  [[nodiscard]] std::stringstream Cut() const;
  [[nodiscard]] std::stringstream Box() const;
  std::stringstream &operator<<(std::stringstream &ss) const;
  virtual ~PizzaInterface() = 0;

 protected:
  std::string name_;
  std::string dough_;
  std::string sauce_;
  std::list<std::string> toppings_ = {};
  PizzaInterface() = default;
};

#endif //FACTORY_PATTERN_SIMPLEFACTORY_PIZZA_INTERFACE_HPP_
