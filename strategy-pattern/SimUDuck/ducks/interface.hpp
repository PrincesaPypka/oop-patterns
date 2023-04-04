#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_

#include "flyBehavior/interface.hpp"
#include "quackBehavior/interface.hpp"

class DuckInterface {
 public:
  DuckInterface() { /* some common duck staff */ }
  virtual ~DuckInterface() = default;

  virtual void display() = 0;

  void performQuack() { QuackBehavior_->quack(); }
  void performFly() { FlyBehavior_->fly(); }
  void performSwim() { std::cout << "All ducks can swim" << std::endl; }
  /* here could be more duck actions to perform */
  void setFlyBehavior(std::unique_ptr<FlyBehavior> behavior) {
      FlyBehavior_ = std::move(behavior);
  }
  void setQuackBehavior(std::unique_ptr<QuackBehavior> behavior) {
      QuackBehavior_ = std::move(behavior);
  }
  /* here could be more duck action typesetters*/
 private:
  std::unique_ptr<FlyBehavior> FlyBehavior_ {};
  // alternatively we could use FlyBehaviorInterface *ptr and so on
  // but in this case we could have memory leaks or bad pointer issue
  // if this pointer will be destroyed somewhere else
  std::unique_ptr<QuackBehavior> QuackBehavior_ {};
  /* here could be more duck action type */
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_
