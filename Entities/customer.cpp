#include "Entities/customer.h"

Customer::Customer()
{
    firstName = "";
    lastName = "";
    phoneNumber = 0000000000;
    email = "";
}

Customer::Customer(std::string firstName, std::string lastName, long phoneNumber, std::string email)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

Customer::~Customer()
{

}

std::string Customer::getFirstName()
{
    return firstName;
}

std::string Customer::getLastName()
{
    return lastName;
}

long Customer::getPhoneNumber()
{
    return phoneNumber;
}

std::string Customer::getEmail()
{
    return email;
}

void Customer::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Customer::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Customer::setPhoneNumber(long phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Customer::setEmail(std::string email)
{
    this->email = email;
}

bool Customer::operator==(Customer& toCompare)
{
    return phoneNumber == toCompare.getPhoneNumber();
}

bool Customer::operator==(long& phoneNumber)
{
    return this->phoneNumber == phoneNumber;
}

