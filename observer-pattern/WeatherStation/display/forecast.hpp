#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_FORECAST_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_FORECAST_HPP_

#include <iostream>

#include "interface.hpp"

class ForecastDisplay : public DisplayInterface {
 public:
  /// @brief A shared pointer to ForecastDisplay.
  using Shared = std::shared_ptr<ForecastDisplay>;
  /**
    * @brief Creates a shared pointer to a ForecastDisplay object with
    * the specified weather data.
    * @param weather_data The weather data to be associated with
    * the ForecastDisplay.
    * @return A shared pointer to the newly created ForecastDisplay object.
    * */
  static Shared ForecastDisplayPtr(const WeatherData::Shared &);
  /**
    * @brief Creates a shared pointer to a ForecastDisplay object with
    * the specified ForecastDisplay.
    * @param copy A shared pointer to the ForecastDisplay to be copied.
    * @return A shared pointer to the newly created ForecastDisplay object.
    * */
  static Shared ForecastDisplayPtr(const Shared &);
  /**
    * @brief Creates a shared pointer to a ForecastDisplay object with
    * the specified ForecastDisplay.
    * The ownership of the ForecastDisplay is transferred to the
    * newly created shared pointer.
    * @param copy A rvalue reference to the ForecastDisplay to be copied.
    * @return A shared pointer to the newly created ForecastDisplay object.
    * */
  static Shared ForecastDisplayPtr(Shared &&);
  /// @brief Destroys the ForecastDisplay object and removes it from the
  /// associated WeatherData object.
  ~ForecastDisplay() { weather_data_->RemoveDisplay(shared_from_this()); }
  /**
    * @brief Connects the ForecastDisplay to another WeatherData object.
    * @param weather_data The WeatherData object to be associated with
    * the ForecastDisplay.
    * */
  void ConnectToAnotherDataSource(const WeatherData::Shared &);
  /// @brief Displays the forecast based on the current and previous
  /// pressure readings.
  void Display() const override;

 protected:
  /**
    * @brief Constructs a ForecastDisplay object with the specified WeatherData object.
    * @param weather_data The WeatherData object to be associated with the ForecastDisplay.
    * */
  explicit ForecastDisplay(const WeatherData::Shared &weather_data) :
      DisplayInterface(weather_data) {}
  /**
    * @brief Constructs a ForecastDisplay object by copying another ForecastDisplay object.
    * @param copy The ForecastDisplay object to be copied.
    * */
  explicit ForecastDisplay(const Shared &copy) :
      DisplayInterface(copy->weather_data_),
      current_pressure_(copy->current_pressure_),
      previous_pressure_(copy->previous_pressure_) {}
  /**
    * @brief Constructs a ForecastDisplay object by moving another
    * ForecastDisplay object.
    * The ownership of the WeatherData object is transferred to the newly
    * created object.
    * @param copy The ForecastDisplay object to be moved.
    * */
  explicit ForecastDisplay(Shared &&copy) :
      DisplayInterface(copy->weather_data_),
      current_pressure_(copy->current_pressure_),
      previous_pressure_(copy->previous_pressure_) {}

 private:
  double current_pressure_ = 0;
  double previous_pressure_ = -1;
  /// @brief Updates the current and previous pressure readings.
  void Update() override;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_FORECAST_HPP_
