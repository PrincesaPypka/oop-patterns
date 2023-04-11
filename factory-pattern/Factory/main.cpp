#include "PizzaStore/nyPizzaStore.hpp"
#include "PizzaStore/chicagoPizzaStore.hpp"

int main() {
    auto store = std::shared_ptr<PizzaStoreInterface>(new NYPizzaStore());
    auto pizza = store->OrderPizza(NYPizzaStore::PizzaType::VEGGIE);
    std::cout << pizza << std::endl << std::endl;
    store = std::shared_ptr<PizzaStoreInterface>(new ChicagoPizzaStore());
    pizza = store->OrderPizza(ChicagoPizzaStore::PizzaType::CHEESE);
    std::cout << pizza << std::endl << std::endl;

    return 0;
}
