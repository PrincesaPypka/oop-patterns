#ifndef OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_
#define OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_

class DisplayInterface :
    public std::enable_shared_from_this<DisplayInterface> {
 public:
  using Shared = std::shared_ptr<DisplayInterface>;
  virtual void Update() = 0;
  virtual void Display() const = 0;
};

#endif //OBSERVER_PATTERN_WEATHERSTATION_DISPLAY_INTERFACE_HPP_
