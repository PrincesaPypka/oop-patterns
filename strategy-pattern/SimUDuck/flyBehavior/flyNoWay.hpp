#ifndef STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYNOWAY_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYNOWAY_HPP_

#include "interface.hpp"

class FlyNoWay : public FlyBehavior {
 public:
  ~FlyNoWay() override = default;

  void Fly() override { std::cout << "I can't Fly :(" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYNOWAY_HPP_
