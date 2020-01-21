#include "Database/userdatabase.h"
#include <string>
#include <filesystem>
#include <fstream>

void UserDatabase::addUser(User& user)
{
    std::ofstream entityFile("POS/Users/" + std::to_string(user.getLoginID()) + ".entity");
    if(entityFile.is_open())
    {
        entityFile << "===USER===\n";
        entityFile << "FIRST_NAME: " + user.getFirstName() << std::endl;
        entityFile << "LAST_NAME: " + user.getLastName() << std::endl;
        entityFile << "LOGIN_ID: " + std::to_string(user.getLoginID()) << std::endl;
        entityFile << "USER_TYPE: " + std::to_string(user.getUserType()) << std::endl;
        entityFile << "===END===";
    }
    entityFile.close();
}

void UserDatabase::updateUser(User& user)
{
    deleteUser(user.getLoginID());
    addUser(user);
}

void UserDatabase::deleteUser(int loginID)
{
    std::string deletePath = "POS/Users/" + std::to_string(loginID) + ".entity";
    std::filesystem::remove(deletePath);
}

User UserDatabase::getUser(std::string path)
{
    std::string line;
    std::ifstream entityFile(path);
    User user;
    if(entityFile.is_open())
    {
        while(std::getline(entityFile, line))
        {
            if(line.find("FIRST_NAME") != std::string::npos)
            {
                line.erase(0, 12);
                user.setFirstName(line);
            }
            else if(line.find("LAST_NAME") != std::string::npos)
            {
                line.erase(0, 11);
                user.setLastName(line);
            }
            else if(line.find("LOGIN_ID") != std::string::npos)
            {
                line.erase(0, 10);
                user.setLoginID(std::stoi(line));
            }
            else if(line.find("USER_TYPE") != std::string::npos)
            {
                line.erase(0, 11);
                user.setUserType(static_cast<UserType>(std::stoi(line)));
            }
        }
    }
    entityFile.close();
    return user;
}

std::vector<User> UserDatabase::getAllUsers()
{
    std::vector<User> allUsers;
    for(auto& file : std::filesystem::directory_iterator("POS/Users/"))
    {
        allUsers.push_back(getUser(file.path()));
    }
    return allUsers;
}
