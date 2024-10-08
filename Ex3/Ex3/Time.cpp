//
// Created by Elmo Erla on 7.10.2024.
//
#include "Time.h"
#include <iostream>
#include <iomanip>

Time::Time(int h, int m) : hour(h), min(m) {}

std::istream& operator>>(std::istream& in, Time& t) {
    char colon;
    in >> t.hour >> colon >> t.min;
    if (colon != ':' || t.hour < 0 || t.hour > 23 || t.min < 0 || t.min > 59) {
        in.setstate(std::ios::failbit);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << std::setw(2) << std::setfill('0') << t.hour << ":"
        << std::setw(2) << std::setfill('0') << t.min;
    return out;
}

bool Time::operator>(const Time& t) const {
    return (hour > t.hour) || (hour == t.hour && min > t.min);
}

bool Time::operator==(const Time& t) const {
    return (hour == t.hour && min == t.min);
}

bool Time::lessThan(const Time& t) const {
    return (hour < t.hour) || (hour == t.hour && min < t.min);
}

Time Time::subtract(const Time& t) const {
    int totalMin1 = hour * 60 + min;
    int totalMin2 = t.hour * 60 + t.min;
    int diff = totalMin1 - totalMin2;

    if (diff < 0) {
        diff += 24 * 60;
    }

    return Time(diff / 60, diff % 60);
}

void Time::display() const {
    std::cout << std::setw(2) << std::setfill('0') << hour << ":"
              << std::setw(2) << std::setfill('0') << min << std::endl;
}

int Time::get_hour() const {
    return hour;
}

void Time::set_hour(int h) {
    hour = h;
}
