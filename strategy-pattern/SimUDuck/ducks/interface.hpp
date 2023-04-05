#ifndef STRATEGY_PATTERN_SIMUDUCK_DUCKS_INTERFACE_HPP_
#define STRATEGY_PATTERN_SIMUDUCK_DUCKS_INTERFACE_HPP_

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
  DuckInterface() : DuckInterface(std::shared_ptr<FlyBehavior>(),
                                  std::shared_ptr<QuackBehavior>()) {
      /* some common duck staff */
  }

  /**
   * @brief Destroys the DuckInterface object.
   *
   * This destructor is defined as pure virtual, making the class abstract and
   * preventing instances of it from being created. It is also defined as default,
   * allowing derived classes to clean up their own resources as needed.
   */
  virtual ~DuckInterface() = 0;

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
  void PerformFly()  { fly_behavior_->Fly(); }

  /**
   * @brief Performs the duck's swim behavior.
   *
   * This method is common to all ducks and is implemented here to provide
   * a default behavior for swimming.
   */
  void PerformSwim()  { std::cout << "All ducks can swim" << std::endl; }

  /**
   * @brief Sets the duck's Fly behavior dynamically.
   *
   * This method takes a shared_ptr to a FlyBehavior object, which encapsulates
   * a specific Fly behavior algorithm. The current FlyBehavior object is
   * replaced with the new one, allowing the duck's Fly behavior to be changed
   * dynamically at runtime.
   * @param behavior The new FlyBehavior object to use.
   */
  void SetFlyBehavior(const std::shared_ptr<FlyBehavior> &behavior)  {
      fly_behavior_ = behavior;
  }

  /**
   * @brief Sets the duck's Quack behavior dynamically.
   *
   * This method takes a shared_ptr to a QuackBehavior object, which
   * encapsulates a specific Quack behavior algorithm. The current
   * QuackBehavior object is replaced with the new one, allowing the
   * duck's Quack behavior to be changed dynamically at runtime.
   * @param behavior The new QuackBehavior object to use.
   */
  void SetQuackBehavior(const std::shared_ptr<QuackBehavior> &behavior){
      quack_behavior_ = behavior;
  }

  /**
   * @brief Copy assignment operator.
   *
   * This method is declared as default, allowing the compiler to generate
   * a default copy assignment operator.
   * @param copy The object to copy.
   * @return A reference to this DuckInterface object.
   */

  DuckInterface &operator=(const DuckInterface &copy) = default;
  /**
   * @brief Overloaded move assignment operator.
   * This default move assignment operator is provided to allow derived classes
   * to move the state of one DuckInterface object to another.
   * @param copy The DuckInterface object to move.
   * @return A reference to this DuckInterface object.
   */
  DuckInterface &operator=(DuckInterface &&) = default;
 protected:
  /**
   * @brief Constructs a new DuckInterface object.
   *
   * This constructor initializes any common duck properties or behaviors.
   * @param fly The fly behavior of the duck.
   * @param quack The quack behavior of the duck.
   */
  DuckInterface(const std::shared_ptr<FlyBehavior> &fly,
                const std::shared_ptr<QuackBehavior> &quack)
      : fly_behavior_(fly), quack_behavior_(quack) {}
  /**
   * @brief Copy constructor.
   *
   * This default copy constructor is provided to allow derived classes to
   * copy the state of one DuckInterface object to another.
   * @param copy The DuckInterface object to copy.
   */
  DuckInterface(const DuckInterface &copy) = default;
  /**
   * @brief Move constructor.
   *
   * This move constructor initializes any common duck properties or behaviors.
   * @param copy The DuckInterface object to move.
   */
  DuckInterface(DuckInterface &&copy) noexcept
      : fly_behavior_(std::move(copy.fly_behavior_)),
        quack_behavior_(std::move(copy.quack_behavior_)) { }
 private:
  // Alternatively, we could have used a raw pointer like FlyBehavior *ptr,
  // but that could lead to issues such as memory leaks or dangling pointers
  // if the pointer is deleted somewhere else.
  // Using std::shared_ptr avoids these potential problems.
  std::shared_ptr<FlyBehavior> fly_behavior_;
  std::shared_ptr<QuackBehavior> quack_behavior_;
};

inline DuckInterface::~DuckInterface() {}

#endif // STRATEGY_PATTERN_SIMUDUCK_DUCKS_INTERFACE_HPP_