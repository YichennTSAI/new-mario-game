#include "flag.h"

flag::flag()
{
    x=7000;
    y=20;
    move=false;
}
void flag::startmove()
{
    if(move==true&&y<=450)
    {
        pix->move(x,y+10);
        y+=10;
    }
}
