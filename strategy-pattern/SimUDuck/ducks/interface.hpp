#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_

#include "flyBehavior/interface.hpp"
#include "quackBehavior/interface.hpp"

/**
 * @class DuckInterface
 *
 * @brief Provides a common interface for ducks.
 *
 * The DuckInterface class defines a set of common methods that all
 * ducks should have, such as display, quack, fly, and swim. It also
 * provides methods for setting the duck's quack and fly
 * behaviors dynamically, using the Strategy pattern.
 */
class DuckInterface {
 public:
  /**
   * @brief Constructs a new DuckInterface object.
   *
   * This constructor initializes any common duck properties or behaviors.
   */
  DuckInterface() { /* some common duck staff */ }

  /**
   * @brief Destroys the DuckInterface object.
   *
   * This virtual destructor is defined as default, allowing derived classes
   * to clean up their own resources as needed.
   */
  virtual ~DuckInterface() = default;

  /**
   * @brief Displays the duck's appearance and behavior.
   *
   * This pure virtual method should be overridden by derived classes
   * to provide a custom display implementation for each type of duck.
   */
  virtual void display() = 0;

  /**
   * @brief Performs the duck's quack behavior.
   *
   * This method delegates the quack behavior to the current QuackBehavior
   * object, which can be set dynamically using setQuackBehavior().
   */
  void performQuack() { QuackBehavior_->quack(); }

  /**
   * @brief Performs the duck's fly behavior.
   *
   * This method delegates the fly behavior to the current FlyBehavior
   * object, which can be set dynamically using setFlyBehavior().
   */
  void performFly() { FlyBehavior_->fly(); }

  /**
   * @brief Performs the duck's swim behavior.
   *
   * This method is common to all ducks and is implemented here to provide
   * a default behavior for swimming.
   */
  void performSwim() { std::cout << "All ducks can swim" << std::endl; }

  /**
   * @brief Sets the duck's fly behavior dynamically.
   *
   * This method takes a unique_ptr to a FlyBehavior object, which encapsulates
   * a specific fly behavior algorithm. The current FlyBehavior object is
   * replaced with the new one, allowing the duck's fly behavior to be changed
   * dynamically at runtime.
   *
   * @param behavior The new FlyBehavior object to use.
   */
  void setFlyBehavior(std::unique_ptr<FlyBehavior> behavior) {
      FlyBehavior_ = std::move(behavior);
  }

  /**
   * @brief Sets the duck's quack behavior dynamically.
   *
   * This method takes a unique_ptr to a QuackBehavior object, which
   * encapsulates a specific quack behavior algorithm. The current
   * QuackBehavior object is replaced with the new one, allowing the
   * duck's quack behavior to be changed dynamically at runtime.
   *
   * @param behavior The new QuackBehavior object to use.
   */
  void setQuackBehavior(std::unique_ptr<QuackBehavior> behavior) {
      QuackBehavior_ = std::move(behavior);
  }

 private:
  // Alternatively, we could have used a raw pointer like FlyBehavior *ptr,
  // but that could lead to issues such as memory leaks or dangling pointers
  // if the pointer is deleted somewhere else.
  // Using std::unique_ptr avoids these potential problems.
  std::unique_ptr<FlyBehavior> FlyBehavior_{};
  std::unique_ptr<QuackBehavior> QuackBehavior_{};
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_
