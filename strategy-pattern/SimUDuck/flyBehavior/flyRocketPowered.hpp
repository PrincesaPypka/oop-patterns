#ifndef STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYROCKETPOWERED_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYROCKETPOWERED_HPP_

#include "interface.hpp"

class FlyRocketPowered : public FlyBehavior {
 public:
  ~FlyRocketPowered() override = default;

  void Fly() override {
      std::cout << "I'm fling with rocket power!" << std::endl;
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_FLYBEHAVIOR_FLYROCKETPOWERED_HPP_
