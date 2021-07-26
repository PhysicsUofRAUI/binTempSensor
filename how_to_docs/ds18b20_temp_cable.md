# Goals and Description
1. Outline the steps to make a temperature cable
2. Spread the cheer of grain monitoring far and wide

# Materials needed
- [3 DS18B20 sensors](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/381/5875807)
- Some wire (I used 60 ft for a 25ft tall bin)
- Solder & soldering iron

## Step One: Measure The Bin
The easiest way to do this is to measure the height of one ring and then count how many rings there are. In my case I measured one ring to be roughly 3.5 feet, and I counted 5 rings in total. That makes a total height of $3.5ft \times 5 = 17.5ft$.

To gauge how long the entire cable needs to be I estimated the height of the top to be 5ft to 8.5ft. That brings the total height estimate to 25ft so doubling that brings me to 50ft and then an extra 10ft gives some leeway to hook up the arduino later.

## Step Two: Decide where to place the sensors
Placing the sensors have to be done with some care. The top sensor should be in the top ring or lower so it is covered by the grain, and the bottom sensor needs to be somewhere around the start of the hopper but can not be at the bottom.

What I did was to place the bottom sensor first and then the space the other two 7ft away from each other. This should give good overall coverage of the bin, and also ensure that each sensor is in the grain.

Below is an outline of how my sensors should line up in the bin.

<img src="outline_sensor_locations.jpg" alt="drawing" width="400"/>

## Step Three: Mark where the sensors go on the main cable
Before I started attaching the sensors I used a knife to mark the places where the sensors are to go. A photo can be seen below.

<img src="mark_on_cable.jpg" alt="drawing" width="400"/>

When doing longer cables I would attach a sensor and then mark the next one just because it was getting to become cumbersome to deal with all the wire that was strewn around the shop.

## Step Four: Attach the sensors to the main cable
Before placing all the sensors on the cable it is advisable to slide three pieces of heat shrink (about 6 inches in length) onto the cable to be used later to cover up all the connections made while attaching the sensors.

### Bottom Sensor
1. Strip the power (I used the red one) and the ground (I used the black one) just a enough so the sensor can be attached.

2. Now strip the wire that will be used as the data pin.

3. Solder the black wire of the sensor to the ground.

4. Solder the red wire to the power.

5. Solder the last wire (yellow wire on my devices) to the conductor that will be used as the data wire.

6. Put some electrical tape around each of the solders. 
  - Note: for this one heat shrink could be used, but for the following it could not

7. Apply the first heat shrink around the electrical connections. Do not heat the heat shrink until after the cable is tested in case something is wrong.
- add photo of heat shrink being applied
<img src="ds18b20_sensor.jpg" alt="drawing" width="400"/>
- add photo of sensor attached

### Middle and Top Sensor
1. Measure the decided amount of feet separating each sensor and mark the location.

2. Follow the steps done for the bottom sensor keeping in mind the sheathing will have to be cut away instead of stripped since it is in the middle of the cable.

Cable shown stripped in the middle.

<img src="middle_sensor_stripped.jpg" alt="drawing" width="400"/>

The sensor soldered and attached in the middle.

<img src="ds18b20_middle_solder.jpg" alt="drawing" width="400"/>

The sensor tapped in the middle.

<img src="ds18b20_tapped.jpg" alt="drawing" width="400"/>

- add one with the heat shrink

## Step 5: Test the Cable
No testing regime as of yet, but it will come.

## Step 6: Complete the Cable
If the testing went as planned take a heat gun (or a torch if you do not have one), and heat the heat shrink to seal the connections. 

# Conclusion
This concludes the tutorial of how to create the DS18B20 based temperature monitoring cable. Soon tutorials involving how to how up and start monitoring the grain will be uploaded, but it is not that hard and if anyone is actually interested please reach out and I will help or get the tutorial out faster.