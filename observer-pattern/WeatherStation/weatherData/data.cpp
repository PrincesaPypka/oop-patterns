#include "data.hpp"

void WeatherData::RemoveDisplay(const std::shared_ptr<DeviceInterface> &device) {
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

void WeatherData::AddDisplay(const std::shared_ptr<DeviceInterface> &device) {
    connected_devises_.push_back(device);
}

void WeatherData::NotifyDisplay() {
    for (const auto &device : connected_devises_)
        if (device)
            device->Update();
}

void WeatherData::SetTemperature(double temperature) {
    temperature_ = temperature;
    NotifyDisplay();
}

void WeatherData::SetHumidity(double humidity) {
    humidity_ = humidity;
    NotifyDisplay();
}

void WeatherData::SetPressure(double pressure) {
    pressure_ = pressure;
    NotifyDisplay();
}

void WeatherData::SetAllData(double temperature,
                             double humidity,
                             double pressure) {
    temperature_ = temperature;
    humidity_ = humidity;
    pressure_ = pressure;
    NotifyDisplay();
}

WeatherData &WeatherData::operator=(const WeatherData &new_wd) {
    temperature_ = new_wd.temperature_;
    humidity_ = new_wd.humidity_;
    pressure_ = new_wd.pressure_;
    return *this;
}

WeatherData &WeatherData::operator=(WeatherData &&new_wd) noexcept {
    temperature_ = new_wd.temperature_;
    humidity_ = new_wd.humidity_;
    pressure_ = new_wd.pressure_;
    return *this;
}
