#ifndef UI_H
#define UI_H

#include <string>
#include "Registration.h"

class UI {
public:
    void printMainMenu();
    void loginMenu(std::string& n, std::string& p);
    void printAdminMenu();
    void printStudentMenu();
    void printMessage(const std::string& message);
    void displayStudentSchedule(Registration& reg, const std::string& username);
};

#endif
