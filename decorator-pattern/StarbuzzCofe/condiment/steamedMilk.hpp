#ifndef DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_STEAMEDMILK_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_STEAMEDMILK_HPP_

#include "decorator.hpp"

class SteamedMilk : public CondimentDecorator {
 public:
  explicit SteamedMilk(BeverageInterface *drink) : CondimentDecorator(drink) {
      description_ = beverage_->GetDescription() + ", Steamed milk";
  }
  [[nodiscard]] double Cost() const override { return beverage_->Cost() + .1; }
  ~SteamedMilk() override { delete beverage_; }
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_STEAMEDMILK_HPP_
