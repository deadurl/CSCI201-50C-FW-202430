#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

enum timeType
{
    TWELVE = 12,
    TWENTYFOUR = 24
};
enum partType
{
    AM,
    PM
};

class clockType
{
public:
    clockType(int = 0, int = 0, int = 0);

    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    // void printTime() const;
    std::string tostring() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    void invalidHour();
    bool equalTime(const clockType &) const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    bool validHr() const;
    bool validMin() const;
    bool validSec() const;

    static timeType formats[2];
    static partType parts[2];
    static std::string formatToStr[2];
    static std::string partToStr[2];

private:
    int hr;
    int min;
    int sec;
};

class twelveHrClock : public clockType
{
public:
    twelveHrClock(int h, int m, int s, partType part);
    bool validHr() const;
    // void setHour(int h);
    void invalidHour();
    std::string tostring() const;

private:
    partType partOfDay;
};
#endif