#include "IRController.hpp"

IRController::IRController() : ir(PinName::p7)
{
}

IRController::Value IRController::getValue()
{
    uint8_t data = this->ir.GetIR();
    return IRController::Value(data);
}
