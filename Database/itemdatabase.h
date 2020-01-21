#ifndef ITEMDATABASE_H
#define ITEMDATABASE_H
#include <vector>
#include "Entities/item.h"

namespace ItemDatabase
{
    void addItem(Item&);
    void updateItem(Item&);
    void deleteItem(int);
    Item getItem(std::string);
    std::vector<Item> getAllItems();
}

#endif // ITEMDATABASE_H
