#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_

#include <memory>
#include "weatherData/data.hpp"

class DisplayInterface :
    public std::enable_shared_from_this<DisplayInterface> {
 public:
  using Shared = std::shared_ptr<DisplayInterface>;
  virtual void Update() = 0;
  virtual void Display() const = 0;
 protected:
  explicit DisplayInterface(WeatherData::Shared weather_data) :
      weather_data_(std::move(weather_data)) {}

  WeatherData::Shared weather_data_;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_
