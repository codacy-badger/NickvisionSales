#include "Database/customerdatabase.h"
#include <string>
#include <filesystem>
#include <fstream>

void CustomerDatabase::addCustomer(Customer& customer)
{
    std::ofstream entityFile("POS/Customers/" + std::to_string(customer.getPhoneNumber()) + ".entity");
    if(entityFile.is_open())
    {
        entityFile << "===Customer===\n";
        entityFile << "FIRST_NAME: " + customer.getFirstName() << std::endl;
        entityFile << "LAST_NAME: " + customer.getLastName() << std::endl;
        entityFile << "PHONE_NUMBER: " + std::to_string(customer.getPhoneNumber()) << std::endl;
        entityFile << "EMAIL: " + customer.getEmail() << std::endl;
        entityFile << "===END===";
    }
    entityFile.close();
}

void CustomerDatabase::updateCustomer(Customer& customer)
{
    deleteCustomer(customer.getPhoneNumber());
    addCustomer(customer);
}

void CustomerDatabase::deleteCustomer(long phoneNumber)
{
    std::string deletePath = "POS/Customers/" + std::to_string(phoneNumber) + ".entity";
    std::filesystem::remove(deletePath);
}

Customer CustomerDatabase::getCustomer(std::string path)
{
    std::string line;
    std::ifstream entityFile(path);
    Customer customer;
    if(entityFile.is_open())
    {
        while(std::getline(entityFile, line))
        {
            if(line.find("FIRST_NAME") != std::string::npos)
            {
                line.erase(0, 12);
                customer.setFirstName(line);
            }
            else if(line.find("LAST_NAME") != std::string::npos)
            {
                line.erase(0, 11);
                customer.setLastName(line);
            }
            else if(line.find("PHONE_NUMBER") != std::string::npos)
            {
                line.erase(0, 14);
                customer.setPhoneNumber(std::stol(line));
            }
            else if(line.find("EMAIL") != std::string::npos)
            {
                line.erase(0, 7);
                customer.setEmail(line);
            }
        }
    }
    entityFile.close();
    return customer;
}

std::vector<Customer> CustomerDatabase::getAllCustomers()
{
    std::vector<Customer> allCustomers;
    for(auto& file : std::filesystem::directory_iterator("POS/Customers/"))
    {
        allCustomers.push_back(getCustomer(file.path()));
    }
    return allCustomers;
}
