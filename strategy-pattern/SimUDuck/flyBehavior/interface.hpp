#ifndef STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_INTERFACE_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_INTERFACE_HPP_

#include <iostream>

class FlyBehavior {
 public:
  virtual ~FlyBehavior() = 0;
  virtual void Fly() = 0;
};

FlyBehavior::~FlyBehavior() = default;

#endif //STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_INTERFACE_HPP_
