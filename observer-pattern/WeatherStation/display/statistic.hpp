#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_STATISTIC_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_STATISTIC_HPP_

#include <iostream>

#include "interface.hpp"
// TODO write documentation
class StatisticDisplay : public DisplayInterface {
 public:
  using Shared = std::shared_ptr<StatisticDisplay>;

  static Shared StatisticDisplayPtr(const WeatherData::Shared &);
  static Shared StatisticDisplayPtr(const Shared &);
  static Shared StatisticDisplayPtr(Shared &&);

  ~StatisticDisplay() { weather_data_->RemoveDisplay(shared_from_this()); }

  void ConnectToAnotherDataSource(const WeatherData::Shared &);
  void Display() const override;

 protected:
  explicit StatisticDisplay(const WeatherData::Shared &weather_data) :
      DisplayInterface(weather_data) {}

  explicit StatisticDisplay(const Shared &copy) :
      DisplayInterface(copy->weather_data_),
      min_temperature_(copy->min_temperature_),
      max_temperature_(copy->max_temperature_),
      sum_temperature_(copy->sum_temperature_),
      measure_count_(copy->measure_count_) {}

  explicit StatisticDisplay(Shared &&copy) :
      DisplayInterface(copy->weather_data_),
      min_temperature_(copy->min_temperature_),
      max_temperature_(copy->max_temperature_),
      sum_temperature_(copy->sum_temperature_),
      measure_count_(copy->measure_count_) {}

 private:
  double min_temperature_ = 0;
  double max_temperature_ = 0;
  double sum_temperature_ = 0;
  unsigned measure_count_ = 0;

  void Update() override;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_STATISTIC_HPP_
