#include "Views/adminview.h"
#include "ui_adminview.h"
#include <QMessageBox>
#include "utils.h"
#include "Database/userdatabase.h"
#include "Database/itemdatabase.h"
#include "Database/customerdatabase.h"

AdminView::AdminView(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminView)
{
    ui->setupUi(this);
    this->user = user;
    this->setModal(true);
    this->setFixedSize(QSize(595, 450));
    ui->lblWelcome->setText(QString::fromStdString("Welcome " + user.getFirstName() + " " + user.getLastName()));
}

AdminView::~AdminView()
{
    delete ui;
}

void AdminView::on_btnLogout_clicked()
{
    this->close();
}

void AdminView::on_btnExitApp_clicked()
{
    QApplication::quit();
}

void AdminView::on_btnNewSale_clicked()
{
    Customer customer;
    bool isValid = false;
    utils::getCustomer(customer, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Phone Number", "No customer exists with that phone number");
        msgBox.exec();
        return;
    }
    newSaleDialog = new NewSaleDialog(customer);
    newSaleDialog->exec();
    delete newSaleDialog;
}

void AdminView::on_btnNewUser_clicked()
{
    userDialog = new UserDialog(true, false);
    delete userDialog;
}

void AdminView::on_btnEditUser_clicked()
{
    userDialog = new UserDialog(false, false);
    delete userDialog;
}

void AdminView::on_btnViewUser_clicked()
{
    User user;
    bool isValid = false;
    utils::getUser(user, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Login ID", "No user exists with that login id");
        msgBox.exec();
        return;
    }
    std::string userInfo("First Name: " + user.getFirstName() + "\nLast Name: " + user.getLastName() +
                         "\nLogin ID: " + std::to_string(user.getLoginID()));
    if(user.getUserType() == Admin) userInfo += "\nUser Type: Admin";
    else userInfo += "\nUser Type: Sales";
    QMessageBox msgBox(QMessageBox::Information, "User Info", QString::fromStdString(userInfo));
    msgBox.exec();
}

void AdminView::on_btnDeleteUser_clicked()
{
    User user;
    bool isValid = false;
    utils::getUser(user, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Login ID", "No user exists with that login id");
        msgBox.exec();
        return;
    }
    UserDatabase::deleteUser(user.getLoginID());
    QMessageBox msgBox(QMessageBox::Information, "User Deleted", "User was deleted");
    msgBox.exec();
}

void AdminView::on_btnListAllUsers_clicked()
{
    entityListDialog = new EntityListDialog(eUser);
    delete entityListDialog;
}

void AdminView::on_btnNewItem_clicked()
{
    itemDialog = new ItemDialog(true);
    delete itemDialog;
}

void AdminView::on_btnEditItem_clicked()
{
    itemDialog = new ItemDialog(false);
    delete itemDialog;
}

void AdminView::on_btnViewItem_clicked()
{
    Item item;
    bool isValid = false;
    utils::getItem(item, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Item Code", "No item exists with that item code");
        msgBox.exec();
        return;
    }
    std::string itemInfo("Name: " + item.getName() + "\nDescription: " + item.getDescription() +
                         "\nItem Code: " + std::to_string(item.getItemCode()) + "\nPrice: " + std::to_string(item.getPrice()));
    QMessageBox msgBox(QMessageBox::Information, "Item Info", QString::fromStdString(itemInfo));
    msgBox.exec();
}

void AdminView::on_btnDeleteItem_clicked()
{
    Item item;
    bool isValid = false;
    utils::getItem(item, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Item Code", "No item exists with that item code");
        msgBox.exec();
        return;
    }
    ItemDatabase::deleteItem(item.getItemCode());
    QMessageBox msgBox(QMessageBox::Information, "Item Deleted", "Item was deleted");
    msgBox.exec();
}

void AdminView::on_btnListAllItems_clicked()
{
    entityListDialog = new EntityListDialog(eItem);
    delete entityListDialog;
}

void AdminView::on_btnNewCustomer_clicked()
{
    customerDialog = new CustomerDialog(true);
    delete customerDialog;
}

void AdminView::on_btnEditCustomer_clicked()
{
    customerDialog = new CustomerDialog(false);
    delete customerDialog;
}

void AdminView::on_btnViewCustomer_clicked()
{
    Customer customer;
    bool isValid = false;
    utils::getCustomer(customer, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Phone Number", "No customer exists with that phone number");
        msgBox.exec();
        return;
    }
    std::string customerInfo("First Name: " + customer.getFirstName() + "\nLast Name: " + customer.getLastName() +
                         "\nPhone: " + std::to_string(customer.getPhoneNumber()) + "\nEmail: " + customer.getEmail());
    QMessageBox msgBox(QMessageBox::Information, "Customer Info", QString::fromStdString(customerInfo));
    msgBox.exec();
}

void AdminView::on_btnDeleteCustomer_clicked()
{
    Customer customer;
    bool isValid = false;
    utils::getCustomer(customer, isValid);
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Phone Number", "No customer exists with that phone number");
        msgBox.exec();
        return;
    }
    CustomerDatabase::deleteCustomer(customer.getPhoneNumber());
    QMessageBox msgBox(QMessageBox::Information, "Customer Deleted", "Customer was deleted");
    msgBox.exec();
}

void AdminView::on_btnListAllCustomers_clicked()
{
    entityListDialog = new EntityListDialog(eCustomer);
    delete entityListDialog;
}
