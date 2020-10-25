#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup() {
  Serial.begin(9600);

  if (!driver.init())
  {
    Serial.println("init failed");
  }

}

void loop() {
  uint8_t buf[12];

  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen))
  {
    Serial.println("Hello");
    int i;

    Serial.print("Message: ");

    Serial.println((char*)buf);
  }

}
