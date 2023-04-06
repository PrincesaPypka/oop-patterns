#ifndef DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_SOY_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_SOY_HPP_

#include "decorator.hpp"

class Soy : public CondimentDecorator {
 public:
  explicit Soy(BeverageInterface *drink) : CondimentDecorator(drink) {
      description_ = beverage_->GetDescription() + ", Soy";
  }
  [[nodiscard]] double Cost() const override { return beverage_->Cost() + .15; }
  ~Soy() override { delete beverage_; }
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_SOY_HPP_
