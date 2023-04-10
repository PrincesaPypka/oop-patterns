project(strategy-pattern)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

# example 1 - simple factory pattern (not really)
file(GLOB PIZZAS "SimpleFactory/Pizza/")
#file(GLOB QUACK_BEHAVIOR "SimUDuck/quickBehavior")
#file(GLOB DUCKS "SimUDuck/ducks")
add_executable(SimpleFactoryExe
        SimpleFactory/main.cpp
        ${PIZZAS}
        #${PIZZA_HEADER}
        #${DUCKS}
        )
target_include_directories(SimpleFactoryExe PRIVATE SimpleFactory)
