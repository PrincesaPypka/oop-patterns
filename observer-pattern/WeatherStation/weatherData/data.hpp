#ifndef OBSERVER_PATTERN_WEATHERSTATION_WEATHERDATA_DATA_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_WEATHERDATA_DATA_HPP_

#include <vector>
#include "display/interface.hpp"

class WeatherData {
 public:
  using Shared = std::shared_ptr<WeatherData>;
  explicit WeatherData(double temperature = 0,
                       double humidity = 0,
                       double pressure = 0)
      : temperature_(temperature), humidity_(humidity), pressure_(pressure) {}

  WeatherData(const WeatherData &s) = default;
  WeatherData(WeatherData &&s) noexcept:
      temperature_(s.temperature_),
      humidity_(s.humidity_),
      pressure_(s.pressure_),
      connected_displays_(std::move(s.connected_displays_)) {}

  void AddDisplay(const std::shared_ptr<DisplayInterface> &device);
  void RemoveDisplay(const std::shared_ptr<DisplayInterface> &device);
  void NotifyDisplay();

  [[nodiscard]] double GetTemperature() const { return temperature_; }
  [[nodiscard]] double GetHumidity() const { return humidity_; }
  [[nodiscard]] double GetPressure() const { return pressure_; }

  void SetTemperature(double temperature);
  void SetHumidity(double humidity);
  void SetPressure(double pressure);
  void SetAllData(double temperature, double humidity, double pressure);

  WeatherData &operator=(const WeatherData &new_wd);
  WeatherData &operator=(WeatherData &&new_wd) noexcept;

 private:
  double temperature_;
  double humidity_;
  double pressure_;
  std::vector<std::shared_ptr<DisplayInterface>> connected_displays_ = {};
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_WEATHERDATA_DATA_HPP_
