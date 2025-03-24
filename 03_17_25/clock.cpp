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
    if (h >= 0 && h <= 23)
    {
        hr = h;
    }
    else
    {
        std::cout << "Hours must be between 0 and 23." << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        hr = 0;
    }
}

void clockType::setMinute(int m)
{
    if (m >= 0 && m <= 59)
    {
        min = m;
    }
    else
    {
        std::cout << "Minutes must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        min = 0;
    }
}

void clockType::setSecond(int s)
{
    if (s >= 0 && s <= 59)
    {
        sec = s;
    }
    else
    {
        std::cout << "Seconds must be between 0 and 59" << std::endl;
        std::cout << "Defaulting to 0." << std::endl;
        sec = 0;
    }
}

clockType::clockType(int h, int m, int s)
{
    setTime(h, m, s);
}
