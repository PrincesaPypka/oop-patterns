#ifndef STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_QUACK_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_QUACK_HPP_

#include "interface.hpp"

class QuackStd : public QuackBehavior {
 public:
  ~QuackStd() override = default;

  void Quack() override { std::cout << "Quack" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_QUACK_HPP_
