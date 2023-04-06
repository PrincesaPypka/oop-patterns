#ifndef DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_INTERFACE_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_INTERFACE_HPP_

#include <string>
#include <utility>

class BeverageInterface {
 public:
  [[nodiscard]] virtual const std::string &GetDescription() const {
      return description_;
  }
  [[nodiscard]] virtual double Cost() const = 0;
  virtual ~BeverageInterface() = 0;
 protected:
  explicit BeverageInterface(std::string description = "Unknown Beverage") :
      description_(std::move(description)) {}
  std::string description_;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_BEVERAGE_INTERFACE_HPP_
