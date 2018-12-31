#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

#define DHTPIN1            2
#define DHTPIN2            4
#define DHTPIN3            7

#define DHTTYPE           DHT22

DHT_Unified dht1(DHTPIN1, DHTTYPE);
DHT_Unified dht2(DHTPIN2, DHTTYPE);
DHT_Unified dht3(DHTPIN3, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht1.begin();
  dht2.begin();
  dht3.begin();

  sensor_t sensor;
}

void loop() {
  // Delay between measurements.
  delay(10000);
  // Get temperature event and print its value.
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);
  if (isnan(event1.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature 1: ");
    Serial.print(event1.temperature);
    Serial.println(" *C");
  }
  // Get humidity event and print its value.
  dht1.humidity().getEvent(&event1);
  if (isnan(event1.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity 1: ");
    Serial.print(event1.relative_humidity);
    Serial.println("%");
  }

  // Get temperature event and print its value.
  sensors_event_t event2;
  dht2.temperature().getEvent(&event2);
  if (isnan(event2.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature 2: ");
    Serial.print(event2.temperature);
    Serial.println(" *C");
  }
  // Get humidity event and print its value.
  dht2.humidity().getEvent(&event2);
  if (isnan(event2.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity 2: ");
    Serial.print(event2.relative_humidity);
    Serial.println("%");
  }

  // Get temperature event and print its value.
  sensors_event_t event3;
  dht3.temperature().getEvent(&event3);
  if (isnan(event3.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature 3: ");
    Serial.print(event3.temperature);
    Serial.println(" *C");
  }
  // Get humidity event and print its value.
  dht3.humidity().getEvent(&event3);
  if (isnan(event3.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity 3: ");
    Serial.print(event3.relative_humidity);
    Serial.println("%");
  }
}
