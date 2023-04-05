#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_DECOY_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_DECOY_HPP_

#include "interface.hpp"
#include "flyBehavior/flyRocketPowered.hpp"
#include "quackBehavior/muteQuack.hpp"

class DecoyDuck : public DuckInterface {
 public:
  DecoyDuck() : DuckInterface(std::make_unique<FlyRocketPowered>(),
                              std::make_unique<MuteQuack>()) {}

  void Display() override {
      std::cout << "I'm a decoy duck!" << std::endl;
      PerformFly();
      PerformQuack();
      PerformSwim();
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_DECOY_HPP_
