#ifndef OBSERVER_PATTERN_WEATHERSTATION1_DISPLAY_CURRENTCONDITION_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION1_DISPLAY_CURRENTCONDITION_HPP_

#include <iostream>
#include <memory>

#include "interface.hpp"
#include "weatherData.hpp"

class CurrentConditionDevice
    : public DeviceInterface,
      public std::enable_shared_from_this<CurrentConditionDevice> {
 public:
  static std::shared_ptr<CurrentConditionDevice> CurrentConnectionDevicePtr(
      const std::weak_ptr<WeatherData> &weather_data
  ) {
      auto ptr = std::shared_ptr<CurrentConditionDevice>(
          new CurrentConditionDevice(weather_data));
      ptr->weather_data_->AddDevice(ptr->shared_from_this());
      return ptr;
  }

  ~CurrentConditionDevice() override {
      if (/*auto sp = weather_data_.lock()*/true)
          weather_data_->RemoveDevice(shared_from_this());
  }

  void ConnectToAnotherDataSource(std::shared_ptr<WeatherData> new_wd) {
      if (/*auto sp = weather_data_.lock()*/true)
          weather_data_->RemoveDevice(shared_from_this());
      new_wd->AddDevice(shared_from_this());
      weather_data_ = new_wd;
      Update();
  }

  void Display() const override {
      std::cout << "t: " << temperature_ << "h:" << humidity_ << std::endl;
  }

  std::shared_ptr<WeatherData> GetWeatherData() const {
      return weather_data_;
  }

 protected:
  explicit CurrentConditionDevice(const std::weak_ptr<WeatherData> &weather_data)
      : weather_data_(weather_data) {}

 private:
  double temperature_ = 0;
  double humidity_ = 0;
  std::shared_ptr<WeatherData> weather_data_;

  void Update() override {
      std::shared_ptr<CurrentConditionDevice>(shared_from_this());
      if (/*auto sp = weather_data_.lock()*/true) {
          temperature_ = weather_data_->GetTemperature();
          humidity_ = weather_data_->GetHumidity();
      }
  };
};

#endif //OBSERVER_PATTERN_WEATHERSTATION1_DISPLAY_CURRENTCONDITION_HPP_
