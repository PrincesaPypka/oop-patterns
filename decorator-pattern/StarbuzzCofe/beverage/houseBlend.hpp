#ifndef DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_HOUSEBLEND_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_HOUSEBLEND_HPP_

#include "interface.hpp"

class HouseBlend : public BeverageInterface {
 public:
  HouseBlend() : BeverageInterface("House Blend") {}
  [[nodiscard]] double Cost() const override { return .89; }
  ~HouseBlend() override = default;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_HOUSEBLEND_HPP_
