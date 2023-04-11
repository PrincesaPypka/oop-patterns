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
std::ostream &operator<<(std::ostream &out,
                         const PizzaInterface::PizzaInterfacePtr &pizza) {
    out << "---" << pizza->name_ << "---" << std::endl
        << pizza->dough_ << std::endl << pizza->sauce_ << std::endl;
    for (const auto &kTopping : pizza->toppings_)
        out << kTopping << std::endl;
    return out;
}

PizzaInterface::~PizzaInterface() = default;
