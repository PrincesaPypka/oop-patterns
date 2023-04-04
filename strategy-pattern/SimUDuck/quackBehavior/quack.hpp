#ifndef STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_QUACK_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_QUACK_HPP_

#include "interface.hpp"

class Quack : public QuackBehavior {
 public:
  ~Quack() override = default;

  void quack() override { std::cout << "Quack" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_QUACK_HPP_
