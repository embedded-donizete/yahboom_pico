#include <Arduino.h>
#include <PwmOut.h>

mbed::PwmOut R_A(PinName::p10);
mbed::PwmOut R_B(PinName::p11);

mbed::PwmOut L_A(PinName::p12);
mbed::PwmOut L_B(PinName::p13);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hello World");
  R_B.write(1);
  delay(1000);
  R_B.write(0);
  delay(1000);

  R_A.write(1);
  delay(1000);
  R_A.write(0);
  delay(1000);
}