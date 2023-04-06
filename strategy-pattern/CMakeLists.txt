project(strategy-pattern)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

# example 1
file(GLOB FLY_BEHAVIOR "SimUDuck/flyBehavior")
file(GLOB QUACK_BEHAVIOR "SimUDuck/quickBehavior")
file(GLOB DUCKS "SimUDuck/ducks")
add_executable(SimUDuckExe
        SimUDuck/simUDuck.cpp
        ${FLY_BEHAVIOR}
        ${QUACK_BEHAVIOR}
        ${DUCKS})
target_include_directories(SimUDuckExe PRIVATE SimUDuck)
