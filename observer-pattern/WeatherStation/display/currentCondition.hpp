#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_CURRENTCONDITION_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_CURRENTCONDITION_HPP_

#include <iostream>

#include "interface.hpp"
// TODO write documentation
class CurrentConditionDisplay : public DisplayInterface {
 public:
  using Shared = std::shared_ptr<CurrentConditionDisplay>;

  static Shared CurrentConnectionDevicePtr(const WeatherData::Shared &);
  static Shared CurrentConditionDevicePtr(const Shared &);
  static Shared CurrentConditionDevicePtr(Shared &&);

  ~CurrentConditionDisplay() {
      weather_data_->RemoveDisplay(shared_from_this());
  }

  void ConnectToAnotherDataSource(const WeatherData::Shared &);

  void Display() const override {
      std::cout << "t: " << temperature_ << "h:" << humidity_ << std::endl;
  }

  WeatherData::Shared GetWeatherData() const { return weather_data_; }

 protected:
  explicit CurrentConditionDisplay(const WeatherData::Shared &weather_data)
      : DisplayInterface(weather_data) {}

  explicit CurrentConditionDisplay(const Shared &copy) :
      DisplayInterface(copy->weather_data_),
      temperature_(copy->temperature_),
      humidity_(copy->humidity_) {}

  explicit CurrentConditionDisplay(Shared &&copy) :
      DisplayInterface(copy->weather_data_),
      temperature_(copy->temperature_),
      humidity_(copy->humidity_) {}

 private:
  double temperature_ = 0;
  double humidity_ = 0;

  void Update() override;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_CURRENTCONDITION_HPP_
