#ifndef USERDATABASE_H
#define USERDATABASE_H
#include <vector>
#include "Entities/user.h"

namespace UserDatabase
{
    void addUser(User&);
    void updateUser(User&);
    void deleteUser(int);
    User getUser(std::string);
    std::vector<User> getAllUsers();
}

#endif // USERDATABASE_H
