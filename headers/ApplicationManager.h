#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "LoginSystem.h"
#include "ui.h"
#include "Registration.h"
#include "COURSE.h"
#include "file_manager.h"
#include <string>

class ApplicationManager {
private:
    LoginSystem loginSystem;
    UI ui;
    Registration reg;
    Course courseList[10]; 
    file_manager fm;
    std::string username, password;

public:
    void run();              
    void handleLogin();      
    void handleAdminMenu();  
    void handleStudentMenu();
};

#endif
