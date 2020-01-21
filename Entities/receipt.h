#ifndef RECEIPT_H
#define RECEIPT_H
#include <string>
#include <vector>
#include "customer.h"
#include "item.h"

class Receipt
{
public:
    Receipt();
    Receipt(Customer);
    ~Receipt();
    void addItem(Item);
    void removeItem(Item&);
    void clearItems();
    double getTotal();
    std::vector<std::string> getReceipt();
    double checkout(double);
    void saveReceipt();
private:
    Customer customer;
    std::vector<Item> items;
    std::vector<std::string> receipt;
};

#endif // RECEIPT_H
