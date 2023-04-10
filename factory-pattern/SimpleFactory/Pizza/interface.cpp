#include "interface.hpp"

std::stringstream PizzaInterface::Prepare() const {
    std::stringstream ss;
    ss << "Preparing " << name_ << "..." << std::endl;
    return ss;
}

std::stringstream PizzaInterface::Bake() const {
    std::stringstream ss;
    ss << "Baking " << name_ << "..." << std::endl;
    return ss;
}

std::stringstream PizzaInterface::Cut() const {
    std::stringstream ss;
    ss << "Cutting " << name_ << "..." << std::endl;
    return ss;
}

std::stringstream PizzaInterface::Box() const {
    std::stringstream ss;
    ss << "Boxing " << name_ << "..." << std::endl;
    return ss;
}

std::stringstream &PizzaInterface::operator<<(std::stringstream &ss) const {
    ss << "---" << name_ << "---" << std::endl
       << dough_ << std::endl << sauce_ << std::endl;
    for (const auto &kTopping : toppings_)
        ss << kTopping << std::endl;
    return ss;
}

PizzaInterface::~PizzaInterface() {}
