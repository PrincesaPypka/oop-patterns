#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_RUBBER_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_RUBBER_HPP_

#include "interface.hpp"
#include "flyBehavior/flyNoWay.hpp"
#include "quackBehavior/squeak.hpp"

class RubberDuck : public DuckInterface {
 public:
  RubberDuck() : DuckInterface() {
      setFlyBehavior(std::make_unique<FlyNoWay>());
      setQuackBehavior(std::make_unique<Squeak>());
  }
  void display() override {
      std::cout << "I'm a rubber duck!" << std::endl;
      performFly();
      performQuack();
      performSwim();
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_RUBBER_HPP_
