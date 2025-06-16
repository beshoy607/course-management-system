#include "../headers/file_manager.h"
#include "../headers/COURSE.h"
#include "../headers/user.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

file_manager::file_manager() {}
file_manager::~file_manager() {}

void file_manager::saveCourses(const std::vector<Course>& courses, const std::string& file_name) {
    std::ofstream outFile(file_name);
    if (!outFile) return;

    for (const auto& course : courses) {
        std::string schedule[2];
        int schedCount;
        course.getSchedule(schedule, schedCount);

        outFile << "Course Code: " << course.getCourseCode() << "\n"
            << "Course Name: " << course.getCourseName() << "\n"
            << "Instructor: " << course.getInstructor() << "\n"
            << "Credit Hours: " << course.getCreditHours() << "\n"
            << "Capacity: " << course.getCapacity() << "\n"
            << "Enrolled: " << course.getEnrolledStudents() << "\n";

        for (int i = 0; i < schedCount; ++i) {
            outFile << "Schedule Slot " << (i + 1) << ": " << schedule[i] << "\n";
        }

        outFile << "===\n"; // Separator
    }
    outFile.close();
}

std::vector<Course> file_manager::loadCourses(const std::string& file_name) {
    std::vector<Course> courses;
    std::ifstream inFile(file_name);
    if (!inFile) return courses;

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty() || line.find("Course Code:") != 0) continue;

        std::string code = line.substr(line.find(":") + 2);

        std::string name, instructor, hoursStr, capStr, enrolledStr;
        if (!std::getline(inFile, line) || line.find("Course Name:") != 0) continue;
        name = line.substr(line.find(":") + 2);

        if (!std::getline(inFile, line) || line.find("Instructor:") != 0) continue;
        instructor = line.substr(line.find(":") + 2);

        if (!std::getline(inFile, line) || line.find("Credit Hours:") != 0) continue;
        hoursStr = line.substr(line.find(":") + 2);

        if (!std::getline(inFile, line) || line.find("Capacity:") != 0) continue;
        capStr = line.substr(line.find(":") + 2);

        if (!std::getline(inFile, line) || line.find("Enrolled:") != 0) continue;
        enrolledStr = line.substr(line.find(":") + 2);

        if (code.empty() || name.empty() || instructor.empty() || hoursStr.empty() || capStr.empty() || enrolledStr.empty())
            continue;

        int hours = 0, cap = 0, enrolled = 0;
        try {
            hours = std::stoi(hoursStr);
            cap = std::stoi(capStr);
            enrolled = std::stoi(enrolledStr);
        }
        catch (...) {
            continue; // Skip malformed numbers
        }

        std::string schedule[2];
        int numSched = 0;

        while (std::getline(inFile, line) && line != "===") {
            size_t pos = line.find(": ");
            if (pos != std::string::npos && numSched < 2) {
                schedule[numSched++] = line.substr(pos + 2);
            }
        }

        Course c(code, name, instructor, schedule, numSched, hours, cap);
        c.setEnrolledStudents(enrolled);
        courses.push_back(c);
    }

    inFile.close();
    return courses;
}

void file_manager::saveUsers(const std::vector<user>& users, const std::string& file_name) {
    std::ofstream outFile(file_name);
    if (!outFile) return;

    for (const auto& user : users) {
        outFile << user.get_uname() << ","
            << user.get_pword() << std::endl;
    }
    outFile.close();
}

std::vector<user> file_manager::loadUsers(const std::string& file_name) {
    std::vector<user> users;
    std::ifstream inFile(file_name);
    if (!inFile) return users;

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string uname, pword;
        std::getline(ss, uname, ',');
        std::getline(ss, pword);
        user u(uname, pword);
        users.push_back(u);
    }
    inFile.close();
    return users;
}