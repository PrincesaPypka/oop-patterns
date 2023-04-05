#include "weatherData/data.hpp"
#include "display/currentCondition.hpp"

int main() {
    auto data1 = std::make_shared<WeatherData>();
    auto device1 = CurrentConditionDevice::CurrentConnectionDevicePtr(data1);
    auto device2 = CurrentConditionDevice::CurrentConnectionDevicePtr(data1);
    {
        auto data2 = std::make_shared<WeatherData>(10, 10);
        device1->ConnectToAnotherDataSource(data2);
        data2->SetAllData(2, 4, 6);
    }
    auto data2 = device1->GetWeatherData();
    data1->SetAllData(5, 5, 5);
    device1->Display();
    device2->Display();
    data2->SetAllData(5, 6, 7);
    device1->Display();
    return 0;
}