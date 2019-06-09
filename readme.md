# Bin Temperature Sensor
This project was started to build a affordable 'gadjet' to monitor the temperature of grain in a bin. There is some products already available that do this but they cost a 1000 or more dollars, and from what I can tell contain an excessive amount of sensors. The one to be developed here will have a emphasis on being cheap and doing what needs to be done (aka do not buy or use things that are not needed).

# Main Hardware
## Arduino
The arduino will be used for simplicity for at least the original version. The arduino is likely the cheapest development board on the market, however there could be others and I'd like you to tell me about them if you find them.

It will be used to collect the data from temperature sensors from the bin then send them to the Raspberrypi.

Later costs could be reduced by putting together the necessary parts to create the device with the least amount of parts necessary.

## Raspberrypi
The Raspberrypi will be used for the same reason as arduino. It will be used to receive all the data from the arduinos. It will also display it on a screen. It could also send a notification to someone. I don't know if this can be replaced with anything, but if anyone has an idea please say :smiley:.

## Temperature Sensor
The only data collection viewed for this system is the temperature sensor to see where the grain is at. It was thought that the best sensor for this would be a infrared sensor (some of that is discussed in more detail in the 'current base idea' pdf). This is because the sensor would not have direct contact with the grain. This may be unnecessary :confused: and some advice on it would certainly be welcome :smiley:.

An option for a sensor that does make direct contact is the DHT 22 sensor that senses both humidity and temperature. It may be interesting to log both the humidity data and the temperature data and do analysis on it to see if the humidity could be used as a early warning.

# Rough Idea of GSM Sheild and wired connection to Arduino
This plan will have three sensors and a GSM sheild directly connected to a Arduino sitting at the top of the bin. One of the sensors will be close to the bottom, another in the middle, and the last one at the top. They will report the temperature and the humidity at periodic intervals. The Arduino will then send a message if the bin starts heating.

More information is located in the folder Arduino_GSM.

# RF Link between Raspberry Pi and Arduino with sensor having wired connection to Arduino
This is largely the same as with the GSM sheild except that the Arduino reports everything to the Raspberry Pi. It is then up to the farmer to look at the data trend or for the Raspberry Pi to alert the farmer in some way (email, GSM, etc). This version could be useful in locations that lack cell service in certain areas but has better in others. The RF link would take the data from a no wifi or cell recption to a place with wifi or cell reception.

Again more information on this one will again be located in its own separate folder. This folder will be called 'RF_RaspberryPi_Arduino'.

# WiFi and Arduino
Another option could be using WiFi directly to transmit the data. This might work for some places, but since bin yards are large and located in rural places WiFi may not be availble. It is useful to look into though since it would drive the cost down and increase connection reliability.

Any future work on this will be included in the folder 'Wifi'

# Contributing
Please anyone feel free to contribute. It would especially be appreciated if people with more experience on the hardware related, people involved on farms (like me :smiley:) who have experience to what is really needed to help production and save bushels, and people with experience writing software for this type of hardware.

All this being said I do want to stress that those thinking they don't know anything about this, but are still interested in the project please at least contact. We have almost no-one here and even if people don't think it they always have some sort of skill that could be used.

# Final Remarks
Hopefully this project becomes a success and maybe more like could be made!

Thanks for reading all this!
