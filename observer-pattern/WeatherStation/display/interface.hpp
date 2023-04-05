#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_

#include "weatherData/data.hpp"

class DeviceInterface {
 public:
  virtual void Update() = 0;
  virtual void Display() const = 0;
 private:
  friend class WeatherData;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_
