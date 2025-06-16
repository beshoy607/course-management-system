#include "../headers/user.h"

user::user() {
}

user::user(string u, string p) {
    uname = u;
    pword = p;
}

string user::get_uname() const {
    return uname;
}

string user::get_pword() const {
    return pword;
}

void user::set_pword(const string p) {
    pword = p;
}


