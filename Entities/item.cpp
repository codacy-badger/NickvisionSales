#include "Entities/item.h"
#include "utils.h"

Item::Item()
{
    name = "";
    description = "";
    itemCode = 0;
    price = 0.00;
}

Item::Item(std::string name, std::string description, int itemCode, double price)
{
    this->name = name;
    this->description = description;
    this->itemCode = itemCode;
    this->price = price;
    utils::convertToMoney(price);
}

Item::~Item()
{

}

std::string Item::getName()
{
    return name;
}

std::string Item::getDescription()
{
    return description;
}

int Item::getItemCode()
{
    return itemCode;
}

double Item::getPrice()
{
    utils::convertToMoney(price);
    return price;
}

void Item::setName(std::string name)
{
    this->name = name;
}

void Item::setDescription(std::string description)
{
    this->description = description;
}

void Item::setItemCode(int itemCode)
{
    this->itemCode = itemCode;
}

void Item::setPrice(double price)
{
    this->price = price;
    utils::convertToMoney(price);
}

bool Item::operator==(Item& toCompare)
{
    return itemCode == toCompare.getItemCode();
}

bool Item::operator==(int& itemCode)
{
    return this->itemCode == itemCode;
}
