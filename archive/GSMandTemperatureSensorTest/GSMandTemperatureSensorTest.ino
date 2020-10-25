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
#define DHTPIN2            4
#define DHTPIN3            6

#define DHTTYPE           DHT22

DHT_Unified dht1(DHTPIN1, DHTTYPE);
DHT_Unified dht2(DHTPIN2, DHTTYPE);
DHT_Unified dht3(DHTPIN3, DHTTYPE);

float temp1 = 0;
float temp2 = 0;
float temp3 = 0;

/*
Purpose: To get the temperature when it fails. This function will first be called when
  the primary attempt to attain the temperature failed, and it will then be recusivly
  called until such time the temperature is attained.
Parameters:
  sensor_needed: This is an object that represents the sensor that failed to
    read.
Variables:
  new_event: The event object as defined in the DHT libraries. This is a variable
    used to collect information from an event. It will be used in this function
    to get the temperature information.

Returns:
  temperature: a float that is the temperature that was read.
*/
float getTemperatureInCaseOfError(DHT_Unified sensor_needed)
{
  sensors_event_t new_event;

  delay(4000);

  sensor_needed.temperature().getEvent(&new_event);

  float temperature = new_event.temperature;

  if (isnan(temperature))
  {
    temperature = getTemperatureInCaseOfError(sensor_needed);
  }

  return temperature;
}

void setup() {

  dht1.begin();
  dht2.begin();
  dht3.begin();

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
  // Get temperature event
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);
  
  if (isnan(event1.temperature)) {
    // try to get the event again
    temp1 = getTemperatureInCaseOfError(dht1);

    // When getting the event is a success print the temperature
    sms.beginSMS("13069219628");
    sms.print("temperature 1: ");
    sms.print(temp1);
    sms.endSMS();
  }
  else {
    // Get the current temperature from sensor 1
    temp1 = event1.temperature;

    sms.beginSMS("13069219628");
    sms.print("temperature 1: ");
    sms.print(temp1);
    sms.endSMS();
  }

  // Get temperature event
  sensors_event_t event2;
  dht2.temperature().getEvent(&event2);
  
  if (isnan(event2.temperature)) {
    // try to get the event again
    temp2 = getTemperatureInCaseOfError(dht2);

    // When getting the event is a success print the temperature
    sms.beginSMS("13069219628");
    sms.print("temperature 2: ");
    sms.print(temp2);
    sms.endSMS();
  }
  else {
    // Get the current temperature from sensor 1
    temp2 = event2.temperature;

    sms.beginSMS("13069219628");
    sms.print("temperature 2: ");
    sms.print(temp2);
    sms.endSMS();
  }

  // Get temperature event
  sensors_event_t event3;
  dht3.temperature().getEvent(&event3);
  
  if (isnan(event3.temperature)) {
    // try to get the event again
    temp3 = getTemperatureInCaseOfError(dht3);

    // When getting the event is a success print the temperature
    sms.beginSMS("13069219628");
    sms.print("temperature 3: ");
    sms.print(temp3);
    sms.endSMS();
  }
  else {
    // Get the current temperature from sensor 1
    temp3 = event3.temperature;

    sms.beginSMS("13069219628");
    sms.print("temperature 3: ");
    sms.print(temp3);
    sms.endSMS();
  }

  delay(43200000);

}
