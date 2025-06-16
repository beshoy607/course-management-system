#ifndef USER_H  
#define USER_H

#include <string>
#include "COURSE.h"
using namespace std;

class user {
private:
    string uname;
    string pword;
    
public:
    Course courses[10];
    user(); 
    user(string n, string p);
    string get_uname() const;
    string get_pword() const;
    void set_pword(const string p);
};

#endif
