#ifndef DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_DECORATOR_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_DECORATOR_HPP_

#include "beverage/interface.hpp"

class CondimentDecorator : public BeverageInterface {
 public:
  explicit CondimentDecorator(BeverageInterface *beverage) :
      beverage_(beverage) {}
  [[nodiscard]] double Cost() const override = 0;
  virtual ~CondimentDecorator() = 0;

 protected:
  BeverageInterface *beverage_;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_DECORATOR_HPP_
