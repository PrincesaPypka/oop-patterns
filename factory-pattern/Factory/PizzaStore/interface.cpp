#include "interface.hpp"

PizzaStoreInterface::PizzaInterfacePtr PizzaStoreInterface::OrderPizza(
    PizzaStoreInterface::PizzaType type) {
    auto pizza = CreatePizza(type);
    std::cout << pizza->Prepare().str()
              << pizza->Bake().str();
    std::cout << pizza->Cut().str()
              << pizza->Box().str();

    return pizza;
}

PizzaStoreInterface::~PizzaStoreInterface() = default;
