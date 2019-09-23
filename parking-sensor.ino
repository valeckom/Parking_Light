// parkingsensor.ino
// 2017 Mark Valecko
//
// Measures distance to car and gives visual feedback via LEDs
//
// HARDEWARE
// HC-SR04 Ultrasonic Sensor
// Vcc  -> VIN
// Trig -> D0
// Echo -> D1
// GND  -> GND
//
// Red LED
//  + -> D2
//  - -> GND
//
//  Yellow LED
//  + -> D3
//  - -> GND
//
//  Green LED
//  + -> D4
//  - -> GND

#include "indicator_light.h"
#include "sensor_sonic.h"

IndicatorLight redLed;
IndicatorLight yellowLed;
IndicatorLight greenLed;
SensorSonic sonicSensor;

const double kParkDistance = 17.0; // target inches from object
const double kPhi = 1.618;  // golden ratio (Phi)
const double kStopDistance = kParkDistance / kPhi; // alert stop distance
const double kSlowDistance = kParkDistance * kPhi; // getting close distance

double distance = 0;

void setup() { // attach all hardware
  sonicSensor.Attach(D0, D1);
  redLed.Attach(D2);
  yellowLed.Attach(D3);
  greenLed.Attach(D4);
  Particle.variable("Distance", distance); // cloud Variable
}

void loop() {

  distance = sonicSensor.DistanceInches();

  if (distance <= kStopDistance) { // flash red when too close
    redLed.Flash(100);
    yellowLed.TurnOff();
    greenLed.TurnOff();
  } else if (distance <= kParkDistance) { // solid red when to stop
    redLed.TurnOn();
    yellowLed.TurnOff();
    greenLed.TurnOff();
  } else if (distance <= kSlowDistance) { // solid yellow when close
    redLed.TurnOff();
    yellowLed.TurnOn();
    greenLed.TurnOff();
  } else if (distance < 40) { // solid green when clear
    redLed.TurnOff();
    yellowLed.TurnOff();
    greenLed.TurnOn();
  } else { // flash yellow when the sensor does not see the object
    redLed.TurnOff();
    yellowLed.Flash(250);
    greenLed.TurnOff();
  }
}