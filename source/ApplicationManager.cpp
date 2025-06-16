#include "../headers/ApplicationManager.h"
#include "../headers/file_manager.h"
#include "../headers/user.h"
#include "../headers/COURSE.h"
#include <iostream>
#include <limits>
using namespace std;

void ApplicationManager::run() {
    vector<Course> loadedCourses = fm.loadCourses("courses.txt");
    reg.setCourses(loadedCourses);

    vector<user> loadedUsers = fm.loadUsers("users.txt");
    loginSystem.setUsers(loadedUsers);

    loginSystem.register_admin("admin1", "1234");
    loginSystem.register_user("user", "1234");

    while (true) {
        int mainChoice;
        ui.printMainMenu();

        if (!(cin >> mainChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ui.printMessage("Invalid input. Please enter a number.");
            continue;
        }

        cin.ignore();

        switch (mainChoice) {
        case 1:
            handleLogin();
            break;
        case 2:
            ui.printMessage("Exiting the system...");
            fm.saveCourses(reg.getCourses(), "courses.txt");
            fm.saveUsers(loginSystem.getUsers(), "users.txt");
            return;
        default:
            ui.printMessage("Invalid option, please try again.");
            break;
        }
    }
}

void ApplicationManager::handleLogin() {
    ui.loginMenu(username, password);
    int result = loginSystem.login(username, password);

    reg.setCourses(fm.loadCourses("courses.txt"));

    switch (result) {
    case 1:
        ui.printMessage("Login successful! (Admin)");
        handleAdminMenu();
        break;
    case 2:
        ui.printMessage("Login successful! (Student)");
        handleStudentMenu();
        break;
    default:
        ui.printMessage("Login failed. Please try again.");
        break;
    }
}

void ApplicationManager::handleAdminMenu() {
    while (true) {
        ui.printAdminMenu();
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ui.printMessage("Invalid input. Please enter a number.");
            continue;
        }
        cin.ignore();

        switch (choice) {
        case 1:
            reg.AddCourseFromInput();
            fm.saveCourses(reg.getCourses(), "courses.txt");
            break;
        case 2:
            reg.ModifyAttributes();
            fm.saveCourses(reg.getCourses(), "courses.txt");
            break;
        case 3:
            reg.DropCourse();
            fm.saveCourses(reg.getCourses(), "courses.txt");
            break;
        case 4:
            reg.ShowAllCourses();
            break;
        case 5:
            return;
        default:
            ui.printMessage("Invalid option, try again.");
            break;
        }
    }
}

void ApplicationManager::handleStudentMenu() {
    while (true) {
        ui.printStudentMenu();
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ui.printMessage("Invalid input. Please enter a number.");
            continue;
        }
        cin.ignore();

        switch (choice) {
        case 1:
        {
            string code;
            cout << "Enter course code to register: ";
            getline(cin, code);
            reg.registerCourse(username, code);
        }
        break;
        case 2:
        {
            string code;
            cout << "Enter course code to drop: ";
            getline(cin, code);
            reg.unregisterCourse(username, code);
        }
        break;
        case 3:
        {
            string schedule[10];
            int size = 0;
            reg.getStudentSchedule(username, schedule, size);
            ui.displayStudentSchedule(reg, username);
        }
        break;
        case 4:
            reg.ShowAllCourses();
            break;
        case 5:
            return;
        default:
            ui.printMessage("Invalid option, try again.");
            break;
        }
    }
}
