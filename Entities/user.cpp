#include "Entities/user.h"

User::User()
{
    firstName = "";
    lastName = "";
    loginID = 0;
    userType = Sales;
}

User::User(std::string firstName, std::string lastName, int loginID, UserType userType)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->loginID = loginID;
    this->userType = userType;
}

User::~User()
{

}

std::string User::getFirstName()
{
    return firstName;
}

std::string User::getLastName()
{
    return lastName;
}

int User::getLoginID()
{
    return loginID;
}

UserType User::getUserType()
{
    return userType;
}

void User::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void User::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void User::setLoginID(int loginID)
{
    this->loginID = loginID;
}

void User::setUserType(UserType userType)
{
    this->userType = userType;
}

bool User::operator==(User& toCompare)
{
    return loginID == toCompare.getLoginID();
}

bool User::operator==(int& loginID)
{
    return this->loginID == loginID;
}
