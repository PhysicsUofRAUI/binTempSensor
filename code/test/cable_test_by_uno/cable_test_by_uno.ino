// Include all the needed libraries
#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

// everything to control the sensors
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

void setup() {
  // put your setup code here, to run once:
  dht1.begin();
  dht2.begin();
  dht3.begin();
  
  sensor_t sensor;

  Serial.print("Everthing Initialized From Kody");
}

void loop() {
  // Get temperature event
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);

  if (isnan(event1.temperature)) {
    Serial.println("sensor failed");
  }
  else {
    // Get the current temperature from sensor 1
    cur_temp1 = event1.temperature;

    // find the difference between current value and previous value
    difference = cur_temp1 - temp1;

    // print the current temperature and the difference from the
    // previous temperature
    Serial.print("temperature 1: ");
    Serial.print(cur_temp1);
    Serial.print(", difference: ");
    Serial.println(difference);

    // update temp 1
    temp1 = cur_temp1;
  }

  // Get temperature event and print its value.
  sensors_event_t event2;
  dht2.temperature().getEvent(&event2);
  if (isnan(event2.temperature)) {
    Serial.println("sensor failed");
  }
  else {
    // Get the current temperature from sensor 2
    cur_temp2 = event2.temperature;

    // find the difference between current value and previous value
    difference = cur_temp2 - temp2;

    // When getting the event is a success print the temperature
    Serial.print("temperature 2: ");
    Serial.print(cur_temp2);
    Serial.print(", difference: ");
    Serial.println(difference);

    // update the temp2 variable
    temp2 = cur_temp2;
  }

  // Get temperature event and print its value.
  sensors_event_t event3;
  dht3.temperature().getEvent(&event3);
  if (isnan(event3.temperature)) {
    Serial.println("sensor failed");
  }
  else {
    // Get the current temperature from sensor 3
    cur_temp3 = event3.temperature;

    // find the difference between current value and previous value
    difference = cur_temp3 - temp3;

    // When getting the event is a success print the temperature
    Serial.print("temperature 3: ");
    Serial.print(cur_temp3);
    Serial.print(", difference: ");
    Serial.println(difference);

    // update the temp3 variable
    temp3 = cur_temp3;
  }

  // Delay between measurements.
  delay(10000);
}
