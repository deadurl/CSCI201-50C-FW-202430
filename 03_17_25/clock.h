#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <iomanip>

class clockType
{
public:
    clockType(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

private:
    int hr;
    int min;
    int sec;
};
#endif