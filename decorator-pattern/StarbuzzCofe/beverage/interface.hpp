#ifndef DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_INTERFACE_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_INTERFACE_HPP_

#include <string>
#include <utility>
#include <iostream>

/**
  * @class BeverageInterface
  * @brief The abstract base class for all beverage classes
  * @details BeverageInterface provides a common interface for all the
  * beverages that will be served.
  * */
class BeverageInterface {
 public:
  /**
    * @brief Get the description of the beverage
    * @return const std::string& The description of the beverage
    * */
  [[nodiscard]] virtual const std::string &GetDescription() const {
      return description_;
  }
  /**
    * @brief Get the cost of the beverage
    * @return double The cost of the beverage
    * */
  [[nodiscard]] virtual double Cost() const = 0;
  /// @brief Virtual destructor
  virtual ~BeverageInterface() = 0;
 protected:
  /**
    * @brief Constructor for BeverageInterface class
    * @param description The description of the beverage
    * */
  explicit BeverageInterface(std::string description = "Unknown Beverage") :
      description_(std::move(description)) {}
  std::string description_;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_INTERFACE_HPP_
