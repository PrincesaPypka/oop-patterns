#ifndef STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_MUTEQUACK_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_MUTEQUACK_HPP_

#include "interface.hpp"

class MuteQuack : public QuackBehavior{
 public:
  ~MuteQuack() override = default;

  void quack() override { std::cout << "<< silence >>" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_QUACKBEHAVIOR_MUTEQUACK_HPP_
