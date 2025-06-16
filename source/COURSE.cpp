#include "../headers/COURSE.h"
#include <iostream>
using namespace std;

// Default Constructor
Course::Course() {
    courseCode = "";
    courseName = "";
    instructor = "";
    numSchedules = 0;
    creditHours = 0;
    capacity = 0;
    enrollStudents = 0;
}

// Parameterized Constructor
Course::Course(string code, string name, string doc, string sched[], int numSched, int hours, int cap) {
    courseCode = code;
    courseName = name;
    instructor = doc;
    numSchedules = (numSched > 2) ? 2 : numSched;
    creditHours = hours;
    capacity = cap;
    enrollStudents = 0;
    for (int i = 0; i < numSchedules; i++) {
        schedule[i] = sched[i];
    }
}

// Getters
string Course::getCourseCode() const {
    return courseCode;
}

string Course::getCourseName() const {
    return courseName;
}

string Course::getInstructor() const {
    return instructor;
}

int Course::getCreditHours() const {
    return creditHours;
}

int Course::getCapacity() const {
    return capacity;
}

int Course::getEnrolledStudents() const {
    return enrollStudents;
}

// Setters
void Course::setCourseCode(const string& code) {
    courseCode = code;
}

void Course::setCourseName(const string& name) {
    courseName = name;
}

void Course::setInstructor(const string& doc) {
    instructor = doc;
}

void Course::setSchedule(const string sched[], int numSched) {
    numSchedules = (numSched > 2) ? 2 : numSched;
    for (int i = 0; i < numSchedules; i++) {
        schedule[i] = sched[i];
    }
}

void Course::setSchedule(const std::string& slot, int index) {
    if (index >= 0 && index < 2) {
        schedule[index] = slot;
    }
}

void Course::setCreditHours(const int hours) {
    creditHours = hours;
}

void Course::setCapacity(const int cap) {
    capacity = cap;
}

void Course::setEnrolledStudents(const int enrolled) {
    enrollStudents = enrolled;
}

// Functions
void Course::GetCourseDetails(string& code, string& name, string& doc, string sched[], int& numSched,
    int& hours, int& cap, int& enrolled) const {

    code = getCourseCode();
    name = getCourseName();
    doc = getInstructor();
    getSchedule(sched, numSched);
    hours = getCreditHours();
    cap = getCapacity();
    enrolled = getEnrolledStudents();
}

void Course::getSchedule(string output[], int& count) const {
    count = numSchedules;
    for (int i = 0; i < numSchedules; i++) {
        output[i] = schedule[i];
    }
}

void Course::UpdateEnrolled(int n) {
    enrollStudents += n;
    if (enrollStudents < 0) enrollStudents = 0;
    if (enrollStudents > capacity) enrollStudents = capacity;
}

bool Course::IsAvailable() const {
    return enrollStudents < capacity;
}

void Course::ModifyAttributes(const string& newCode, const string& newName, const string& newInstructor,
    const string newSchedule[], int newNumSched, int newHours, int newCapacity) {

    setCourseCode(newCode);
    setCourseName(newName);
    setInstructor(newInstructor);
    setSchedule(newSchedule, newNumSched);
    setCreditHours(newHours);
    setCapacity(newCapacity);
}
void Course::enrollStudent() {
    if (enrollStudents < capacity) {
        enrollStudents++;
    }
}

