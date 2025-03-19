#include "clock.h"

void clockType::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

void clockType::printTime() const
{
    std::cout << std::setfill('0');
    std::cout << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec << std::endl;
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementHours()
{
    hr++;
    if (hr > 23)
    {
        hr = 0;
    }
}

bool clockType::equalTime(const clockType &otherClock) const
{
    return otherClock.hr == hr && otherClock.min == min && otherClock.sec == sec;
}

int clockType::getHour() const
{

    return hr;
}
int clockType::getMinute() const
{
    return min;
}

int clockType::getSecond() const
{
    return sec;
}

void clockType::setHour(int h)
{
    hr = h;
    if (!validHr())
    {
        std::cout << "Hours must be between 0 and 23." << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        hr = 0;
    }
}

void clockType::setMinute(int m)
{
    min = m;
    if (!validMin())
    {
        std::cout << "Minutes must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        min = 0;
    }
}

void clockType::setSecond(int s)
{

    sec = s;
    if (!validSec())
    {
        std::cout << "Seconds must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        sec = 0;
    }
}

clockType::clockType(int h, int m, int s) : hr{h}, min{m}, sec{s}
{
    if (!validHr())
    {
        std::cout << "Hours must be between 0 and 23." << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        hr = 0;
    }
    if (!validMin())
    {
        std::cout << "Minutes must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        min = 0;
    }
    if (!validSec())
    {
        std::cout << "Seconds must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        sec = 0;
    }
    // setTime(h, m, s);
}

bool clockType::validHr() const
{
    return hr >= 0 && hr <= 23; //&& sec >= 0 && sec <= 59 && min >= 0 && min <= 59;
}

bool clockType::validMin() const
{
    return min >= 0 && min <= 59;
}

bool clockType::validSec() const
{
    return sec >= 0 && sec <= 59;
}