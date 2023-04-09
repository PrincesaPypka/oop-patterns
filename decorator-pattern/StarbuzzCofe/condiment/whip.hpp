#ifndef DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_WHIP_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_WHIP_HPP_

#include "decorator.hpp"

class Whip : public CondimentDecorator {
 public:
  explicit Whip(BeverageInterface *drink) : CondimentDecorator(drink) {
      description_ = beverage_->GetDescription() + ", Whip";
  }
  [[nodiscard]] double Cost() const override { return beverage_->Cost() + .10; }
  ~Whip() override { delete beverage_; };
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_WHIP_HPP_
