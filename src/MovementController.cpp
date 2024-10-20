#include "MovementController.hpp"

MovementController::MovementController() : R_A(PinName::p10),
                                           R_B(PinName::p11),
                                           L_A(PinName::p13),
                                           L_B(PinName::p12)

{
}

static inline void set_pair_pwm(mbed::PwmOut &a, mbed::PwmOut &b, float value)
{
    value *= .2;
    if (value > 0)
    {
        a.write(value);
        b.write(0);
        return;
    }
    if (value < 0)
    {
        a.write(0);
        b.write(-value);
        return;
    }
    a.write(0);
    b.write(0);
}

void MovementController::forward()
{
    set_pair_pwm(R_A, R_B, 1);
    set_pair_pwm(L_A, L_B, 1);
}

void MovementController::backward()
{
    set_pair_pwm(R_A, R_B, -1);
    set_pair_pwm(L_A, L_B, -1);
}

void MovementController::right()
{
    set_pair_pwm(R_A, R_B, -1);
    set_pair_pwm(L_A, L_B, 1);
}

void MovementController::left()
{
    set_pair_pwm(R_A, R_B, 1);
    set_pair_pwm(L_A, L_B, -1);
}

void MovementController::stop()
{
    set_pair_pwm(R_A, R_B, 0);
    set_pair_pwm(L_A, L_B, 0);
}
