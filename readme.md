# Bin Temperature Sensor
This project was started to build a affordable 'gadjet' to monitor the temperature of grain in a bin. There is some products already available that do this but they cost a 1000 or more dollars, and from what I can tell contain an excessive amount of sensors. The one to be developed here will have a emphasis on being cheap and doing what needs to be done (aka do not buy or use things that are not needed).

# Hardware
## Arduino
The arduino will be used for simplicity for at least the original version. The arduino is likely the cheapest development board on the market, however there could be others and I'd like you to tell me about them if you find them.

It will be used to collect the data from temperature sensors from the bin then send them to the Raspberrypi.

Later costs could be reduced by putting together the necessary parts to create the device with the least amount of parts necessary.

## Raspberrypi
The Raspberrypi will be used for the same reason as arduino. It will be used to receive all the data from the arduinos. It will also display it on a screen. It could also send a notification to someone. I don't know if this can be replaced with anything, but if anyone has an idea please say :smiley:.

## Temperature Sensor
The only data collection viewed for this system is the temperature sensor to see where the grain is at. It was thought that the best sensor for this would be a infrared sensor (some of that is discussed in more detail in the 'current base idea' pdf). This is because the sensor would not have direct contact with the grain. This may be unnecessary :confused: and some advice on it would certainly be welcome :smiley:.

## Rough Idea of GSM Sheild and Arduino
This plan involves conecting the Arduino on the top of the bin to a GSM sheild. This would then be used to send a text message alert to the farmer in question. 

### Rough cost
- $25 for each Arduino (seems we need an Arduino for each temperature sensor).
- RF link kit for around $15 https://www.mouser.be/ProductDetail/seeed-studio/113060000/?qs=1%252b9yuXKSi8Ar4bRwCH3EMg==&countrycode=DE&currencycode=EUR
- $25 or so for GSM sheild https://www.banggood.com/nl/SIM900-Quad-band-GSM-GPRS-Shield-Development-Board-For-Arduino-p-964229.html?gmcCountry=BE&currency=EUR&createTmp=1&utm_source=googleshopping&utm_medium=cpc_elc&utm_content=zouzou&utm_campaign=pla-be-ele-diy-pc&gclid=EAIaIQobChMI7omYi9ma3gIVQeJ3Ch3oSgNcEAQYAyABEgL3bvD_BwE&cur_warehouse=CN
- $20 or so for each temperature sensor https://www.mouser.be/ProductDetail/melexis/mlx90614esf-baa-000-tu/?qs=KuGPmAKtFKVScNDmoJmFVw==&countrycode=DE&currencycode=EUR
- say the cost of the battery pack around $15

The total cost would then be about $125.

This cost is for two sensor points, one at the bottom and one at the top. I would say hang one in the middle but it would be hard to communicate through the grain with the link kit.



# Contributing
Please anyone feel free to contribute. It would especially be appreciated if people with more experience on the hardware related, people involved on farms (like me :smiley:) who have experience to what is really needed to help production and save bushels, and people with experience writing software for this type of hardware.

All this being said I do want to stress that those thinking they don't know anything about this, but are still interested in the project please at least contact. We have almost no-one here and even if people don't think it they always have some sort of skill that could be used.

# Final Remarks
Hopefully this project becomes a success and maybe more like could be made!

Thanks for reading all this!
