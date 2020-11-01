// Include all the needed libraries
#include <MKRGSM.h>
#include <bin_sensor.hpp>

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

float result = 0.0;


BinSensor bin_sensor((float)0.5);

void setup() {
  // put your setup code here, to run once:
  dht1.begin();
  

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

  sms.beginSMS("your-phone-number");
  sms.print("Connected!");
  sms.endSMS();
}

void loop() {
  // put your main code here, to run repeatedly:

  result = bin_sensor.check_sensor(dht1);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("temperature 1 has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  // wait for 12 hours
  delay(43200000);
}
