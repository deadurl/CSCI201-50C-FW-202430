#include <iostream>
#include <limits>
#include <string>
#include "clock.h"

clockType clockTick();
bool codeGradeLoopFix();
int main()
{
    int x = 0;
    timeType t = timeType::TWELVE;
    std::cout << "How many clocks? ";
    std::cin >> x;
    if (codeGradeLoopFix())
        return 0;
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

    std::string format;
    std::cout << "Would you like a 12 hour clock or a 24 hour clock? " << std::endl;
    std::cin >> std::ws;
    getline(std::cin, format);
    if (codeGradeLoopFix())
    {
        return 0;
    }
    return 0;
}

clockType clockTick()
{
    static clockType theClock(TWENTYFOUR);
    theClock.incrementSeconds();
    return theClock;
}

bool codeGradeLoopFix()
{
    if (std::cin.eof())
    {
        std::cout << "Infinite loop detected. Out of input ending program." << std::endl;
        return true;
    }
    return false;
}
