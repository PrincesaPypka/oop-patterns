#include "currentCondition.hpp"

CurrentConditionDisplay::Shared CurrentConditionDisplay::CurrentConnectionDevicePtr(
    const WeatherData::Shared &weather_data) {
    // make_shared<CurrentConditionDisplay>(weather_data) is not available
    // since the constructor CurrentConditionDisplay is protected. Using
    // make_shared<CurrentConditionDisplay>(CurrentConditionDisplay(weather_data))
    // throws a bad_weak_ptr exception since we are trying to create
    // a shared pointer from a temporary object.
    auto ptr = std::shared_ptr<CurrentConditionDisplay>(
        new CurrentConditionDisplay(weather_data));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    return ptr;
}

CurrentConditionDisplay::Shared CurrentConditionDisplay::CurrentConditionDevicePtr(
    const CurrentConditionDisplay::Shared &copy) {
    copy->weather_data_->RemoveDisplay(copy->shared_from_this());
    auto ptr = std::shared_ptr<CurrentConditionDisplay>(
        new CurrentConditionDisplay(copy));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    return ptr;
}

CurrentConditionDisplay::Shared CurrentConditionDisplay::CurrentConditionDevicePtr(
    CurrentConditionDisplay::Shared &&copy) {
    copy->weather_data_->RemoveDisplay(copy->shared_from_this());
    auto ptr = std::shared_ptr<CurrentConditionDisplay>(
        new CurrentConditionDisplay(copy));
    ptr->weather_data_->AddDisplay(ptr->shared_from_this());
    return ptr;
}

void CurrentConditionDisplay::ConnectToAnotherDataSource(WeatherData::Shared new_wd) {
    weather_data_->RemoveDisplay(shared_from_this());
    new_wd->AddDisplay(shared_from_this());
    weather_data_ = new_wd;
    Update();
}

void CurrentConditionDisplay::Update() {
    temperature_ = weather_data_->GetTemperature();
    humidity_ = weather_data_->GetHumidity();
}
