// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[]      = "952e3ad9-ef0f-46b0-aa63-a71ab33f7a11";

const char GPRS_APN[]      = "";
const char PINNUMBER[]     = "";
const char GPRS_LOGIN[]    = "";
const char GPRS_PASSWORD[] = "";


float one_top;
float one_bottom;
float one_middle;
float pcb_temp;
float two_middle;
float two_top;
float two_bottom;
float three_top;
float three_middle;
float four_bottom;
float three_bottom;
float four_top;
float four_middle;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(one_top, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(one_bottom, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(one_middle, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(pcb_temp, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(two_middle, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(two_top, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(two_bottom, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(three_top, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(three_middle, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(four_bottom, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(three_bottom, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(four_top, READ, 900 * SECONDS, NULL);
  ArduinoCloud.addProperty(four_middle, READ, 900 * SECONDS, NULL);

}

GSMConnectionHandler ArduinoIoTPreferredConnection(PINNUMBER, GPRS_APN, GPRS_LOGIN, GPRS_PASSWORD);