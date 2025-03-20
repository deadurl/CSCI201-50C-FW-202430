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
    clockType myClock(TWENTYFOUR, 53, 3, 3);
    clockType yourClock(TWELVE, 0, 0, 0, PM);
    std::cout << x << std::endl;
    std::cout << myClock.tostring() << std::endl;
    myClock.setTime(0, 0, 0);
    std::cout << myClock.tostring() << std::endl;
    if (myClock.equalTime(yourClock))
    {
        std::cout << "The clocks are the same" << std::endl;
    }
    std::cout << yourClock.tostring() << std::endl;
    yourClock = myClock;
    std::cout << yourClock.tostring() << std::endl;
    for (int i = 0; i < 120; i++)
    {
        yourClock = clockTick();
        std::cout << yourClock.tostring() << std::endl;
    }
    // clockType allClocks[45];
    return 0;
}

clockType clockTick()
{
    static clockType theClock(TWENTYFOUR);
    theClock.incrementSeconds();
    return theClock;
}
