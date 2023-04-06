#include "forecast.hpp"

void ForecastDisplay::Display() const {
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(3);
    std::cout << "Forecast: ";
    if (current_pressure_ > previous_pressure_)
        std::cout << "Improving weather on the way!";
    else if (current_pressure_ == previous_pressure_)
        std::cout << "More of the same";
    else if (current_pressure_ < previous_pressure_)
        std::cout << "Watch out for cooler, rainy weather";
    std::cout << std::endl;
}

ForecastDisplay::Shared ForecastDisplay::ForecastDisplayPtr(
    const WeatherData::Shared &weather_data) {
    auto ptr = std::shared_ptr<ForecastDisplay>(
        new ForecastDisplay(weather_data));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    ptr->Update();
    return ptr;
}

ForecastDisplay::Shared ForecastDisplay::ForecastDisplayPtr(
    const ForecastDisplay::Shared &copy) {
    copy->weather_data_->RemoveDisplay(copy->shared_from_this());
    auto ptr = std::shared_ptr<ForecastDisplay>(
        new ForecastDisplay(copy));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    ptr->Update();
    return ptr;
}

ForecastDisplay::Shared ForecastDisplay::ForecastDisplayPtr(
    ForecastDisplay::Shared &&copy) {
    copy->weather_data_->RemoveDisplay(copy->shared_from_this());
    auto ptr = std::shared_ptr<ForecastDisplay>(
        new ForecastDisplay(copy));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    ptr->Update();
    return ptr;
}

void ForecastDisplay::ConnectToAnotherDataSource(
    const WeatherData::Shared &new_wd) {
    weather_data_->RemoveDisplay(shared_from_this());
    new_wd->AddDisplay(shared_from_this());
    weather_data_ = new_wd;
}

void ForecastDisplay::Update() {
    previous_pressure_ = current_pressure_;
    current_pressure_ = weather_data_->GetPressure();
}





