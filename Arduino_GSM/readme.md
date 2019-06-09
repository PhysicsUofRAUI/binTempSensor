# Rough Idea
This plan will have three sensors and a GSM sheild directly connected to a Arduino sitting at the top of the bin. One of the sensors will be close to the bottom, another in the middle, and the last one at the top. They will report the temperature and the humidity at periodic intervals. The Arduino will then send a message if the bin starts heating.

# Materials To Be Used
- Arduino: The arduino will be used to control the sensors and to send the SMS if one the sensors reports a unacceptable temperature increase.
- DHT22 Sensors: Three of these will be deployed in the bin. One close to the top, another in the middle, and the last one close to the bottom. These sensors will be connected controlled by the Arduino.
- Battery Pack: This will either be a battery charging pack that can be bought on Amazon like this one https://www.amazon.ca/Battery-Charger-RAVPower-26800mAh-Portable/dp/B012S6IHQC/ref=sr_1_2_sspa?ie=UTF8&qid=1550267774&sr=8-2-spons&keywords=battery+pack&psc=1 or a couple of old cell phone batteries made into a battery pack following this instructable https://www.instructables.com/id/Make-A-Cheap-Lithium-Battery-Pack/. Simply using a 9V battery may do as well.
- Some Wood: This would be used to construct a small casing for the Arduino that is rain proof but not water proof. This will help with potential moisture problems.
- a wire or rope: To string the sensors done into the bin
- A Resistor: To heat the Arduino enclosure when it gets cold out.

# Tutorials that are useful
- https://learn.adafruit.com/dht/overview
- https://www.instructables.com/id/Make-A-Cheap-Lithium-Battery-Pack/
- https://randomnerdtutorials.com/sim900-gsm-gprs-shield-arduino/
- https://www.instructables.com/id/Sim900-GSM-module-interfacing-to-arduino/
- http://wiki.epalsite.com/index.php?title=SIM900_Quad-Band_GPRS_shield
- https://www.instructables.com/id/SIM900-GSM-Based-Weather-Notifier/
- http://wiki.seeedstudio.com/GPRS_Shield_v1.0/

Will add more later when I get to my other computer.

# The 'ChangedCodeToWhatIThinkWillWork'
This was created by me from looking at what the gsmAccess.begin() does. To find the code for the .begin() function follow these steps.
1. Go to your Arduino directory
- For me it was in my home directory and it was called 'Arduino'
2. Then switch into the directory called 'libraries'
3. In this directory there should be one called MKRGSM open that one.
4. In MKRGSM there should be two files called GSM.h and GSM.cpp
- This is where the code is located.
5. It is the begin function and details how the function operates

What I realized when looking at it is that it seems to be hanging when the modem is being started. Since this is the case I decided to start the modem myself before (lines 46 to 58) and then move to the begin function. Instead of passing in true for the 'restart' variable of begin I pass in false. It no longer hangs but as of right now I still get no network, so I have ordered a antenna and will test that next week. 
