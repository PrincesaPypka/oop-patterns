#ifndef DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_DECORATOR_HPP_
#define DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_DECORATOR_HPP_

#include "beverage/interface.hpp"

/**
  * @class CondimentDecorator
  * @brief The abstract base class for all condiment decorator classes
  * @details CondimentDecorator is an abstract base class that provides a
  * common interface for all the condiment decorators that will be used to
  * decorate a beverage.
  * */
class CondimentDecorator : public BeverageInterface {
 public:
  /**
    * @brief Get the cost of the decorated beverage
    * @return double The cost of the decorated beverage
    * */
  [[nodiscard]] double Cost() const override = 0;
  ~CondimentDecorator() override = 0;

 protected:
  /**
    * @brief Constructor for CondimentDecorator class
    * @param beverage A pointer to the BeverageInterface object to be decorated
    * */
  explicit CondimentDecorator(BeverageInterface *beverage) :
      beverage_(beverage) {
      std::cout << "CondimentDecor " << this <<
                " beverage " << beverage << std::endl;
  }
  BeverageInterface *beverage_;
};

#endif //DECORATOR_PATTERN_STARBUZZCOFE_CONDIMENT_DECORATOR_HPP_
