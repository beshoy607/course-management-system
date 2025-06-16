#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "COURSE.h"
#include "../headers/user.h"
using namespace std;

class file_manager {
public:
    file_manager();
    ~file_manager();

    void saveCourses(const vector<Course>& courses, const string& file_name);
    vector<Course> loadCourses(const string& file_name);

    void saveUsers(const vector<user>& users, const string& file_name);
    vector<user> loadUsers(const string& file_name);
};

#endif
