#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

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
    clockType(int, int, int);

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

protected:
    int hr;
    int min;
    int sec;
};

class twelveHrClock : public clockType
{
public:
    twelveHrClock(int h, int m, int s, partType part);
    bool validHr() const;
    void setHour(int h);
    void invalidHour();
    std::string tostring() const;
    std::string getPartOfDay() const;
    void setPartOfDay(std::string);
    void setTime(int, int, int);
    void setTime(int, int, int, partType);

private:
    partType partOfDay;
};
#endif