#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

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

float cur_temp1;
float cur_temp2;
float cur_temp3;

int difference;

/*
Purpose: To get the temperature when it fails. This function will first be called when
  the primary attempt to attain the temperature failed, and it will then be recusivly
  called until such time the temperature is attained.
*/
float getTemperatureInCaseOfError(sensors_event_t new_event, DHT_Unified sensor_needed)
{
  delay(4000);

  sensor_needed.temperature().getEvent(&new_event);

  float temperature = new_event.temperature;

  if (isnan(temperature))
  {
    temperature = getTemperatureInCaseOfError(new_event, sensor_needed);
  }

  return temperature;
}


void setup() {
  Serial.begin(9600);

  dht1.begin();
  dht2.begin();
  dht3.begin();

  sensor_t sensor;

  Serial.print("Everthing Initialized From Kody");
}

void loop() {
  // Delay between measurements.
  delay(10000);
  // Get temperature event and print its value.
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);
  if (isnan(event1.temperature)) {
    // send the message
    float temperature = getTemperatureInCaseOfError(event1, dht1);
    difference = temperature - temp1;

    Serial.print("temperature 1: ");
    Serial.print(temperature);
    Serial.print(", difference: ");
    Serial.print(difference);

    temp1 = temperature;
  }


  else {
    cur_temp1 = event1.temperature;
    difference = cur_temp1 - temp1;

    Serial.print("temperature 1: ");
    Serial.print(cur_temp1);
    Serial.print(", difference: ");
    Serial.print(difference);

    temp1 = cur_temp1;
  }

  // Get temperature event and print its value.
  sensors_event_t event2;
  dht2.temperature().getEvent(&event2);
  if (isnan(event2.temperature)) {
    float temperature = getTemperatureInCaseOfError(event2, dht2);
    difference = temperature - temp2;

    Serial.print("temperature 2: ");
    Serial.print(temperature);
    Serial.print(", difference: ");
    Serial.print(difference);

    temp1 = temperature;
  }
  else {
    cur_temp2 = event2.temperature;
    difference = cur_temp2 - temp2;

    Serial.print("temperature 2: ");
    Serial.print(cur_temp2);
    Serial.print(", difference: ");
    Serial.print(difference);

    temp2 = cur_temp2;
  }

  // Get temperature event and print its value.
  sensors_event_t event3;
  dht3.temperature().getEvent(&event3);
  if (isnan(event3.temperature)) {
    float temperature = getTemperatureInCaseOfError(event3, dht3);
    difference = temperature - temp1;

    Serial.print("temperature 3: ");
    Serial.print(temperature);
    Serial.print(", difference: ");
    Serial.print(difference);

    temp1 = temperature;
  }
  else {
    cur_temp3 = event3.temperature;

    difference = cur_temp3 - temp3;

    Serial.print("temperature 3: ");
    Serial.print(cur_temp3);
    Serial.print(", difference: ");
    Serial.print(difference);

    temp2 = cur_temp2;
  }
}
