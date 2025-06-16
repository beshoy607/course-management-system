#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    string instructor;
    string schedule[2];
    int numSchedules;
    int creditHours;
    int capacity;
    int enrollStudents;

public:
    Course();
    Course(string code, string name, string doc, string sched[], int numSched, int hours, int cap);

    string getCourseCode() const;
    string getCourseName() const;
    string getInstructor() const;
    void getSchedule(string output[], int& count) const;
    int getCreditHours() const;
    int getCapacity() const;
    int getEnrolledStudents() const;

    void setCourseCode(const string& code);
    void setCourseName(const string& name);
    void setInstructor(const string& doc);
    void setSchedule(const string sched[], int numSched);
    void setSchedule(const string& slot, int index);
    void setCreditHours(const int hours);
    void setCapacity(const int cap);
    void setEnrolledStudents(const int enrolled);

    void GetCourseDetails(string& code, string& name, string& doc, string sched[], int& numSched,
        int& hours, int& cap, int& enrolled) const;

    void UpdateEnrolled(int n);
    bool IsAvailable() const;
    void ModifyAttributes(const string& newCode, const string& newName, const string& newInstructor,
        const string newSchedule[], int newNumSched, int newHours, int newCapacity);
    void enrollStudent();
};

#endif
