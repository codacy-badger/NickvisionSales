#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "Entities/user.h"
#include "Entities/item.h"
#include "Entities/customer.h"

namespace utils
{
    void convertToMoney(double&);
    void getUser(User&, bool&);
    void getItem(Item&, bool&);
    void getCustomer(Customer&, bool&);
}

#endif // UTILS_H
