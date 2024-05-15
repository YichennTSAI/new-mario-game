#include "mario.h"

mario::mario()
{
    state=1;  //1 小,2 大,3 火球.
    xsize=(state>1)?56:50;
    ysize=(state>1)?80:50;  //以state決定

    x=0;
    y=520-ysize;

    life=2;   //最多3條
    die=false;
    walk=(state>1)?2:1;   //單位長度
    height=(state>1)?160:70; //跳躍高度
    direction=2;  //1 左邊,2 右邊
    swift=0;      //0 站,1 圖1,2 圖2,3 跳起來
    yspeed=0;
    score=0;
    bul=0;

    canmoveright=false;
    canmoveleft=false;
    canjump=true;
    open=false;
    jumping=false;
    inhole=false;
}

bool mario::atmid()
{
    if(x>=600)
        return true;
    else
        return false;
}

void mario::moveright()
{
    direction=2;
    if(canmoveright&&x<1390-xsize)
    {
        pix->move(pix->x()+1,pix->y());
        x+=1;
    }
}
void mario::moveleft()
{
    direction=1;
    if(canmoveleft&&x>0)
    {
        pix->move(pix->x()-1,pix->y());
        x-=1;
    }
}

void mario::jump()
{
    if(!canjump)
    {
        pix->move(pix->x(),pix->y()+yspeed);
        y+=yspeed;
        yspeed+=4;
    }

}
