#include "pizzaStore.hpp"

int main() {
    auto factory = std::make_unique<SimplePizzaFactory>();
    PizzaStore store(factory);
    auto pizza = store.OrderPizza(SimplePizzaFactory::PizzaType::CHEESE);
    std::cout << "We ordered " << pizza->GetName() << std::endl << std::endl;
    std::cout << pizza;
    pizza = store.OrderPizza(SimplePizzaFactory::PizzaType::VEGGIE);
    std::cout << "We ordered " << pizza->GetName() << std::endl;

    return 0;
}
