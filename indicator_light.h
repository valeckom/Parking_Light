// indicator_light.h
// 2017 Mark Valecko
//
// Attach an LED
// Control wether the LED is on or off and be able to flash it.

#ifndef indicator_light_H
#define indicator_light_H

class IndicatorLight {
public:
  IndicatorLight();
  void Attach(const int pin);
  void Flash(const unsigned int rate);
  void TurnOn();
  void TurnOff();
private:
  int pin_; // holds hardeware pin adress
  bool light_is_on_; // holds pin state
  // used for timming
  unsigned long current_millis_;
  unsigned long previous_millis_;
};

#endif