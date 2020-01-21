#ifndef USER_H
#define USER_H
#include <string>

enum UserType
{
    Admin,
    Sales
};

class User
{
public:
    User();
    User(std::string, std::string, int, UserType);
    ~User();
    std::string getFirstName();
    std::string getLastName();
    int getLoginID();
    UserType getUserType();
    void setFirstName(std::string);
    void setLastName(std::string);
    void setLoginID(int);
    void setUserType(UserType);
    bool operator==(User&);
    bool operator==(int&);
private:
    std::string firstName, lastName;
    int loginID;
    UserType userType;
};

#endif // USER_H
