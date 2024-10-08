//
// Created by Elmo Erla on 7.10.2024.
//
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

class Time {
    friend std::ostream& operator<<(std::ostream& out, const Time& t);
    friend std::istream& operator>>(std::istream& in, Time& t);

public:
    explicit Time(int h = 0, int m = 0);

    bool operator>(const Time& t) const;
    bool operator==(const Time& t) const;

    [[nodiscard]] bool lessThan(const Time& t) const;
    [[nodiscard]] Time subtract(const Time& t) const;
    void display() const;
    int get_hour() const;
    void set_hour(int hour);

private:
    int hour;
    int min;
};

#endif