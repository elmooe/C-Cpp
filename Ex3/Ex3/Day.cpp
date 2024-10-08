//
// Created by Elmo Erla on 8.10.2024.
//
#include "Day.h"
#include <sstream>

Day::Day() : day(0), month("") {}

bool Day::from_str(const std::string &s) {
    std::istringstream stream(s);
    list.clear();
    stream >> day >> month;

    if (stream.fail()) {
        return false;
    }

    std::string time_str;
    while (stream >> time_str) {
        std::istringstream time_stream(time_str);
        Time time;
        if (time_stream >> time) {
            list.push_back(time);
        } else {
            break;
        }
    }

    if (list.empty()) {
        return false;
    }

    std::sort(list.begin(), list.end(), [](const Time& t1, const Time& t2) {
        return t2 > t1;
    });

    return true;
}

std::string Day::to_str() const {
    std::ostringstream out;
    out << day << " " << month;
    for (const auto& time : list) {
        out << " " << time;
    }
    return out.str();
}

void Day::dst(int offset) {
    for (auto& time : list) {
        int new_hour = time.get_hour() + offset;
        if (new_hour >= 24) {
            new_hour -= 24;
        } else if (new_hour < 0) {
            new_hour += 24;
        }
        time.set_hour(new_hour);
    }
}