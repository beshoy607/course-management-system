#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "user.h"
#include <vector>
#include <string>

class LoginSystem {
private:
    std::vector<user> users;

public:
    void setUsers(const std::vector<user>& newUsers);
    std::vector<user> getUsers() const;
    int login(const std::string& username, const std::string& password) const;
    void register_admin(const std::string& username, const std::string& password);
    void register_user(const std::string& username, const std::string& password);
};

#endif
