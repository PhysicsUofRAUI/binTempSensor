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
// bin one
#define DHTPIN1            0
#define DHTPIN2            1
#define DHTPIN3            2

// bin two
#define DHTPIN4            3
#define DHTPIN5            4
#define DHTPIN6            5

// bin three
#define DHTPIN7            6
#define DHTPIN8            7
#define DHTPIN9            8

#define DHTTYPE           DHT22

// bin one
DHT_Unified dht1(DHTPIN1, DHTTYPE);
DHT_Unified dht2(DHTPIN2, DHTTYPE);
DHT_Unified dht3(DHTPIN3, DHTTYPE);

// bin two
DHT_Unified dht4(DHTPIN4, DHTTYPE);
DHT_Unified dht5(DHTPIN5, DHTTYPE);
DHT_Unified dht6(DHTPIN6, DHTTYPE);


// bin three
DHT_Unified dht7(DHTPIN7, DHTTYPE);
DHT_Unified dht8(DHTPIN8, DHTTYPE);
DHT_Unified dht9(DHTPIN9, DHTTYPE);

float result = 0.0;


// bin one
BinSensor bin_sensor1((float)0.5);
BinSensor bin_sensor2((float)0.5);
BinSensor bin_sensor3((float)0.5);

// bin two
BinSensor bin_sensor4((float)0.5);
BinSensor bin_sensor5((float)0.5);
BinSensor bin_sensor6((float)0.5);

// bin three
BinSensor bin_sensor7((float)0.5);
BinSensor bin_sensor8((float)0.5);
BinSensor bin_sensor9((float)0.5);

void setup() {
  // put your setup code here, to run once:
  dht1.begin();
  dht2.begin();
  dht3.begin();

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

  /*
   * Check the sensors in the first bin
   */

  result = bin_sensor1.check_sensor(dht1);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Top of bin one has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  result = bin_sensor2.check_sensor(dht2);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Middle of bin one has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  result = bin_sensor3.check_sensor(dht3);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Bottom of bin one has increased by ");
    sms.print(result);
    sms.endSMS();
  }


  /*
   * Check the sensors in the second bin
   */
   result = bin_sensor4.check_sensor(dht4);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Top of bin two has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  result = bin_sensor5.check_sensor(dht5);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Middle of bin two has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  result = bin_sensor6.check_sensor(dht6);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Bottom of bin two has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  /*
   * Check the sensors in the third bin
   */
   result = bin_sensor7.check_sensor(dht7);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Top of bin three has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  result = bin_sensor8.check_sensor(dht8);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Middle of bin three has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  result = bin_sensor9.check_sensor(dht9);

  if (result < 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Sensor Failure");
    sms.endSMS();
  }
  else if (result > 0)
  {
    sms.beginSMS("your-phone-number");
    sms.print("Bottom of bin three has increased by ");
    sms.print(result);
    sms.endSMS();
  }

  // wait for 12 hours
  delay(43200000);
}
