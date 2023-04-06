#ifndef DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_ESPRESSO_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_ESPRESSO_HPP_

#include "interface.hpp"

class Espresso : public BeverageInterface {
 public:
  Espresso() : BeverageInterface("Espresso") {}
  [[nodiscard]] double Cost() const override { return 1.99; }
  ~Espresso() override = default;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_ESPRESSO_HPP_
