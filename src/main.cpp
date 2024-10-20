#include <Arduino.h>
#include "MovementController.hpp"
#include "IRController.hpp"

MovementController movementController;
IRController irController;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  IRController::Value value = irController.getValue();
  switch (value)
  {
  case IRController::Value::Right:
    movementController.right();
    break;
  case IRController::Value::Left:
    movementController.left();
    break;
  case IRController::Value::Up:
    movementController.forward();
    break;
  case IRController::Value::Down:
    movementController.backward();
    break;
  case IRController::Value::None:
    movementController.stop();
    break;
  }
}