#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_FORECAST_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_FORECAST_HPP_

#include <iostream>

#include "interface.hpp"

class ForecastDisplay : public DisplayInterface {
 public:
  using Shared = std::shared_ptr<ForecastDisplay>;

  static Shared ForecastDisplayPtr(const WeatherData::Shared &);
  static Shared ForecastDisplayPtr(const Shared &);
  static Shared ForecastDisplayPtr(Shared &&);

  ~ForecastDisplay() { weather_data_->RemoveDisplay(shared_from_this()); }

  void ConnectToAnotherDataSource(const WeatherData::Shared &);
  void Display() const override;

 protected:
  explicit ForecastDisplay(const WeatherData::Shared &weather_data) :
      DisplayInterface(weather_data) {}

  explicit ForecastDisplay(const Shared &copy) :
      DisplayInterface(copy->weather_data_),
      current_pressure_(copy->current_pressure_),
      previous_pressure_(copy->previous_pressure_) {}

  explicit ForecastDisplay(Shared &&copy) :
      DisplayInterface(copy->weather_data_),
      current_pressure_(copy->current_pressure_),
      previous_pressure_(copy->previous_pressure_) {}

 private:
  double current_pressure_ = 0;
  double previous_pressure_ = -1;

  void Update() override;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_FORECAST_HPP_
