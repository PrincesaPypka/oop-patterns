#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_MALLARD_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_MALLARD_HPP_

#include "interface.hpp"
#include "flyBehavior/flyWithWings.hpp"
#include "quackBehavior/quack.hpp"

class MallardDuck : public DuckInterface {
 public:
  MallardDuck() : DuckInterface(std::make_unique<FlyWithWings>(),
                                std::make_unique<QuackStd>()) {}

  void Display() override {
      std::cout << "I'm a mallard duck!" << std::endl;
      PerformFly();
      PerformQuack();
      PerformSwim();
  }
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_MALLARD_HPP_
