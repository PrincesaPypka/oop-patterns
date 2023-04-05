project(observer-pattern-0.2)

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

file(GLOB DEVICES "WeatherStation/display")
file(GLOB WEATHER_DATA_HEADERS "WeatherStation/weatherData/*.hpp")
file(GLOB WEATHER_DATA_SOURCES "WeatherStation/weatherData/*.cpp")

#example 1
add_executable(WeatherStationExe
        WeatherStation/tmp.cpp
        ${DEVICES}
        ${WEATHER_DATA_HEADERS}
        ${WEATHER_DATA_SOURCES})
target_include_directories(WeatherStationExe PRIVATE WeatherStation)
