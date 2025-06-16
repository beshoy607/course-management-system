#include "../headers/Registration.h"
#include <iostream>
#include <algorithm>
using namespace std;

vector<Course> Registration::getCourses() const {
    return courses;
}

void Registration::setCourses(const vector<Course>& newCourses) {
    courses = newCourses;
}

void Registration::AddCourseFromInput() {
    Course course;
    string input;
    int intInput;

    cout << "Enter Course Code: ";
    getline(cin, input);
    course.setCourseCode(input);

    cout << "Enter Course Name: ";
    getline(cin, input);
    course.setCourseName(input);

    cout << "Enter Instructor Name: ";
    getline(cin, input);
    course.setInstructor(input);

    cout << "Enter Credit Hours: ";
    cin >> intInput;
    course.setCreditHours(intInput);

    cout << "Enter Capacity: ";
    cin >> intInput;
    while (intInput <= 0) {
        cout << "Capacity must be greater than 0. Enter again: ";
        cin >> intInput;
    }
    course.setCapacity(intInput);
    cin.ignore();

    int numSched;
    cout << "Enter number of schedule slots (max 2): ";
    cin >> numSched;
    cin.ignore();
    if (numSched > 2) numSched = 2;

    string schedule[2];
    for (int i = 0; i < numSched; ++i) {
        cout << "Enter schedule slot " << i + 1 << ": ";
        getline(cin, schedule[i]);
    }
    course.setSchedule(schedule, numSched);

    courses.push_back(course);
    cout << "Course added successfully.\n";
}

void Registration::ModifyAttributes() {
    string code;
    cout << "Enter the course code to edit: ";
    getline(cin, code);

    for (auto& course : courses) {
        if (course.getCourseCode() == code) {
            string input;
            int intInput;

            cout << "Enter new Course Name: ";
            getline(cin, input);
            course.setCourseName(input);

            cout << "Enter new Instructor Name: ";
            getline(cin, input);
            course.setInstructor(input);

            cout << "Enter new Credit Hours: ";
            cin >> intInput;
            course.setCreditHours(intInput);

            cout << "Enter new Capacity: ";
            cin >> intInput;
            while (intInput <= 0) {
                cout << "Capacity must be greater than 0. Enter again: ";
                cin >> intInput;
            }
            course.setCapacity(intInput);
            cin.ignore();

            int numSched;
            cout << "Enter number of schedule slots (max 2): ";
            cin >> numSched;
            cin.ignore();
            if (numSched > 2) numSched = 2;

            string schedule[2];
            for (int i = 0; i < numSched; ++i) {
                cout << "Enter schedule slot " << i + 1 << ": ";
                getline(cin, schedule[i]);
            }
            course.setSchedule(schedule, numSched);

            cout << "Course updated successfully.\n";
            return;
        }
    }

    cout << "Course not found.\n";
}

void Registration::DropCourse() {
    string code;
    cout << "Enter the course code to delete: ";
    getline(cin, code);

    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->getCourseCode() == code) {
            courses.erase(it);
            cout << "Course deleted successfully.\n";
            return;
        }
    }

    cout << "Course not found.\n";
}

void Registration::unregisterCourse(const std::string& username, const std::string& courseCode) {
    for (auto& student : studentRegistrations) {
        if (student.first == username) {
            auto& courseList = student.second;
            auto it = std::find(courseList.begin(), courseList.end(), courseCode);
            if (it != courseList.end()) {
                courseList.erase(it);
                for (auto& course : courses) {
                    if (course.getCourseCode() == courseCode) {
                        course.UpdateEnrolled(-1);
                        break;
                    }
                }
                cout << "Course dropped successfully.\n";
                return;
            }
        }
    }
    cout << "Course not found in your schedule.\n";
}

int Registration::getTotalCourses() const {
    return static_cast<int>(courses.size());
}

void Registration::registerCourse(const string& username, const string& courseCode) {
    for (auto& course : courses) {
        if (course.getCourseCode() == courseCode) {
            if (!course.IsAvailable()) {
                cout << "Course is full and cannot accept more students.\n";
                return;
            }
            course.enrollStudent();

            for (auto& student : studentRegistrations) {
                if (student.first == username) {
                    student.second.push_back(courseCode);
                    cout << "Course registered successfully.\n";
                    return;
                }
            }

            studentRegistrations.push_back({ username, { courseCode } });
            cout << "Course registered successfully.\n";
            return;
        }
    }
    cout << "Course not found.\n";
}

void Registration::getStudentSchedule(const string& username, string schedule[], int& size) const {
    size = 0;
    for (const auto& student : studentRegistrations) {
        if (student.first == username) {
            for (const auto& courseCode : student.second) {
                schedule[size++] = courseCode;
            }
            return;
        }
    }
    cout << "No courses registered yet.\n";
}

void Registration::ShowAllCourses() const {
    if (courses.empty()) {
        cout << "No courses available.\n";
        return;
    }

    for (const auto& course : courses) {
        cout << "Code: " << course.getCourseCode() << endl;
        cout << "Name: " << course.getCourseName() << endl;
        cout << "Instructor: " << course.getInstructor() << endl;
        cout << "Hours: " << course.getCreditHours() << endl;
        cout << "Capacity: " << course.getCapacity() << endl;
        cout << "Enrolled: " << course.getEnrolledStudents() << endl;
        cout << "--------------------------" << endl;
    }
}
