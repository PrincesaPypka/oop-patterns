#ifndef STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYWITHWINGS_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYWITHWINGS_HPP_

#include "interface.hpp"

class FlyWithWings : public FlyBehavior {
 public:
  ~FlyWithWings() override = default;

  void Fly() override { std::cout << "I can Fly!" << std::endl; }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYWITHWINGS_HPP_
