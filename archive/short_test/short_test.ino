/*
 * This file is meant to hold a test for the arduino MKR 1400 the temperature
 * sensors and its accompanying battery.
 * The test will be to send the temperature every 12 hours via sms. 
 * What I hope to get out of this is an idea of how long the Arduino can last on this 
 * particular battery, and whether the sensors are reliable.
 */

// Include all the needed libraries
#include <MKRGSM.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

// Set up everything for the cellular device to work

// modem verification object
GSMModem modem;

// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;

// everything to control the sensors
#define DHTPIN1            5

#define DHTTYPE           DHT22

DHT_Unified dht1(DHTPIN1, DHTTYPE);

float temp1 = 0;


void setup() {

  dht1.begin();

  sensor_t sensor;

  // connection state
  bool connected = false;
  bool flag = true;

  while(flag)
  {
    // start modem test (reset and check response)
    if (modem.begin()) {
      flag = false;
    } else {
    }
  }

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (!connected) {
    if (gsmAccess.begin("0000") == GSM_READY) {
      connected = true;
    } else {
      delay(1000);
    }
  }
}



void loop() {
  // Get temperature event 1
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);
  
  // Get the current temperature from sensor 1
  temp1 = event1.temperature;

  sms.beginSMS("13069219618");
  sms.print("temperature 1: ");
  sms.print(temp1);
  sms.endSMS();

  delay(100000);

}
