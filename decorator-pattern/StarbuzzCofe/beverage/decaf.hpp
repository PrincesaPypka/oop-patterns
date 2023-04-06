#ifndef DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_DECAF_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_DECAF_HPP_

#include "interface.hpp"

class Decaf : public BeverageInterface {
 public:
  Decaf() : BeverageInterface("Decaf") {}
  [[nodiscard]] double Cost() const override { return 1.05; }
  ~Decaf() override = default;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_DECAF_HPP_
