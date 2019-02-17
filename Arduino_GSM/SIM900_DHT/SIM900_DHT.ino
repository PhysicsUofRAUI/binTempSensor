#include <DHT.h>
#include <DHT_U.h>

/*
This code was written by SayantanM4
and the full project can be found here: https://www.instructables.com/id/SIM900-GSM-Based-Weather-Notifier/
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
#include<DHT.h>

#define DHTPIN1            5

#define DHTTYPE           DHT22

DHT_Unified dht1(DHTPIN1, DHTTYPE);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  mySerial.println("AT+CNMI=2,2,0,0,0");
  delay(100);
  
  dht1.begin();

  sensor_t sensor;
}

void loop()
{
  sensors_event_t event1;
  dht1.temperature().getEvent(&event1);
  
  // float humidity = event1.humidity;
  float temperature = event1.temperature;
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+XXxxxxxxxxxx\"\r"); // Replace x with mobile number X with countryCode
  delay(1000);
  mySerial.println("I am SMS from GSM Module\n");// The SMS text you want to send
  mySerial.println("The current temperature is:"+String(temperature)+"*C");
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(60000);
}
