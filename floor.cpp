#include "floor.h"

Floor::Floor()
{
    hole.push_back(600);
    hole.push_back(1200);
    hole.push_back(1800);
    hole.push_back(3000);
    hole.push_back(5500);
    hole.push_back(0);

    int i=0,count=0;
    while(i<8000)
    {
        if(i==hole[count])
        {
            i+=50;
            count++;
        }
        else
        {
            x.push_back(i);
        }
        i+=50;
    }
}
