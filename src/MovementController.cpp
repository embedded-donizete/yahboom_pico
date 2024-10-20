#include "MovementController.hpp"

MovementController::MovementController() : R_A(PinName::p10),
                                           R_B(PinName::p11),
                                           L_A(PinName::p12),
                                           L_B(PinName::p13)
{
}

void MovementController::forward()
{
    this->R_A.write(1);
    this->R_B.write(0);

    this->L_A.write(1);
    this->L_B.write(0);
}

void MovementController::backward()
{
    this->R_A.write(0);
    this->R_B.write(1);

    this->L_A.write(0);
    this->L_B.write(1);
}

void MovementController::right()
{
    this->R_A.write(0);
    this->R_B.write(1);

    this->L_A.write(1);
    this->L_B.write(0);
}

void MovementController::left()
{
    this->R_A.write(1);
    this->R_B.write(0);

    this->L_A.write(0);
    this->L_B.write(1);
}

void MovementController::stop()
{
    this->R_A.write(0);
    this->R_B.write(0);

    this->L_A.write(0);
    this->L_B.write(0);
}
