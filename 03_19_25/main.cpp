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

    return 0;
}