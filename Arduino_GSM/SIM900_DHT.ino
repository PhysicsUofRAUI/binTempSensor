/*
This code was written by SayantanM4
and the full project can be found here: https://www.instructables.com/id/SIM900-GSM-Based-Weather-Notifier/
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
#include<DHT.h>
DHT dht;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  mySerial.println("AT+CNMI=2,2,0,0,0");
  delay(100);
  dht.setup(4);
}

void loop()
{
   float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+XXxxxxxxxxxx\"\r"); // Replace x with mobile number X with countryCode
  delay(1000);
  mySerial.println("I am SMS from GSM Module\n");// The SMS text you want to send
  mySerial.println("The current temperature is:"+String(temperature)+"*C"+"the humidity is:"+String(humidity)+"%");
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(60000);
}
