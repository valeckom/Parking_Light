# Parking Light
Measure the distance to a vehicle and gives visual feedback via LEDs. 
## Required Hardware
- Particle Photon Microcontroller
- HC-SR04 Ultrasonic Sensor
- 30000MCD 10mm led (x3)
> (Optional) 3D Printer
## Hardware Build
- Install the LED into a traffic light fixture.
- Mount the Ultrasonic Sensor in a location that will allow it to measure the distance between a parking vehicle and the object you wish to park near.
> (Optional) Print the mount files. Use the mounts to connect the sensor with the controller via an cat-5 cable.
## Software
Upload all files into the microcontroller
### parking-sensor.ino
This is the main program run by the microcontroller.
### sensor-sonic
The control class for the HC-SR04 Ultrasonic Sensor.
### indicator-light
The class for controlling a LED.