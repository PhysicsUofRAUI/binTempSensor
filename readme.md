# Bin Temperature Sensor
This project is a gadget to monitor the temperature in a grain bin. This is important because when grain heats it can spoil and a farmer can lose lots of money. The current iteration is the cheapest when 4 bins are wired up and costs about $140 per bin. That cost can be contrasted with the current bin monitoring systems which can cost up to $5000 a bin. The next iteration will focus on lowering the per bin cost for when more than 4 bins are wired up, and the iteration after that will integrate Arduino Cloud into the project, so that all collected data can be stored for later use.

## Main Hardware
### Arduino MKR 1400
This will be the Arduino that will send the alerts to the farmer and possibly one day send data to the Arduino Cloud. At the moment the code is designed to be controlled soley by the MKR 1400, but in the next iteration it will recieve alerts from regular Arduinos.

### Temperature Sensor
The DHT 22 or the DFR0198 sensor is currently being used as the sensor. Three of them are needed to monitor one bin.

### RF Link kits
The next iteration of the code will have the MKR 1400 recieve alerts from regular Arduinos about the sensors in the regular Arduinos.

### Arduino Mega
This will be used in the second iteration to control the sensors in the bin and send the alerts or data to the MKR 1400. 

## Implementations
### Current Implementation
The current iteration is simple, and only uses the MKR 1400 and the DHT 22 sensors or DFR0198 sensors. It will connect to the cloud and will request data every 15 minutes and if the temperature has changed the cloud will be updated. The frequency of readings can be reduced to save on data charges. This iteration is using the code located in code/ArduinoCloud.

#### Cost
Below I will outline the cost of how much the current implementation would cost for four large bins (about 30ft high). If your bins are larger or smaller you would either need to buy more or less wire, but it should not change the cost that much. The price of the wire put in is what I have got, but your price will probably be different.

#### Hardware Costs
##### With AM2302
| Item            | Price of One                                                                                                            | Number Needed | Total Cost |
| ------------    |:-----------------------------------------------------------------------------------------------------------------------:| -------------:| ----------:|
| MKR 1400        | [$103.41](https://www.digikey.ca/en/products/detail/arduino/ABX00018/8135631)                                           | 1             | $103.41    |
| DHT 22          | [$21.81](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/393/5356714?s=N4IgTCBcDaIIIFkAEYDMAGCBdAvkA) | 12            | $261.72    |
| Junction Box    | [$25.99](https://www.amazon.ca/gp/product/B075DJQJVY/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)                  | 1             | $25.99     |
| Wire (per foot) | Varies                                                                                                                  | 300           | $95        |
| Hologram Sim    | [$5.00](https://store.hologram.io/store/)                                                                               | 1             | $5.00      |
| Total           |                                                                                                                         |               | $491.12    |

Note that shipping was not included for any of this.

#### With DFR0198
| Item            | Price of One                                                                                                            | Number Needed | Total Cost |
| ------------    |:-----------------------------------------------------------------------------------------------------------------------:| -------------:| ----------:|
| MKR 1400        | [$103.41](https://www.digikey.ca/en/products/detail/arduino/ABX00018/8135631)                                           | 1             | $103.41    |
| DFR0198         | [$10.03](https://www.digikey.ca/en/products/detail/dfrobot/DFR0198/7597054)                                             | 12            | $120.36    |
| Junction Box    | [$25.99](https://www.amazon.ca/gp/product/B075DJQJVY/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)                  | 1             | $25.99     |
| Wire (per foot) | Varies                                                                                                                  | 300           | $95        |
| Hologram Sim    | [$5.00](https://store.hologram.io/store/)                                                                               | 1             | $5.00      |
| Total           |                                                                                                                         |               | $349.76    |

#### Monthly Costs
| Item            | Price                                                                                                           |
| --------------------- |:-----------------------------------------------------:|
| Arduino Cloud Account | [$9.00 CAD](https://store.arduino.cc/digital/create#) | 
| Hologram Data Costs   | $11.80 CAD                                            |
| Total                 | $20.8                                                 |

Note: The data charges will probably be lower since this was calculated on costs when there was no grain in the bin and the temperature varies wildly then.

### Future Improvements
#### RF Link kits
The Arduino Mega has 54 digital pins so it can control many more bins than the MKR 1400 can, however, it cannot connect to the network. The RF link kit will allow the Mega to communication with the MKR 1400 and the MKR 1400 will be able to communicate with the network and send alerts.

#### Email Alerts
This is currently the focus of the work and it will entail the MKR GSM sending data to a third party, possibly IFTTT, which will then send out an email alerting the farmer to a temperature rise. 

# Contributing
Please anyone feel free to contribute. It would especially be appreciated if people with more experience on the hardware related, people involved on farms (like me :smiley:) who have experience to what is really needed to help production and save bushels, and people with experience writing software for this type of hardware.

All this being said I do want to stress that those thinking they don't know anything about this, but are still interested in the project please at least contact. We have almost no-one here and even if people don't think it they always have some sort of skill that could be used.

# Final Remarks
Hopefully this project becomes a success and maybe more like could be made!

Thanks for reading all this!
