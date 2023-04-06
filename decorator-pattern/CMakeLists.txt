project(decorator-pattern)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

file(GLOB BEVERAGE_HEADERS "StarbuzzCofe/beverage/*.hpp")
file(GLOB BEVERAGE_SOURCES "StarbuzzCofe/beverage/*.cpp")
file(GLOB CONDIMENT_HEADERS "StarbuzzCofe/condiment/*.hpp")
file(GLOB CONDIMENT_SOURCES "StarbuzzCofe/condiment/*.cpp")

#example 1
add_executable(StarbuzzCofeExe
        StarbuzzCofe/main.cpp
        ${BEVERAGE_HEADERS}
        ${BEVERAGE_SOURCES}
        ${CONDIMENT_HEADERS}
        ${CONDIMENT_SOURCES})
target_include_directories(StarbuzzCofeExe
        PRIVATE
        StarbuzzCofe
        beverage
        condiment)
