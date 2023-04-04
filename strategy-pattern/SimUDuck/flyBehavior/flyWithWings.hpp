#ifndef STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYWITHWINGS_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYWITHWINGS_HPP_

#include "interface.hpp"

class FlyWithWings : public FlyBehavior {
 public:
  ~FlyWithWings() override = default;

  void fly() override { std::cout << "I can fly!" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYWITHWINGS_HPP_
