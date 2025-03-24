#include <iostream>
#include <limits>
#include <string>
#include "clock.h"

int main()
{
    clockType myClock;
    myClock.printTime();
    myClock.setTime(2, 2, 2);
    myClock.printTime();
    // hello
    return 0;
}