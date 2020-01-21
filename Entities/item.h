#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
public:
    Item();
    Item(std::string, std::string, int, double);
    ~Item();
    std::string getName();
    std::string getDescription();
    int getItemCode();
    double getPrice();
    void setName(std::string);
    void setDescription(std::string);
    void setItemCode(int);
    void setPrice(double);
    bool operator==(Item&);
    bool operator==(int&);
private:
    std::string name, description;
    int itemCode;
    double price;
};

#endif // ITEM_H
