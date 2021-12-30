// OneWire - Version: Latest
#include <OneWire.h>
#include <DallasTemperature.h>

// On board Sensor
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

#define DHTPIN  A5

#define DHTTYPE DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

/*
  Sketch generated by the Arduino IoT Cloud Thing "DS018s_temp_test"
  https://create.arduino.cc/cloud/things/952e3ad9-ef0f-46b0-aa63-a71ab33f7a11

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float top;
  float middle;
  float bottom;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

#define BIN_ONE_ONE_WIRE_BUS 1
#define BIN_TWO_ONE_WIRE_BUS 2
#define BIN_THREE_ONE_WIRE_BUS 3
#define BIN_FOUR_ONE_WIRE_BUS 4

#define TEMPERATURE_PRECISION 9

// Bin One
OneWire binOneOneWire(BIN_ONE_ONE_WIRE_BUS);

DallasTemperature binOneSensors(&binOneOneWire);

DeviceAddress one_top_address = { place your addresses in this area };
DeviceAddress one_middle_top_address = {  };
DeviceAddress one_middle_bottom_address = {  };
DeviceAddress one_bottom_address = {  };

// Bin Two
OneWire binTwoOneWire(BIN_TWO_ONE_WIRE_BUS);

DallasTemperature binTwoSensors(&binTwoOneWire);

DeviceAddress two_top_address = {  };
DeviceAddress two_middle_top_address = {  };
DeviceAddress two_middle_bottom_address = {  };
DeviceAddress two_bottom_address = {  };

// Bin Three
OneWire binThreeOneWire(BIN_THREE_ONE_WIRE_BUS);

DallasTemperature binThreeSensors(&binThreeOneWire);

DeviceAddress three_top_address = {  };
DeviceAddress three_middle_top_address = {  };
DeviceAddress three_middle_bottom_address = {  };
DeviceAddress three_bottom_address = {  };

// Bin Four
OneWire binFourOneWire(BIN_FOUR_ONE_WIRE_BUS);

DallasTemperature binFourSensors(&binFourOneWire);

DeviceAddress four_top_address = {  };
DeviceAddress four_middle_top_address = {  };
DeviceAddress four_middle_bottom_address = {  };
DeviceAddress four_bottom_address = {  };

unsigned long last_time;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // get the onboard sensor ready
  dht.begin();

  sensor_t sensor;

  /*
    Getting Bin One's Sensors Ready
  */
  binOneSensors.begin();

  binOneSensors.setResolution(one_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binOneSensors.setResolution(one_middle_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binOneSensors.setResolution(one_middle_bottom_address, TEMPERATURE_PRECISION);
  delay(500);
  binOneSensors.setResolution(one_bottom_address, TEMPERATURE_PRECISION);

  /*
    Getting Bin Two's Sensors Ready
  */
  binTwoSensors.begin();

  binTwoSensors.setResolution(two_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binTwoSensors.setResolution(two_middle_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binTwoSensors.setResolution(two_middle_bottom_address, TEMPERATURE_PRECISION);
  delay(500);
  binTwoSensors.setResolution(two_bottom_address, TEMPERATURE_PRECISION);

  /*
    Getting Bin Three's Sensors Ready
  */
  binThreeSensors.begin();

  binThreeSensors.setResolution(three_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binThreeSensors.setResolution(three_middle_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binThreeSensors.setResolution(three_middle_bottom_address, TEMPERATURE_PRECISION);
  delay(500);
  binThreeSensors.setResolution(three_bottom_address, TEMPERATURE_PRECISION);

  /*
    Getting Bin Four's Sensors Ready
  */
  binFourSensors.begin();

  binFourSensors.setResolution(four_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binFourSensors.setResolution(four_middle_top_address, TEMPERATURE_PRECISION);
  delay(500);
  binFourSensors.setResolution(four_middle_bottom_address, TEMPERATURE_PRECISION);
  delay(500);
  binFourSensors.setResolution(four_bottom_address, TEMPERATURE_PRECISION);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::CONNECT, doThisOnConnect);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();

  last_time = millis();
}

void loop() {
  ArduinoCloud.update();
  // Your code here

  if (millis() - last_time > 600000)
  {
    // Get temperature from the pcb
    sensors_event_t event;
    dht.temperature().getEvent(&event);

    if (isnan(event.temperature)) {
      pcb_temp = -100.0;
    }
    else {
      pcb_temp = event.temperature;
    }

    /*
      Get Bin One Temperatures
    */
    binOneSensors.requestTemperatures();
    one_top = binOneSensors.getTempC(one_top_address);
    if (one_top == DEVICE_DISCONNECTED_C)
    {
      one_top = -100;
      Serial.println("Error");

    }
    one_middle_top = binOneSensors.getTempC(one_middle_top_address);
    if (one_middle_top == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      one_middle_top = -100;
    }
    one_middle_bottom = binOneSensors.getTempC(one_middle_bottom_address);
    if (one_middle_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      one_middle_bottom = -100;
    }
    one_bottom = binOneSensors.getTempC(one_bottom_address);
    if (one_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      one_bottom = -100;
    }

    /*
      Get Bin Two Temperatures
    */
    binTwoSensors.requestTemperatures();
    two_top = binTwoSensors.getTempC(two_top_address);
    if (two_top == DEVICE_DISCONNECTED_C)
    {
      two_top = -100;
      Serial.println("Error");

    }
    two_middle_top = binTwoSensors.getTempC(two_middle_top_address);
    if (two_middle_top == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      two_middle_top = -100;
    }
    two_middle_bottom = binTwoSensors.getTempC(two_middle_bottom_address);
    if (two_middle_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      two_middle_bottom = -100;
    }
    two_bottom = binTwoSensors.getTempC(two_bottom_address);
    if (two_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      two_bottom = -100;
    }

    /*
      Get Bin Three Temperatures
    */
    binThreeSensors.requestTemperatures();
    three_top = binThreeSensors.getTempC(three_top_address);
    if (three_top == DEVICE_DISCONNECTED_C)
    {
      three_top = -100;
      Serial.println("Error");

    }
    three_middle_top = binThreeSensors.getTempC(three_middle_top_address);
    if (three_middle_top == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      three_middle_top = -100;
    }
    three_middle_bottom = binThreeSensors.getTempC(three_middle_bottom_address);
    if (three_middle_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      three_middle_bottom = -100;
    }
    three_bottom = binThreeSensors.getTempC(three_bottom_address);
    if (three_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      three_bottom = -100;
    }

    /*
      Get Bin Four Temperatures
    */
    binFourSensors.requestTemperatures();
    four_top = binFourSensors.getTempC(four_top_address);
    if (four_top == DEVICE_DISCONNECTED_C)
    {
      four_top = -100;
      Serial.println("Error");

    }
    four_middle_top = binFourSensors.getTempC(four_middle_top_address);
    if (four_middle_top == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      four_middle_top = -100;
    }
    four_middle_bottom = binFourSensors.getTempC(four_middle_bottom_address);
    if (four_middle_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      four_middle_bottom = -100;
    }
    four_bottom = binFourSensors.getTempC(four_bottom_address);
    if (four_bottom == DEVICE_DISCONNECTED_C)
    {
      Serial.println("Error");
      four_bottom = -100;
    }

    last_time = millis();
  }
}

// collect all data once on connect
// so that zeros do not appear across the
// board
void doThisOnConnect(){
  // Get temperature from the pcb
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  if (isnan(event.temperature)) {
    pcb_temp = -100.0;
  }
  else {
    pcb_temp = event.temperature;
  }

  /*
    Get Bin One Temperatures
  */
  binOneSensors.requestTemperatures();
  one_top = binOneSensors.getTempC(one_top_address);
  if (one_top == DEVICE_DISCONNECTED_C)
  {
    one_top = -100;
    Serial.println("Error");

  }
  one_middle_top = binOneSensors.getTempC(one_middle_top_address);
  if (one_middle_top == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    one_middle_top = -100;
  }
  one_middle_bottom = binOneSensors.getTempC(one_middle_bottom_address);
  if (one_middle_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    one_middle_bottom = -100;
  }
  one_bottom = binOneSensors.getTempC(one_bottom_address);
  if (one_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    one_bottom = -100;
  }

  /*
    Get Bin Two Temperatures
  */
  binTwoSensors.requestTemperatures();
  two_top = binTwoSensors.getTempC(two_top_address);
  if (two_top == DEVICE_DISCONNECTED_C)
  {
    two_top = -100;
    Serial.println("Error");

  }
  two_middle_top = binTwoSensors.getTempC(two_middle_top_address);
  if (two_middle_top == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    two_middle_top = -100;
  }
  two_middle_bottom = binTwoSensors.getTempC(two_middle_bottom_address);
  if (two_middle_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    two_middle_bottom = -100;
  }
  two_bottom = binTwoSensors.getTempC(two_bottom_address);
  if (two_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    two_bottom = -100;
  }

  /*
    Get Bin Three Temperatures
  */
  binThreeSensors.requestTemperatures();
  three_top = binThreeSensors.getTempC(three_top_address);
  if (three_top == DEVICE_DISCONNECTED_C)
  {
    three_top = -100;
    Serial.println("Error");

  }
  three_middle_top = binThreeSensors.getTempC(three_middle_top_address);
  if (three_middle_top == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    three_middle_top = -100;
  }
  three_middle_bottom = binThreeSensors.getTempC(three_middle_bottom_address);
  if (three_middle_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    three_middle_bottom = -100;
  }
  three_bottom = binThreeSensors.getTempC(three_bottom_address);
  if (three_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    three_bottom = -100;
  }

  /*
    Get Bin Four Temperatures
  */
  binFourSensors.requestTemperatures();
  four_top = binFourSensors.getTempC(four_top_address);
  if (four_top == DEVICE_DISCONNECTED_C)
  {
    four_top = -100;
    Serial.println("Error");

  }
  four_middle_top = binFourSensors.getTempC(four_middle_top_address);
  if (four_middle_top == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    four_middle_top = -100;
  }
  four_middle_bottom = binFourSensors.getTempC(four_middle_bottom_address);
  if (four_middle_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    four_middle_bottom = -100;
  }
  four_bottom = binFourSensors.getTempC(four_bottom_address);
  if (four_bottom == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error");
    four_bottom = -100;
  }

  last_time = millis();
}
