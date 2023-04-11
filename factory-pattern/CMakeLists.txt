project(strategy-pattern)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

# example 1 - simple factory pattern (not really)
file(GLOB PIZZAS_SOURCE "SimpleFactory/Pizza/*.cpp")
file(GLOB PIZZAS_HEADER "SimpleFactory/Pizza/*.hpp")
set(PIZZAS ${PIZZAS_HEADER} ${PIZZAS_SOURCE})
set(FACTORY SimpleFactory/simplePizzaFactory.hpp)
set(PIZZA_STORE SimpleFactory/pizzaStore.hpp)
add_executable(SimpleFactoryExe
        SimpleFactory/main.cpp
        ${PIZZAS}
        ${FACTORY}
        ${PIZZA_STORE}
        )
target_include_directories(SimpleFactoryExe PRIVATE SimpleFactory)

# example 2 - factory pattern
file(GLOB FACTORY_SOURCE "Factory/PizzaStore/*.cpp")
file(GLOB FACTORY_HEADER "Factory/PizzaStore/*.hpp")
set(FACTORY ${FACTORY_HEADER} ${FACTORY_SOURCE})
add_executable(FactoryExe
        Factory/main.cpp
        ${PIZZAS}
        ${FACTORY}
        ${PIZZA_STORE}
        )
target_include_directories(FactoryExe PRIVATE SimpleFactory)