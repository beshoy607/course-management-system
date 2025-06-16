#include "../headers/ui.h"
#include "../headers/COURSE.h"
#include "../headers/Registration.h"
#include <iostream>
using namespace std;

void UI::printMainMenu() {
    cout << "===== University Course Registration System =====\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
    cout << "Select an option: ";
}

void UI::loginMenu(string& n, string& p) {
    cout << "\n===== Login =====\n";
    cout << "Username: ";
    cin >> n;
    cin.ignore();
    cout << "Password: ";
    cin >> p;
    cin.ignore();
}

void UI::printAdminMenu() {
    cout << "\n===== Admin Menu =====\n";
    cout << "1. Add Course\n";
    cout << "2. Edit Course\n";
    cout << "3. Delete Course\n";
    cout << "4. View All Courses\n";
    cout << "5. Logout\n";
    cout << "Select an option: ";
}

void UI::printStudentMenu() {
    cout << "\n===== Student Menu =====\n";
    cout << "1. Register for a Course\n";
    cout << "2. Drop a Course\n";
    cout << "3. View Schedule\n";
    cout << "4. View Available Courses\n";
    cout << "5. Logout\n";
    cout << "Select an option: ";
}

void UI::printMessage(const string& message) {
    cout << "\n[Message]: " << message << endl;
}

void UI::displayStudentSchedule(Registration& reg, const std::string& username) {
    std::string courseCodes[10];
    int size = 0;
    reg.getStudentSchedule(username, courseCodes, size);

    if (size == 0) {
        cout << "No courses enrolled.\n";
        return;
    }

    vector<Course> allCourses = reg.getCourses();

    for (int i = 0; i < size; ++i) {
        for (const auto& course : allCourses) {
            if (course.getCourseCode() == courseCodes[i]) {
                cout << "Course Code: " << course.getCourseCode() << "\n";

                string slots[2];
                int count;
                course.getSchedule(slots, count);

                for (int j = 0; j < count; ++j) {
                    cout << "Schedule Slot " << j + 1 << ": " << slots[j] << "\n";
                }

                cout << "---------------------\n";
                break;
            }
        }
    }
}
