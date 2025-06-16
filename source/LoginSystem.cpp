#include "../headers/LoginSystem.h"

void LoginSystem::setUsers(const std::vector<user>& newUsers) {
    users = newUsers;
}

std::vector<user> LoginSystem::getUsers() const {
    return users;
}

int LoginSystem::login(const std::string& username, const std::string& password) const {
    for (const auto& u : users) {
        if (u.get_uname() == username && u.get_pword() == password) {
            return (username == "admin1") ? 1 : 2; // 1 for admin, 2 for student
        }
    }
    return 0; // Login failed
}

void LoginSystem::register_admin(const std::string& username, const std::string& password) {
    users.push_back(user(username, password));
}

void LoginSystem::register_user(const std::string& username, const std::string& password) {
    users.push_back(user(username, password));
}
