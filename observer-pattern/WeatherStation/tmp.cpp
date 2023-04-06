#include "display/currentCondition.hpp"
#include "display/statistic.hpp"
#include "display/forecast.hpp"

int main() {
    auto data1 = std::make_shared<WeatherData>();
    auto device1 = CurrentConditionDisplay::CurrentConnectionDevicePtr(data1);
    auto device2 = CurrentConditionDisplay::CurrentConnectionDevicePtr(data1);
    auto device3 = StatisticDisplay::StatisticDisplayPtr(data1);
    auto device4 = ForecastDisplay::ForecastDisplayPtr(data1);
    {
        auto data2 = std::make_shared<WeatherData>(10, 10);
        device1->ConnectToAnotherDataSource(data2);
        data2->SetAllData(2, 4, 6);
    }
    auto data2 = device1->GetWeatherData();
    device3->Display();
    device4->Display();
    data1->SetAllData(5, 5, 5);
    device1->Display();
    device2->Display();
    data2->SetAllData(5, 6, 7);
    data1->SetAllData(-10, 5, 9);
    device1->Display();
    device3->Display();
    device4->Display();
    return 0;
}