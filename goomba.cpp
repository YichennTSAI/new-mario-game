#include "goomba.h"

goomba::goomba()
{
        x.push_back(500);
        x.push_back(1350);
        x.push_back(2600);
        x.push_back(4600);
        x.push_back(6100);

        y.push_back(470);
        y.push_back(470);
        y.push_back(470);
        y.push_back(470);
        y.push_back(470);

        state.push_back(1);
        state.push_back(1);
        state.push_back(1);
        state.push_back(1);
        state.push_back(1);

        leftside.push_back(0);
        leftside.push_back(1350);
        leftside.push_back(2600);
        leftside.push_back(4600);
        leftside.push_back(6100);

        rightside.push_back(550);
        rightside.push_back(1450);
        rightside.push_back(2950);
        rightside.push_back(4950);
        rightside.push_back(6200);

        move.push_back(10);
        move.push_back(10);
        move.push_back(10);
        move.push_back(10);
        move.push_back(10);

        direction.push_back(2);
        direction.push_back(2);
        direction.push_back(2);
        direction.push_back(2);
        direction.push_back(2);
}

