#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer
{
public:
    Customer();
    Customer(std::string, std::string, long, std::string);
    ~Customer();
    std::string getFirstName();
    std::string getLastName();
    long getPhoneNumber();
    std::string getEmail();
    void setFirstName(std::string);
    void setLastName(std::string);
    void setPhoneNumber(long);
    void setEmail(std::string);
    bool operator==(Customer&);
    bool operator==(long&);
private:
    std::string firstName, lastName, email;
    long phoneNumber;
};

#endif // CUSTOMER_H
