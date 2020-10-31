# Purpose of this document
This document is meant to explain how to setup the custom library that was created so that the code provided in this repo will compile in the Arduino IDE. It also meant to explain how to run the tests in case someone wants to.

## 'Installing' the library
Follow these steps so that the Arduino IDE will know of the custom library that has been built.

1. Locate the libraries directory for Arduino.
 - on my machine it is found in '~/snap/arduino/41/Arduino/libraries'
 - for more information check out this article https://www.arduino.cc/en/hacking/libraries
2. Create a new directory called 'bin_sensor_library'
3. Copy the file 'custom_libraries/bin_sensor_library/bin_sensor.hpp' to the newly created directory
4. The code should now compile in your Arduino IDE

## Running the Tests
Follow these steps to run the tests

1. Install [CMake](https://cmake.org/) if not already installed.
2. Open terminal
3. Navigate to the custom_libraries directory in this project
4. Run `make clean` to remove any previous compilations
5. Run `make` to compile the tests
6. Run `./bin/DHT_U` to test the mock library
7. Run `./bin/bin_sensor` to test the custom library
