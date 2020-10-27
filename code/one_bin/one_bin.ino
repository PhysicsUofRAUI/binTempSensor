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

float current_temp;
float difference;
bool limit_reached;

/*
Purpose: To get the temperature when it fails. This function will first be called when
  the primary attempt to attain the temperature failed. It will enter a loop attempting 
  to retrieve the temperature, and will not leave till the temperature is retrieved.
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

  while (isnan(temperature) != true)
  {
    sensor_needed.temperature().getEvent(&new_event);

    float temperature = new_event.temperature;

    delay(4000);
  }

  return temperature;
}


/*
Purpose: This will be used to determine whether or not an alert needs to be sent to the farmer.
  It accomplishes this by comparing the old_temp to the new_temp and checking whether the temperature
  has increased too much.
  
Parameters:
  old_temp : a float that holds the value from the last iteration
  new_temp : a float that holds the value from the current iteration
  
Variables:
  None

Returns:
  limit_reached : A boolean that is true if the new_temp is 0.5 degrees higher (the threshold)
    than the old_temp and false other wise
*/
bool temperature_increase_limit_reached(float old_temp, float new_temp){
  // decrease new_temp by the threshold
  new_temp = new_temp - 0.5;

  if (old_temp < new_temp) {
    return true;
  } else {
    return false;
  }
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

  sms.beginSMS("13069219628");
  sms.print("Connected!");
  sms.endSMS();
}

void loop() {
  // Get temperature event 1
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);
  
  // Get the current temperature from sensor 1
  current_temp = event1.temperature;

  limit_reached = temperature_increase_limit_reached(temp1, current_temp);

  if (limit_reached) {
    difference = current_temp - temp1;
    sms.beginSMS("13069219628");
    sms.print("temperature 1 has increased by ");
    sms.print(difference);
    sms.endSMS();
  }

  temp1 = current_temp;


  // Get temperature event 2
  sensors_event_t event2;
  dht2.temperature().getEvent(&event2);
  
  // Get the current temperature from sensor 2
  current_temp = event2.temperature;

  limit_reached = temperature_increase_limit_reached(temp2, current_temp);

  if (limit_reached) {
    difference = current_temp - temp2;
    sms.beginSMS("13069219628");
    sms.print("temperature 2 has increased by ");
    sms.print(difference);
    sms.endSMS();
  }

  temp2 = current_temp;
  

  // Get temperature event 3
  sensors_event_t event3;
  dht3.temperature().getEvent(&event3);

  // Get the current temperature from sensor 1
  temp3 = event3.temperature;

  limit_reached = temperature_increase_limit_reached(temp3, current_temp);

  if (limit_reached) {
    difference = current_temp - temp3;
    sms.beginSMS("13069219628");
    sms.print("temperature 3 has increased by ");
    sms.print(difference);
    sms.endSMS();
  }

  temp3 = current_temp;

  // wait for 12 hours
  delay(43200000);

}
