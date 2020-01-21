#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#include <vector>
#include "Entities/customer.h"

namespace CustomerDatabase
{
    void addCustomer(Customer&);
    void updateCustomer(Customer&);
    void deleteCustomer(long);
    Customer getCustomer(std::string);
    std::vector<Customer> getAllCustomers();
}

#endif // CUSTOMERDATABASE_H
