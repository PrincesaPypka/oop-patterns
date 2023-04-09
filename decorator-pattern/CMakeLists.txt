project(decorator-pattern)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

#flags for memory leak detection (for LLVM)
#note that some wierd error messages appears, just ignore them or
#suppress as described here:
#https://github.com/google/sanitizers/issues/1501
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=leak -g")

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
