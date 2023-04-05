project(observer-pattern-0.2)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

set(GLOB DEVICES "WeatherStation1/display")

add_executable(WeatherStationExe WeatherStation1/weatherData.hpp WeatherStation1/tmp.cpp ${DEVICES})
target_include_directories(WeatherStationExe PRIVATE WeatherStation1)
#target_link_directories(WeatherStationExe PRIVATE WeatherStation1)