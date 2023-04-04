#ifndef STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_INTERFACE_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_INTERFACE_HPP_

#include <iostream>

class QuackBehavior {
 public:
  virtual ~QuackBehavior() = default;

  virtual void Quack() = 0;
};

#endif //STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_INTERFACE_HPP_
