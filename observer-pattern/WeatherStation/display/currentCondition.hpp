#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_CURRENTCONDITION_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_CURRENTCONDITION_HPP_

#include <iostream>
#include <utility>

#include "interface.hpp"
#include "weatherData/data.hpp"

class CurrentConditionDisplay : public DisplayInterface {
 public:
  using Shared = std::shared_ptr<CurrentConditionDisplay>;

  static Shared CurrentConnectionDevicePtr(const WeatherData::Shared &);
  static Shared CurrentConditionDevicePtr(const Shared &);
  static Shared CurrentConditionDevicePtr(Shared &&);

  ~CurrentConditionDisplay() {
      weather_data_->RemoveDisplay(shared_from_this());
  }

  void ConnectToAnotherDataSource(WeatherData::Shared new_wd);

  void Display() const override {
      std::cout << "t: " << temperature_ << "h:" << humidity_ << std::endl;
  }

  WeatherData::Shared GetWeatherData() const { return weather_data_; }

 protected:
  explicit CurrentConditionDisplay(WeatherData::Shared weather_data)
      : weather_data_(std::move(weather_data)) {}

  explicit CurrentConditionDisplay(const Shared &copy) :
      temperature_(copy->temperature_),
      humidity_(copy->humidity_),
      weather_data_(copy->weather_data_) {}

  explicit CurrentConditionDisplay(Shared &&copy) :
      temperature_(copy->temperature_),
      humidity_(copy->humidity_),
      weather_data_(std::move(copy->weather_data_)) {}

 private:
  double temperature_ = 0;
  double humidity_ = 0;
  WeatherData::Shared weather_data_;

  void Update() override;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_CURRENTCONDITION_HPP_
