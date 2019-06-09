// Include the GSM library
#include <MKRGSM.h>

#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

#define DHTPIN1            2
#define DHTPIN2            3
#define DHTPIN3            4

#define DHTTYPE           DHT22

DHT_Unified dht1(DHTPIN1, DHTTYPE);
DHT_Unified dht2(DHTPIN2, DHTTYPE);
DHT_Unified dht3(DHTPIN3, DHTTYPE);

float temp1 = 0;
float temp2 = 0;
float temp3 = 0;

float cur_temp1;
float cur_temp2;
float cur_temp3;

int difference;

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




// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("SMS Messages Sender");

  // connection state
  bool connected = false;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (!connected) {
    if (gsmAccess.begin(0000) == GSM_READY) {
      connected = true;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");

  Serial.begin(9600);

  dht1.begin();
  dht2.begin();
  dht3.begin();

  sensor_t sensor;

  Serial.println("All sensors initialized");
}



/*
This is the loop. It will get measurements from all three sensors, display
the temperature, and the difference from the previous value.

It will then wait 10 seconds to do the next set of measurements then it will repeat.
*/
void loop() {
  // Get temperature event
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);

  if (isnan(event1.temperature)) {
    // try to get the event again
    float temperature = getTemperatureInCaseOfError(dht1);

    // find the difference between current value and previous value
    difference = temperature - temp1;

    // When getting the event is a success print the temperature
    sms.beginSMS("13069218495");
    sms.print("Hello there");
    sms.print("temperature 1: ");
    sms.print(temperature);
    sms.print(", difference: ");
    sms.println(difference);
    sms.endSMS();

    // update the temp1 variable
    temp1 = temperature;
  }
  else {
    // Get the current temperature from sensor 1
    float temperature = event1.temperature;

    // find the difference between current value and previous value
    difference = temperature - temp1;

    // print the current temperature and the difference from the
    // previous temperature
    sms.beginSMS("13069218495");
    sms.print("Hello there");
    sms.print("temperature 1: ");
    sms.print(temperature);
    sms.print(", difference: ");
    sms.println(difference);
    sms.endSMS();

    // update temp 1
    temp1 = cur_temp1;
  }

  // Get temperature event and print its value.
  sensors_event_t event2;
  dht2.temperature().getEvent(&event2);
  if (isnan(event2.temperature)) {
    // try to get the event again
    float temperature = getTemperatureInCaseOfError(dht2);

    // find the difference between current value and previous value
    difference = temperature - temp2;

    // When getting the event is a success print the temperature
    sms.beginSMS("13069218495");
    sms.print("Hello there");
    sms.print("temperature 2: ");
    sms.print(temperature);
    sms.print(", difference: ");
    sms.println(difference);
    sms.endSMS();

    // update the temp1 variable
    temp2 = temperature;
  }
  else {
    // Get the current temperature from sensor 2
    float temperature = event2.temperature;

    // find the difference between current value and previous value
    difference = temperature - temp2;

    // When getting the event is a success print the temperature
    sms.beginSMS("13069218495");
    sms.print("Hello there");
    sms.print("temperature 2: ");
    sms.print(temperature);
    sms.print(", difference: ");
    sms.println(difference);
    sms.endSMS();

    // update the temp2 variable
    temp2 = cur_temp2;
  }

  // Get temperature event and print its value.
  sensors_event_t event3;
  dht3.temperature().getEvent(&event3);
  if (isnan(event3.temperature)) {
    // try to get the event again
    float temperature = getTemperatureInCaseOfError(dht3);

    // find the difference between current value and previous value
    difference = temperature - temp3;

    // When getting the event is a success print the temperature
    sms.beginSMS("13069218495");
    sms.print("Hello there");
    sms.print("temperature 3: ");
    sms.print(temperature);
    sms.print(", difference: ");
    sms.println(difference);
    sms.endSMS();

    // update the temp3 variable
    temp3 = temperature;
  }
  else {
    // Get the current temperature from sensor 3
    float temperature = event3.temperature;

    // find the difference between current value and previous value
    difference = cur_temp3 - temp3;

    // When getting the event is a success print the temperature
    sms.beginSMS("13069218495");
    sms.print("Hello there");
    sms.print("temperature 3: ");
    sms.print(temperature);
    sms.print(", difference: ");
    sms.println(difference);
    sms.endSMS();

    // update the temp3 variable
    temp3 = cur_temp3;
  }

  // Delay between measurements.
  delay(30000);
}
