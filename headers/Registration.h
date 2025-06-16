#ifndef REGISTRATION_H  
#define REGISTRATION_H  

#include "COURSE.h"  
#include <string>  
#include <vector>  

class Registration {
private:
    std::vector<Course> courses;
    std::vector<std::pair<std::string, std::vector<std::string>>> studentRegistrations;

public:
    std::vector<Course> getCourses() const;
    void setCourses(const std::vector<Course>& newCourses);
    void AddCourse(const Course& course);
    void AddCourseFromInput();
    void ModifyAttributes();
    void DropCourse();
    void unregisterCourse(const std::string& username, const std::string& courseCode);
    int getTotalCourses() const;
    void registerCourse(const std::string& username, const std::string& courseCode);
    void getStudentSchedule(const std::string& username, std::string schedule[], int& size) const;
    void ShowAllCourses() const;
};

#endif
