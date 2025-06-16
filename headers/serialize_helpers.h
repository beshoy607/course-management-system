#pragma once
#include "COURSE.h"
#include <sstream>
#include <vector>
#include <stdexcept>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

std::string courseToLine(const Course& c) {
    std::string s = c.getCourseCode() + "," + c.getCourseName() + "," +
        c.getInstructor() + "," + std::to_string(c.getCreditHours()) + "," +
        std::to_string(c.getCapacity());

    std::string schedule[2];
    int numSchedules = 0;
    c.getSchedule(schedule, numSchedules);
    s += "," + std::to_string(numSchedules);
    for (int i = 0; i < numSchedules; ++i) {
        s += "|" + schedule[i];
    }
    return s;
}

Course parseCourseLine(const std::string& line) {
    std::vector<std::string> parts = split(line, ',');
    if (parts.size() < 6) {
        throw std::invalid_argument("Invalid course line format");
    }

    std::vector<std::string> sched = split(parts[5], '|');
    if (sched.size() > 2) {
        throw std::invalid_argument("Too many schedules provided");
    }

    std::string sched_array[2] = { "", "" };
    for (size_t i = 0; i < sched.size(); ++i) {
        sched_array[i] = sched[i];
    }

    Course c(parts[0], parts[1], parts[2], sched_array, static_cast<int>(sched.size()),
        std::stoi(parts[3]), std::stoi(parts[4]));

    return c;
}
