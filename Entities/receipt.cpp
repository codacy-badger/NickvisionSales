#include "Entities/receipt.h"
#include <filesystem>
#include <fstream>
#include "utils.h"

Receipt::Receipt()
{

}

Receipt::Receipt(Customer customer)
{
    this->customer = customer;
    items.clear();
}

Receipt::~Receipt()
{

}

void Receipt::addItem(Item item)
{
    items.push_back(item);
}

void Receipt::removeItem(Item& item)
{
    for(unsigned int i = 0; i < items.size(); i++)
    {
        if((items.at(i)).getItemCode() == item.getItemCode())
        {
            items.erase(items.begin() + i);
            return;
        }
    }
}

void Receipt::clearItems()
{
    items.clear();
}

double Receipt::getTotal()
{
    double total = 0.00;
    for(auto& item : items)
    {
        total += item.getPrice();
    }
    utils::convertToMoney(total);
    return total;
}

std::vector<std::string> Receipt::getReceipt()
{
    receipt.clear();
    receipt.push_back("Customer: " + customer.getFirstName() + " " + customer.getLastName() + "\n");
    for(auto& item : items)
    {
        receipt.push_back(item.getName() + ": $" + std::to_string(item.getPrice()));
    }
    receipt.push_back("\nTotal: $" + std::to_string(Receipt::getTotal()));
    return receipt;
}

double Receipt::checkout(double amountGiven)
{
    utils::convertToMoney(amountGiven);
    double change = amountGiven - Receipt::getTotal();
    receipt.push_back("Amount Given: $" + std::to_string(amountGiven));
    receipt.push_back("Change: $" + std::to_string(change));
    return change;
}

void Receipt::saveReceipt()
{
    receipt.push_back("\nCustomer Info:");
    receipt.push_back("Name: " + customer.getFirstName() + " " + customer.getLastName());
    receipt.push_back("Phone Number: " + std::to_string(customer.getPhoneNumber()));
    receipt.push_back("Email: " + customer.getEmail());
    int fileNumber = 0;
    for(auto& file : std::filesystem::directory_iterator("POS/Receipts")) fileNumber++;
    fileNumber++;
    std::ofstream writer("POS/Receipts/" + std::to_string(fileNumber) + ".txt");
    for(auto& s : receipt)
    {
        writer << s << "\n";
    }
    writer.close();
}
