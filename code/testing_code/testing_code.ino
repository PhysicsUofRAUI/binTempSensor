// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

/*
 * This code is a slightly edited version of the example 'multiple' made to explain the dallas temperature 
 * library and can be found here: https://github.com/milesburton/Arduino-Temperature-Control-Library/tree/master/examples/Multiple
 */

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
#define TEMPERATURE_PRECISION 9

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// Assign address manually. The addresses below will need to be changed
// to valid device addresses on your bus. Device address can be retrieved
// by using either oneWire.search(deviceAddress) or individually via
// sensors.getAddress(deviceAddress, index)
DeviceAddress top = { 0x28, 0x63, 0x38, 0xF3, 0x4C, 0x20, 0x01, 0xD2 };
DeviceAddress middle_top = {  };
DeviceAddress middle_bottom = {  };
DeviceAddress bottom = {  };

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

  
  // show the addresses we found on the bus
  Serial.print("Top Device Address: ");
  printAddress(top);
  Serial.println();

  Serial.print("Middle Top Address: ");
  printAddress(middle_top);
  Serial.println();

  Serial.print("Middle Bottom Device Address: ");
  printAddress(middle_bottom);
  Serial.println();

  Serial.print("Bottom Address: ");
  printAddress(bottom);
  Serial.println();

  // set the resolution to 9 bit per device
  sensors.setResolution(top, TEMPERATURE_PRECISION);
  sensors.setResolution(middle_top, TEMPERATURE_PRECISION);
  sensors.setResolution(middle_bottom, TEMPERATURE_PRECISION);
  sensors.setResolution(bottom, TEMPERATURE_PRECISION);

  Serial.print("Top Device Resolution: ");
  Serial.print(sensors.getResolution(top), DEC);
  Serial.println();

  Serial.print("Middle Top Device Resolution: ");
  Serial.print(sensors.getResolution(middle_top), DEC);
  Serial.println();

  Serial.print("Middle Bottom Device Resolution: ");
  Serial.print(sensors.getResolution(middle_bottom), DEC);
  Serial.println();

  Serial.print("Bottom Device Resolution: ");
  Serial.print(sensors.getResolution(bottom), DEC);
  Serial.println();
}

// function to print a device address
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if(tempC == DEVICE_DISCONNECTED_C) 
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" Temp F: ");
  Serial.print(DallasTemperature::toFahrenheit(tempC));
}

// function to print a device's resolution
void printResolution(DeviceAddress deviceAddress)
{
  Serial.print("Resolution: ");
  Serial.print(sensors.getResolution(deviceAddress));
  Serial.println();
}

// main function to print information about a device
void printData(DeviceAddress deviceAddress)
{
  Serial.print("Device Address: ");
  printAddress(deviceAddress);
  Serial.print(" ");
  printTemperature(deviceAddress);
  Serial.println();
}

/*
   Main function, calls the temperatures in a loop.
*/
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");

  // print the device information
  Serial.println("Top");
  printData(top);

  Serial.println("Middle Top");
  printData(middle_top);

  Serial.println("Middle Bottom");
  printData(middle_bottom);

  Serial.println("Bottom");
  printData(bottom);

  delay(15000);
}
