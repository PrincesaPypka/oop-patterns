#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_RUBBER_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_RUBBER_HPP_

#include "interface.hpp"
#include "flyBehavior/flyNoWay.hpp"
#include "quackBehavior/squeak.hpp"

class RubberDuck : public DuckInterface {
 public:
  RubberDuck() : DuckInterface() {
      SetFlyBehavior(std::make_unique<FlyNoWay>());
      SetQuackBehavior(std::make_unique<Squeak>());
  }
  void Display() override {
      std::cout << "I'm a rubber duck!" << std::endl;
      PerformFly();
      PerformQuack();
      PerformSwim();
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_RUBBER_HPP_
