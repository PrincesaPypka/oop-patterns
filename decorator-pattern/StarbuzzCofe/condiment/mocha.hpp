#ifndef DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_MOCHA_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_MOCHA_HPP_

#include "decorator.hpp"

class Mocha : public CondimentDecorator {
 public:
  explicit Mocha(BeverageInterface *drink) : CondimentDecorator(drink) {
      description_ = beverage_->GetDescription() + ", Mocha";
  }
  [[nodiscard]] double Cost() const override { return beverage_->Cost() + .2; }
  ~Mocha() override { delete beverage_; };
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_MOCHA_HPP_
