#include "Database/itemdatabase.h"
#include <string>
#include <filesystem>
#include <fstream>

void ItemDatabase::addItem(Item& item)
{
    std::ofstream entityFile("POS/Items/" + std::to_string(item.getItemCode()) + ".entity");
    if(entityFile.is_open())
    {
        entityFile << "===ITEM===\n";
        entityFile << "NAME: " + item.getName() << std::endl;
        entityFile << "DESCRIPTION: " + item.getDescription() << std::endl;
        entityFile << "ITEM_CODE: " + std::to_string(item.getItemCode()) << std::endl;
        entityFile << "PRICE: " + std::to_string(item.getPrice()) << std::endl;
        entityFile << "===END===";
    }
    entityFile.close();
}

void ItemDatabase::updateItem(Item& item)
{
    deleteItem(item.getItemCode());
    addItem(item);
}

void ItemDatabase::deleteItem(int itemCode)
{
    std::string deletePath = "POS/Items/" + std::to_string(itemCode) + ".entity";
    std::filesystem::remove(deletePath);
}

Item ItemDatabase::getItem(std::string path)
{
    std::string line;
    std::ifstream entityFile(path);
    Item item;
    if(entityFile.is_open())
    {
        while(std::getline(entityFile, line))
        {
            if(line.find("NAME") != std::string::npos)
            {
                line.erase(0, 6);
                item.setName(line);
            }
            else if(line.find("DESCRIPTION") != std::string::npos)
            {
                line.erase(0, 13);
                item.setDescription(line);
            }
            else if(line.find("ITEM_CODE") != std::string::npos)
            {
                line.erase(0, 11);
                item.setItemCode(std::stoi(line));
            }
            else if(line.find("PRICE") != std::string::npos)
            {
                line.erase(0, 7);
                item.setPrice(std::stod(line));
            }
        }
    }
    entityFile.close();
    return item;
}

std::vector<Item> ItemDatabase::getAllItems()
{
    std::vector<Item> allItems;
    for(auto& file : std::filesystem::directory_iterator("POS/Items/"))
    {
        allItems.push_back(getItem(file.path()));
    }
    return allItems;
}
