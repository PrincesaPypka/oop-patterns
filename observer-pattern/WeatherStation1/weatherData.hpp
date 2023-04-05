#ifndef OBSERVER_PATTERN_WEATHERSTATION1_WEATHERDATA_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION1_WEATHERDATA_HPP_

#include <vector>
#include "display/interface.hpp"

class WeatherData {
 public:
  explicit WeatherData(double temperature = 0,
                       double humidity = 0,
                       double pressure = 0)
      : temperature_(temperature), humidity_(humidity), pressure_(pressure) {}

  WeatherData(const WeatherData &s) = default;
  WeatherData(WeatherData &&s) noexcept:
      temperature_(s.temperature_),
      humidity_(s.humidity_),
      pressure_(s.pressure_),
      connected_devises_(std::move(s.connected_devises_)) {}

  void AddDevice(const std::shared_ptr<DeviceInterface> &device) {
      connected_devises_.push_back(device);
  }

  void RemoveDevice(const std::shared_ptr<DeviceInterface> &device) {
      auto ptr = device.get();
      long pos = -1;
      for (auto i = 0; i < connected_devises_.size(); ++i)
          if (ptr == connected_devises_[i].get()) {
              pos = i;
              break;
          }
      if (pos != -1)
          connected_devises_.erase(connected_devises_.cbegin() + pos);
  }

  void NotifyDevices() {
      for (const auto &device : connected_devises_) device->Update();
  }

  [[nodiscard]] double GetTemperature() const { return temperature_; }
  [[nodiscard]] double GetHumidity() const { return humidity_; }
  [[nodiscard]] double GetPressure() const { return pressure_; }

  void SetTemperature(double temperature) {
      temperature_ = temperature;
      NotifyDevices();
  }
  void SetHumidity(double humidity) {
      humidity_ = humidity;
      NotifyDevices();
  }
  void SetPressure(double pressure) {
      pressure_ = pressure;
      NotifyDevices();
  }

  void SetAllData(double temperature, double humidity, double pressure) {
      temperature_ = temperature;
      humidity_ = humidity;
      pressure_ = pressure;
      NotifyDevices();
  }

  WeatherData &operator=(const WeatherData &new_wd) {
      temperature_ = new_wd.temperature_;
      humidity_ = new_wd.humidity_;
      pressure_ = new_wd.pressure_;
      return *this;
  }

  WeatherData &operator=(WeatherData &&new_wd) noexcept {
      temperature_ = new_wd.temperature_;
      humidity_ = new_wd.humidity_;
      pressure_ = new_wd.pressure_;
      return *this;
  }

 private:
  double temperature_;
  double humidity_;
  double pressure_;
  std::vector<std::shared_ptr<DeviceInterface>> connected_devises_ = {};
};

#endif //OBSERVER_PATTERN_WEATHERSTATION1_WEATHERDATA_HPP_
