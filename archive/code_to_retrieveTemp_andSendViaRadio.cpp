/*
By: Kody Rogers
Date: 15/8/2018

Purpose: This block of code was written to transmitt code to a Raspberry Pi
in connection with the development of a system to monitor grain temperature
in a bin.

Documentation: Some extra Documentation

      The library being used to send the messages
          http://www.airspayce.com/mikem/arduino/RadioHead/index.html

*/
#include <Adafruit_MLX90614.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// final temperature to be sent to the raspberry pi
float sensor_one;
float sensor_two;
float sensor_three;

// temp value to collect the different averages
float temp = 0;

// store the sum of five values
float sum;

/*
Sets
 	speed = 2000,
	reciever pin = 11,
  transmitter pin = 12,

  Next two are to now whether to transmitt or not
	pttPin = 10,
 	pttInverted = false
*/
RH_ASK driver(2000, 2, 12, 11);

void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT);

  // Set pin 11 to high so we will always transmitt
  digitalWrite(11, HIGH)

  if (!driver.init()){
    Serial.println("init failed");
  }
}

/*
This function is meant to attain a good reading of the temperature then
return it.

issues: This code needs some way to specify what sensor which we will be extracting the
temperature from.

Variables:
  sensor_number : this will be used to select which sensor. Right
    there is no way to do this. See issue #7
*/
float getData(int sensor_number) {
  for(int i = 0;i < 5;i++){
    temp = mlx.readObjectTempC();

    sum = sum + temp;

    delay(100);
  }

  return sum / 5;
}
void loop() {
  /*
  this code should not work yet. There needs to be a way to choose which sensor will
  be read from.


  It is intended to read code from three temperature sensors and then send it as
  a radio signal.
  */

  sensor_one = getData(1);
  driver.send((uint8_t *)sensor_one, strlen(sensor_one));
  driver.waitPacketSent();

  // sensor_two = "hello";
  sensor_two = getData(2);
  driver.send((uint8_t *)sensor_two, strlen(sensor_two));
  driver.waitPacketSent();

  //sensor_three = "hello";
  sensor_three = getData(3);
  driver.send((uint8_t *)sensor_three, strlen(sensor_three));
  driver.waitPacketSent();

  delay(1000);
}
