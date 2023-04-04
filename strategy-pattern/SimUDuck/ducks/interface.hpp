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
 * ducks should have, such as Display, Quack, Fly, and swim. It also
 * provides methods for setting the duck's Quack and Fly
 * behaviors dynamically, using the Strategy pattern.
 */
class DuckInterface {
 public:
  /**
   * @brief Constructs a new DuckInterface object.
   *
   * This constructor initializes any common duck properties or behaviors.
   */
  DuckInterface() : DuckInterface(std::unique_ptr<FlyBehavior>(),
                                  std::unique_ptr<QuackBehavior>()) {
      /* some common duck staff */
  }

  DuckInterface(const DuckInterface &copy) = delete;

  /**
   * @brief Constructs a new DuckInterface object.
   *
   * This move constructor initializes any common duck properties or behaviors.
   */
  DuckInterface(DuckInterface &&copy) noexcept
      : fly_behavior_(std::move(copy.fly_behavior_)),
        quack_behavior_(std::move(copy.quack_behavior_)) {
      std::cout << "Move constructor" << std::endl;
  }

  /**
   * @brief Destroys the DuckInterface object.
   *
   * This virtual destructor is defined as default, allowing derived classes
   * to clean up their own resources as needed.
   */
  virtual ~DuckInterface() = default;

  DuckInterface &operator=(const DuckInterface &o) = delete;

  /**
   * @brief Displays the duck's appearance and behavior.
   *
   * This pure virtual method should be overridden by derived classes
   * to provide a custom Display implementation for each type of duck.
   */
  virtual void Display() = 0;

  /**
   * @brief Performs the duck's Quack behavior.
   *
   * This method delegates the Quack behavior to the current QuackBehavior
   * object, which can be set dynamically using SetQuackBehavior().
   */
  void PerformQuack() { quack_behavior_->Quack(); }

  /**
   * @brief Performs the duck's Fly behavior.
   *
   * This method delegates the Fly behavior to the current FlyBehavior
   * object, which can be set dynamically using SetFlyBehavior().
   */
  void PerformFly() { fly_behavior_->Fly(); }

  /**
   * @brief Performs the duck's swim behavior.
   *
   * This method is common to all ducks and is implemented here to provide
   * a default behavior for swimming.
   */
  void PerformSwim() { std::cout << "All ducks can swim" << std::endl; }

  /**
   * @brief Sets the duck's Fly behavior dynamically.
   *
   * This method takes a unique_ptr to a FlyBehavior object, which encapsulates
   * a specific Fly behavior algorithm. The current FlyBehavior object is
   * replaced with the new one, allowing the duck's Fly behavior to be changed
   * dynamically at runtime.
   *
   * @param behavior The new FlyBehavior object to use.
   */
  void SetFlyBehavior(std::unique_ptr<FlyBehavior> behavior) {
      fly_behavior_ = std::move(behavior);
  }

  /**
   * @brief Sets the duck's Quack behavior dynamically.
   *
   * This method takes a unique_ptr to a QuackBehavior object, which
   * encapsulates a specific Quack behavior algorithm. The current
   * QuackBehavior object is replaced with the new one, allowing the
   * duck's Quack behavior to be changed dynamically at runtime.
   *
   * @param behavior The new QuackBehavior object to use.
   */
  void SetQuackBehavior(std::unique_ptr<QuackBehavior> behavior) {
      quack_behavior_ = std::move(behavior);
  }

 protected:
  /**
   * @brief Constructs a new DuckInterface object.
   *
   * This constructor initializes any common duck properties or behaviors.
   */
  DuckInterface(std::unique_ptr<FlyBehavior> fly,
                std::unique_ptr<QuackBehavior> quack) :
      fly_behavior_(std::move(fly)),
      quack_behavior_(std::move(quack)) {}

 private:
  // Alternatively, we could have used a raw pointer like FlyBehavior *ptr,
  // but that could lead to issues such as memory leaks or dangling pointers
  // if the pointer is deleted somewhere else.
  // Using std::unique_ptr avoids these potential problems.
  std::unique_ptr<FlyBehavior> fly_behavior_;
  std::unique_ptr<QuackBehavior> quack_behavior_;
};

#endif //STRATEGY_PATTERN_SIMUDUCK_DUCKS_DUCKINTERFACE_HPP_
