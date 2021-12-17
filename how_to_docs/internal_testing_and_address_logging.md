# 1. Introduction
This document was created mostly for myself but it can certainly be used by anyone wanting to log the addresses of DS18B20s.

# 2. Getting to it
## 2.1 Assemble circuit
Assemble a simple circuit connecting the DS18B20 to an Arduino (Uno, mkr, mega) with a 4.7 K Ohm between the data pin and the VCC pin. After this is done plug in the Arduino while running the OneWireSearch example which can be found at the following link: https://github.com/milesburton/Arduino-Temperature-Control-Library/blob/master/examples/oneWireSearch/oneWireSearch.ino.

## 2.2 Record Adress
Now write that Adress on the tag and put it on that DS18B20's tag to be put on the outside of its bag. Also tag it with the location of it in the bin (bottom, middle, or top).

## 2.3 Repeat 3 times
Repeat 2.1 and 2.2 three times so they are done a total of 4 times.

## 2.4 Test Addresses
Use the code located at code/testing_code to check if the addresses recorded are correct. Check to make sure each is reporting right by warming one or two with hands and observing the temperature change.

# 3. Conclusion
This should allow myself and possibly others to record the correct addresses of DS18B20 sensors.
