// sensor_sonic.cpp
// 2017 Mark Valecko
//
// This is for a HC-SR04 Ultra Sonic Sensor
//
// Trigger the sensor with a 10 microsecond pulse
// The sensor will respond with a 150 microsecond to 25 millisecond pulse, that corresponds to the distance of an object
// If no object is found it will respond with a 38ms pulse

#include "sensor_sonic.h"
#include "Particle.h"

SensorSonic::SensorSonic() {
    pin_trigger_ = 0;
    pin_echo_ = 0;
    pulse_start_ = 0;
    pulse_end_ = 0;
    pulse_width_ = 0;
}

void SensorSonic::Attach(const int pin_trigger,const int pin_echo) {
    // set pins and turn off signal to the sensor
    pin_trigger_ = pin_trigger;
    pin_echo_ = pin_echo;
    pinMode(pin_trigger_, OUTPUT);
    pinMode(pin_echo_, INPUT);
    digitalWrite(pin_trigger_, LOW); // set trigger pin off to start
}

const double SensorSonic::DistanceInches() {
    // update pulse_width_ and calculate the distance in inches
    UpdatePulseWidth();
    return pulse_width_ / 148.0;
}

void SensorSonic::UpdatePulseWidth() {
    // Send out a 10 microsecond pulse
    digitalWrite(pin_trigger_, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin_trigger_, LOW);

    // Wait for pulse on echo pin
    while (digitalRead(pin_echo_) == 0);

    // Measure how long the echo pin was held high (pulse width)
    // Note: the micros() counter will overflow after ~70 min
    pulse_start_ = micros();
    while (digitalRead(pin_echo_) == 1);
    pulse_end_ = micros();

    pulse_width_ = pulse_end_ - pulse_start_;

    // Wait at least 50ms before next measurement
    delay(60);
}