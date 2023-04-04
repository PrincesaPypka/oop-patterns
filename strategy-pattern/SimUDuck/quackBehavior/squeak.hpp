#ifndef STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_SQUEAK_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_SQUEAK_HPP_

#include "interface.hpp"

class Squeak : public QuackBehavior {
 public:
  ~Squeak() override = default;

  void quack() override { std::cout << "Squeak" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_SQUEAK_HPP_
