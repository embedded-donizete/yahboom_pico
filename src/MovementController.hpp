#include <PwmOut.h>

class MovementController
{
public:
    MovementController();
    void forward();
    void backward();
    void right();
    void left();
    void stop();

private:
    mbed::PwmOut R_A;
    mbed::PwmOut R_B;
    mbed::PwmOut L_A;
    mbed::PwmOut L_B;
};