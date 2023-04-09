#ifndef DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_DARKROAST_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_DARKROAST_HPP_

#include "interface.hpp"

class DarkRoast : public BeverageInterface {
 public:
  DarkRoast() : BeverageInterface("Dark Roast") {}
  [[nodiscard]] double Cost() const override { return .99; }
  ~DarkRoast() override = default;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_DARKROAST_HPP_
