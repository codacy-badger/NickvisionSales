#include "utils.h"
#include <QInputDialog>
#include "Database/userdatabase.h"
#include "Database/itemdatabase.h"
#include "Database/customerdatabase.h"

void utils::convertToMoney(double& toConvert)
{
    toConvert = (int)(toConvert * 100 + .5);
    toConvert /= 100;
}

void utils::getUser(User& user, bool& isValid)
{
    bool ok;
    QString txtLoginID = QInputDialog::getText(0, "Get User", "Enter Login ID:", QLineEdit::Normal, "", &ok);
    if(ok && !txtLoginID.isEmpty())
    {
        int loginID;
        try
        {
            loginID = std::stoi(txtLoginID.toStdString());
        }
        catch (...)
        {
            return;
        }
        for(auto& u : UserDatabase::getAllUsers())
        {
            if(u == loginID)
            {
                user = u;
                isValid = true;
            }
        }
    }
}

void utils::getItem(Item& item, bool& isValid)
{
    bool ok;
    QString txtItemCode = QInputDialog::getText(0, "Get Item", "Enter Item Code:", QLineEdit::Normal, "", &ok);
    if(ok && !txtItemCode.isEmpty())
    {
        int itemCode;
        try
        {
            itemCode = std::stoi(txtItemCode.toStdString());
        }
        catch (...)
        {
            return;
        }
        for(auto& i : ItemDatabase::getAllItems())
        {
            if(i == itemCode)
            {
                item = i;
                isValid = true;
            }
        }
    }
}

void utils::getCustomer(Customer& customer, bool& isValid)
{
    bool ok;
    QString txtPhoneNumber = QInputDialog::getText(0, "Get Customer", "Enter Phone Number:", QLineEdit::Normal, "", &ok);
    if(ok && !txtPhoneNumber.isEmpty())
    {
        long phoneNumber;
        try
        {
            phoneNumber = std::stol(txtPhoneNumber.toStdString());
        }
        catch (...)
        {
            return;
        }
        for(auto& c : CustomerDatabase::getAllCustomers())
        {
            if(c == phoneNumber)
            {
                customer = c;
                isValid = true;
            }
        }
    }
}


