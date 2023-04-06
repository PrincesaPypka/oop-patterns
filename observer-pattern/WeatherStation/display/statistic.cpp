#include "statistic.hpp"

void StatisticDisplay::Display() const {
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(3);
    std::cout << "Avg/Max/Min temperature = "
              << (measure_count_ ? sum_temperature_ / measure_count_ : 0)
              << "/" << max_temperature_ << "/" << min_temperature_
              << std::endl;
}

StatisticDisplay::Shared StatisticDisplay::StaticDisplayPtr(
    const WeatherData::Shared &weather_data) {
    auto ptr = std::shared_ptr<StatisticDisplay>(
        new StatisticDisplay(weather_data));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    return ptr;
}

StatisticDisplay::Shared StatisticDisplay::StaticDisplayPtr(
    const StatisticDisplay::Shared &copy) {
    copy->weather_data_->RemoveDisplay(copy->shared_from_this());
    auto ptr = std::shared_ptr<StatisticDisplay>(
        new StatisticDisplay(copy));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    return ptr;
}

StatisticDisplay::Shared StatisticDisplay::StaticDisplayPtr(
    StatisticDisplay::Shared &&copy) {
    copy->weather_data_->RemoveDisplay(copy->shared_from_this());
    auto ptr = std::shared_ptr<StatisticDisplay>(
        new StatisticDisplay(copy));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    return ptr;
}

void StatisticDisplay::ConnectToAnotherDataSource(
    const WeatherData::Shared &new_wd) {
    weather_data_->RemoveDisplay(shared_from_this());
    new_wd->AddDisplay(shared_from_this());
    weather_data_ = new_wd;
}

void StatisticDisplay::Update() {
    ++measure_count_;
    double temperature = weather_data_->GetTemperature();
    sum_temperature_ += temperature;
    if (temperature > max_temperature_)
        max_temperature_ = temperature;
    else if (temperature < min_temperature_)
        min_temperature_ = temperature;
}





