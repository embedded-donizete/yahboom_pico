#include <Arduino.h>
#include "MovementController.hpp"

MovementController movementController;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hello World");
  movementController.forward();
}