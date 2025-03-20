#include <iostream>
#include <limits>
#include <string>
#include "clock.h"
clockType clockTick();
int main()
{
    int x = 0;
    timeType t = timeType::TWELVE;
    if (t == timeType::TWELVE)
    {
        std::cout << "huzzah" << std::endl;
    }
    clockType myClock(53, 3, 3);
    clockType yourClock(0, 0, 0);
    std::cout << x << std::endl;
    myClock.printTime();
    myClock.setTime(2, 2, 2);
    myClock.printTime();
    myClock.equalTime(yourClock);
    yourClock.printTime();
    yourClock = myClock;
    yourClock.printTime();
    for (int i = 0; i < 120; i++)
    {
        yourClock = clockTick();
        yourClock.printTime();
    }
    clockType allClocks[45];
    return 0;
}

clockType clockTick()
{
    static clockType theClock;
    theClock.incrementSeconds();
    return theClock;
}
