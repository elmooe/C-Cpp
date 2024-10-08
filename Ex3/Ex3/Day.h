#pragma once
#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "Time.h"

class Day {
public:
    Day();

    bool from_str(const std::string &s);
    std::string to_str() const;
    void dst(int offset);

private:
    int day;
    std::string month;
    std::vector<Time> list;
};

#endif  // DAY_H_INCLUDED