#include <iostream>
#include <limits>
#include <string>
#include "clock.h"

int main()
{
    int x = 0;
    clockType myClock(53, 3, 3);
    clockType yourClock;
    std::cout << x << std::endl;
    myClock.printTime();
    myClock.setTime(2, 2, 2);
    myClock.printTime();
    myClock.equalTime(yourClock);
    yourClock.printTime();
    yourClock = myClock;
    yourClock.printTime();
    if (true)
    {
        x = 7;
        int y = 12;
    }
    y = 122;

    return 0;
}

void myFunc()
{
    x = 7;
}