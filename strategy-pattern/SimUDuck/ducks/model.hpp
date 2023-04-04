#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_MODEL_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_MODEL_HPP_

#include "interface.hpp"
#include "flyBehavior/flyNoWay.hpp"
#include "quackBehavior/quack.hpp"

class ModelDuck : virtual public DuckInterface {
 public:
  ModelDuck() : DuckInterface() {
    setFlyBehavior(std::make_unique<FlyNoWay>());
    setQuackBehavior(std::make_unique<Quack>());
  }

  void display() override {
    std::cout << "I'm a model duck!" << std::endl;
    performFly();
    performQuack();
    performSwim();
  };
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_MODEL_HPP_
