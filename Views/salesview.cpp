#include "Views/salesview.h"
#include "ui_salesview.h"
#include <QMessageBox>
#include "utils.h"
#include "Database/itemdatabase.h"
#include "Database/customerdatabase.h"

SalesView::SalesView(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalesView)
{
    ui->setupUi(this);
    this->user = user;
    this->setModal(true);
    this->setFixedSize(QSize(395, 380));
    ui->lblWelcome->setText(QString::fromStdString("Welcome " + user.getFirstName() + " " + user.getLastName()));
}

SalesView::~SalesView()
{
    delete ui;
}

void SalesView::on_btnLogout_clicked()
{
    this->close();
}

void SalesView::on_btnNewSale_clicked()
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

void SalesView::on_btnViewItem_clicked()
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

void SalesView::on_btnListAllItems_clicked()
{
    entityListDialog = new EntityListDialog(eItem);
    delete entityListDialog;
}

void SalesView::on_btnNewCustomer_clicked()
{
    customerDialog = new CustomerDialog(true);
    delete customerDialog;
}

void SalesView::on_btnEditCustomer_clicked()
{
    customerDialog = new CustomerDialog(false);
    delete customerDialog;
}

void SalesView::on_btnViewCustomer_clicked()
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

void SalesView::on_btnListAllCustomers_clicked()
{
    entityListDialog = new EntityListDialog(eCustomer);
    delete entityListDialog;
}
