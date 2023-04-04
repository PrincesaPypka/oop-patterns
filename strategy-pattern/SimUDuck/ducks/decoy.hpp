#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_DECOY_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_DECOY_HPP_

#include "interface.hpp"
#include "flyBehavior/flyRocketPowered.hpp"
#include "quackBehavior/muteQuack.hpp"

class DecoyDuck : public DuckInterface {
 public:
  DecoyDuck() : DuckInterface() {
    setFlyBehavior(std::make_unique<FlyRocketPowered>());
    setQuackBehavior(std::make_unique<MuteQuack>());
  }
  ~DecoyDuck() override = default;

  void display() override {
    std::cout << "I'm a decoy duck!" << std::endl;
    performFly();
    performQuack();
    performSwim();
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_DECOY_HPP_
