#ifndef OBSERVER_PATTERN_WEATHERSTATION1_DISPLAY_INTERFACE_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION1_DISPLAY_INTERFACE_HPP_

#include "weatherData.hpp"

class DeviceInterface {
 public:
  virtual ~DeviceInterface() = 0;
  virtual void Update() = 0;
  virtual void Display() const = 0;
 private:
  friend class WeatherData;
};

DeviceInterface::~DeviceInterface() {}
#endif //OBSERVER_PATTERN_WEATHERSTATION1_DISPLAY_INTERFACE_HPP_
