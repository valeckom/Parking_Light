// sensor_sonic.h
// 2017 Mark Valecko
//
// This is for a HC-SR04 Ultra Sonic Sensor
//
// Attach the sensors trigger and echo pin
// Get the distance of an object to the sensor

#ifndef sensor_sonic_H
#define sensor_sonic_H

class SensorSonic {
public:
  SensorSonic();
  void Attach(const int pin_trigger, const int pin_echo);
  const double DistanceInches();

private:
  void UpdatePulseWidth();
  int pin_trigger_;
  int pin_echo_;
  unsigned long pulse_start_;
  unsigned long pulse_end_;
  unsigned long pulse_width_;
};

#endif