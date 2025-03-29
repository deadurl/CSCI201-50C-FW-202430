#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <algorithm>
#include "clock.h"
#include "clockAgain.h"

// lecture activity fill in input validation in makeClock

clockType clockTick();
bool codeGradeLoopFix();
void makeClock();
bool validFormat(std::string format);
void resetStream();
bool validPart(std::string part);

int main()
{
    int x = 0;
    timeType t = timeType::TWELVE;
    twelveHrClock tclock(1, 1, 1, PM);
    std::cout << tclock.tostring() << std::endl;
    tclock.setHour(13);
    std::cout << "How many clocks? ";
    std::cin >> x;
    if (codeGradeLoopFix())
        return 0;
    for (int i = 0; i < x; i++)
    {
        makeClock();
    }
    if (t == timeType::TWELVE)
    {
        std::cout << "huzzah" << std::endl;
    }
    clockType myClock(53, 3, 3);
    clockType yourClock(0, 0, 0);

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
    static clockType theClock(0, 0, 0);
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

void makeClock()
{
    std::string format;
    timeType clockFormat = TWENTYFOUR;
    int hr, min, sec;
    std::string p;
    partType part = PM;
    std::cout << "Would you like a 12 hour clock or a 24 hour clock? " << std::endl;
    std::cin >> std::ws;
    getline(std::cin, format);
    while (!validFormat(format))
    {
        if (codeGradeLoopFix())
        {
            return;
        }
        std::cout << format << " is not a valid clock format." << std::endl;
        std::cout << "Would you like a 12 hour clock or a 24 hour clock? " << std::endl;
        std::cin >> std::ws;
        getline(std::cin, format);
    }
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);
    for (int i = 0; i < 2; i++)
    {
        if (clockType::formatToStr[i] == format)
        {
            clockFormat = clockType::formats[i];
        }
    }
    std::cout << "What is the clock's hour? ";
    std::cin >> hr;
    if (clockFormat == TWENTYFOUR)
    {
        while (!std::cin || hr < 0 || hr > 23)
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter an hour between 0 and 24: ";
            std::cin >> hr;
        }
    }
    else
    {
        while (!std::cin || hr < 1 || hr > 12)
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter an hour between 1 and 12: ";
            std::cin >> hr;
        }
    }
    // added input validation
    std::cout << "What is the clock's minute? ";
    std::cin >> min;
    while (!std::cin ||min < 0 || min > 59)
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter an minute between 0 and 59: ";
            std::cin >> hr;
        }
    
    // added input validation
    std::cout << "What is the clock's second? ";
    std::cin >> sec;
    while (!std::cin ||sec < 0 || sec > 59)
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter a second between 0 and 59: ";
            std::cin >> hr;
        }
    
    // add input validation
    if (clockFormat == TWELVE)
    {
        std::cout << "Is it AM or PM? ";
        std::cin >> p;
        while (!validPart(p))
        {
            if (codeGradeLoopFix())
            {
                return;
            }
            std::cout << part << " is not a valid clock part." << std::endl;
            std::cout << "Is it AM or PM? ";
            std::cin >> p;
            std::transform(p.begin(), p.end(), p.begin(), ::toupper);
            while (!std::cin ||p != "AM" || p != "PM")
            {
            if (codeGradeLoopFix())
            {
                return;
            }
            else if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Is it AM or PM;";
            std::cin >> p;
            }
            
        }
        
        bool valid = false;
        for (int i = 0; i < 2; i++)
        {
            if (p == clockType::partToStr[i])
            {

                part = clockType::parts[i];
            }
        }
        twelveHrClock newClock(hr, min, sec, part);
        std::cout << newClock.tostring() << std::endl;
    }
    else
    {
        clockType newClock(hr, min, sec);
        std::cout << newClock.tostring() << std::endl;
    }
}

bool validFormat(std::string format)
{
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);

    for (int i = 0; i < 2; i++)
    {
        if (clockType::formatToStr[i] == format)
            return true;
    }
    return false;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validPart(std::string part)
{
    std::transform(part.begin(), part.end(), part.begin(), ::toupper);

    for (int i = 0; i < 2; i++)
    {
        if (part == clockType::partToStr[i])
        {
            return true;
        }
    }
    return false;
}
