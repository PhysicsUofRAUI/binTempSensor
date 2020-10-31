# Bin Temperature Sensor
This project is a gadget to monitor the temperature in a grain bin. This is important because when grain heats it can spoil and a farmer can lose lots of money. The current iteration is the cheapest when 4 bins are wired up and costs about $140 per bin. That cost can be contrasted with the current bin monitoring systems which can cost up to $5000 a bin. The next iteration will focus on lowering the per bin cost for when more than 4 bins are wired up, and the iteration after that will integrate Arduino Cloud into the project, so that all collected data can be stored for later use.

## Main Hardware
### Arduino MKR 1400
This will be the Arduino that will send the alerts to the farmer and possibly one day send data to the Arduino Cloud. At the moment the code is designed to be controlled soley by the MKR 1400, but in the next iteration it will recieve alerts from regular Arduinos.

### Temperature Sensor
The DHT 22 sensor is currently being used as the sensor. Three of them are needed to monitor one bin.

### RF Link kits
The next iteration of the code will have the MKR 1400 recieve alerts from regular Arduinos about the sensors in the regular Arduinos.

### Arduino Uno
This will be used in the second iteration to control the sensors in the bin and send the alerts or data to the MKR 1400. 

## Implementations
### Current Implementation
The current iteration is simple, and only uses the MKR 1400 and the DHT 22 sensors. The MKR 1400 requests temperature data from the sensors every 12 hours, and compares it to the previous data. If the temperature has increased the farmer gets sent an alert. 

#### Cost
Below I will outline the cost of how much the current implementation would cost for one large bin (about 30ft high) and for four large bins. If your bins are larger or smaller you would either need to buy more or less wire, but it should not change the cost that much. A significant cost not accounted for here is the price of a mobile plan and a sim card for the Arduino MKR 1400. I use a Sasktel card which costs about $60 to activate and then $15 a month for the plan I use. That plan takes up another $180, so it is significant. I also did not include the price of a USB cable or a USB port, but any micro-usb cable will work so it is a minor cost. 

##### One bin
| Item            | Price of One                                                                                                            | Number Needed | Total Cost |
| ------------    |:-----------------------------------------------------------------------------------------------------------------------:| -------------:| ----------:|
| MKR 1400        | [$107.85](https://www.digikey.ca/en/products/detail/arduino/ABX00018/8135631)                                           | 1             | $107.85    |
| DHT 22          | [$23.08](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/393/5356714?s=N4IgTCBcDaIIIFkAEYDMAGCBdAvkA) | 3             | $69.24     |
| Junction Box    | [$18.99](https://www.amazon.ca/gp/product/B075DG55KS/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)                  | 1             | $18.99     |
| Wire (per foot) | $0.5 (local hardware store)                                                                                             | 75            | $37.5      |
| Total           |                                                                                                                         |               | $233.58    |

#### Four bins
| Item            | Price of One                                                                                                            | Number Needed | Total Cost |
| ------------    |:-----------------------------------------------------------------------------------------------------------------------:| -------------:| ----------:|
| MKR 1400        | [$107.85](https://www.digikey.ca/en/products/detail/arduino/ABX00018/8135631)                                           | 1             | $107.85    |
| DHT 22          | [$23.08](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/393/5356714?s=N4IgTCBcDaIIIFkAEYDMAGCBdAvkA) | 12            | $276.96    |
| Junction Box    | [$18.99](https://www.amazon.ca/gp/product/B075DG55KS/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)                  | 1             | $18.99     |
| Wire (per foot) | $0.5 (local hardware store)                                                                                             | 300           | $150       |
| Total           |                                                                                                                         |               | $553.80    |

### Second Iteration
This iteration will improve upon the first iteration by using RF link kits. The RF link kits will link the MKR 1400 to Arduino Unos, and the Arduio Unos will perform the job that the MKR 1400 was doing in the first iteration. This will allow many more bins to be monitored with only one MKR 1400, which is an improvement because the MKR 1400 is the most expensive item.

### Third Iteration ([Arduino Cloud!!!!!](https://www.arduino.cc/en/IoT/HomePage))
This iteration will integrate the monitors with the Arduino Cloud. All data that is collected from the bin will be sent to the Arduino Cloud, and logged in someway that is accessible to the user (Google Sheets, or perhaps a custom web app).

# Contributing
Please anyone feel free to contribute. It would especially be appreciated if people with more experience on the hardware related, people involved on farms (like me :smiley:) who have experience to what is really needed to help production and save bushels, and people with experience writing software for this type of hardware.

All this being said I do want to stress that those thinking they don't know anything about this, but are still interested in the project please at least contact. We have almost no-one here and even if people don't think it they always have some sort of skill that could be used.

# Final Remarks
Hopefully this project becomes a success and maybe more like could be made!

Thanks for reading all this!
