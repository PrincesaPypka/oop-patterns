#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_MALLARD_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_MALLARD_HPP_

#include "interface.hpp"
#include "flyBehavior/flyWithWings.hpp"
#include "quackBehavior/quack.hpp"

class MallardDuck : public DuckInterface {
 public:
  MallardDuck() : DuckInterface() {
    setFlyBehavior(std::make_unique<FlyWithWings>());
    setQuackBehavior(std::make_unique<Quack>());
  }

  void display() override {
    std::cout << "I'm a mallard duck!" << std::endl;
    performFly();
    performQuack();
    performSwim();
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_MALLARD_HPP_
