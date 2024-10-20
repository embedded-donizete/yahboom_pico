#include "IR.cpp"

class IRController
{
public:
    IRController();

    enum Value
    {
        None = 0xFE,
        Power = 0,
        Up = 1,
        Light = 2,
        Left = 4,
        Sound = 5,
        Right = 6,
        Turn_Left = 8,
        Down = 9,
        Turn_Right = 10,
        Plus = 12,
        Zero = 13,
        Hyphen = 14,
        One = 16,
        Two = 17,
        Three = 18,
        Four = 20,
        Five = 21,
        Six = 22,
        Seven = 24,
        Eight = 25,
        Nine = 26
    };

    Value getValue();

private:
    IR ir;
};