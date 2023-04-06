#ifndef OBSERVER_PATTERN_WEATHERSTATION_WEATHERDATA_DATA_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_WEATHERDATA_DATA_HPP_

#include <vector>
#include "display/interface.hpp"

class DisplayInterface;
/**
 * @brief A class representing weather data.
 * This class represents weather data, including
 * temperature, humidity, and pressure.
 * */
class WeatherData {
 public:
  /// @brief Shared pointer to WeatherData.
  using Shared = std::shared_ptr<WeatherData>;
  /**
   * @brief Constructs a WeatherData object with default values.
   * @param temperature The temperature value (default: 0).
   * @param humidity The humidity value (default: 0).
   * @param pressure The pressure value (default: 0).
   * */
  explicit WeatherData(double temperature = 0,
                       double humidity = 0,
                       double pressure = 0)
      : temperature_(temperature), humidity_(humidity), pressure_(pressure) {}
  /**
   * @brief Copy constructor for WeatherData.
   * @param s The WeatherData object to be copied.
   * */
  WeatherData(const WeatherData &s) = default;
  /**
    * @brief Move constructor for WeatherData.
    * @param s The WeatherData object to be moved.
    * */
  WeatherData(WeatherData &&s) noexcept:
      temperature_(s.temperature_),
      humidity_(s.humidity_),
      pressure_(s.pressure_),
      connected_displays_(std::move(s.connected_displays_)) {}
  /**
    * @brief Adds a display to the list of connected displays.
    * @param device A shared pointer to the display to be added.
    * */
  void AddDisplay(const std::shared_ptr<DisplayInterface> &device);
  /**
    * @brief Removes a display from the list of connected displays.
    * @param device A shared pointer to the display to be removed.
    * */
  void RemoveDisplay(const std::shared_ptr<DisplayInterface> &device);
  /// @brief Notifies all connected displays of updated weather data.
  void NotifyDisplay();

  /**
    * @brief Returns the temperature value.
    * @return The temperature value.
    * */
  [[nodiscard]] double GetTemperature() const { return temperature_; }
  /**
    * @brief Returns the humidity value.
    * @return The humidity value.
    * */
  [[nodiscard]] double GetHumidity() const { return humidity_; }
  /**
    * @brief Returns the pressure value.
    * @return The pressure value.
    * */
  [[nodiscard]] double GetPressure() const { return pressure_; }
  /**
    * @brief Sets the temperature value.
    * @param temperature The new temperature value.
    * */
  void SetTemperature(double temperature);
  /**
    * @brief Sets the humidity value.
    * @param humidity The new humidity value.
    * */
  void SetHumidity(double humidity);
  /**
    * @brief Sets the pressure value.
    * @param pressure The new pressure value.
    * */
  void SetPressure(double pressure);
  /**
    * @brief Sets all weather data values.
    * @param temperature The new temperature value.
    * @param humidity The new humidity value.
    * @param pressure The new pressure value.
    * */
  void SetAllData(double temperature, double humidity, double pressure);
  /**
    * @brief Copy assignment operator for WeatherData.
    * @param new_wd The WeatherData object to be copied.
    * @return A reference to the current WeatherData object.
    * */
  WeatherData &operator=(const WeatherData &new_wd);
  /**
    * @brief Move assignment operator for WeatherData.
    * @param new_wd The WeatherData object to be moved.
    * @return A reference to the current WeatherData object.
    * */
  WeatherData &operator=(WeatherData &&new_wd) noexcept;

 private:
  double temperature_;
  double humidity_;
  double pressure_;
  std::vector<std::shared_ptr<DisplayInterface>> connected_displays_ = {};
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_WEATHERDATA_DATA_HPP_
