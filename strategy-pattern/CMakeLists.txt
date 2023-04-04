project(strategy-pattern)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

# example 1
set(GLOB FLY_BEHAVIOR "SimUDuck/flyBehavior")
set(GLOB QUACK_BEHAVIOR "SimUDuck/quickBehavior")
set(GLOB DUCKS "SimUDuck/ducks")
add_executable(SimUDuckExe SimUDuck/simUDuck.cpp ${FLY_BEHAVIOR} ${QUACK_BEHAVIOR} ${DUCKS} SimUDuck/ducks/decoy.cpp)
target_include_directories(SimUDuckExe PRIVATE SimUDuck)
