#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_MODEL_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_MODEL_HPP_

#include "interface.hpp"
#include "flyBehavior/flyNoWay.hpp"
#include "quackBehavior/quack.hpp"

class ModelDuck : virtual public DuckInterface {
 public:
  ModelDuck() : DuckInterface(std::make_unique<FlyNoWay>(),
                              std::make_unique<QuackStd>()) {}

  void Display() override {
      std::cout << "I'm a model duck!" << std::endl;
      PerformFly();
      PerformQuack();
      PerformSwim();
  };
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_MODEL_HPP_
