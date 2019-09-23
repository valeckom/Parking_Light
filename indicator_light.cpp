// indicator_light.cpp
// 2017 Mark Valecko


#include "indicator_light.h"
#include "Particle.h"

IndicatorLight::IndicatorLight() {
  pin_ = 0;
  light_is_on_ = false;
  current_millis_ = 0;
  previous_millis_ = 0;
}

void IndicatorLight::Attach(const int pin) {
  pin_ = pin;
  pinMode(pin_, OUTPUT);
}

void IndicatorLight::Flash(const unsigned int rate) {
  current_millis_ = millis();

  if (current_millis_ - previous_millis_ >= rate) {
    if (light_is_on_) {
      TurnOff();
    } else {
      TurnOn();
    }

    previous_millis_ = current_millis_;
  }
}

void IndicatorLight::TurnOn() {
  digitalWrite(pin_, HIGH);
  light_is_on_ = true;
}

void IndicatorLight::TurnOff() {
  digitalWrite(pin_, LOW);
  light_is_on_ = false;
}