#include <string>
using namespace std;
#ifndef ADMIN_H  
#define ADMIN_H

#include "user.h"  

class admin : public user {
public:
    admin(string n, string p);
};

#endif
