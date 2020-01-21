#include "Views/customerdialog.h"
#include "ui_customerdialog.h"
#include <QMessageBox>
#include "utils.h"
#include "Database/customerdatabase.h"

CustomerDialog::CustomerDialog(bool creatingNewCustomer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    this->creatingNewCustomer = creatingNewCustomer;
    this->setupDialog();
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::setupDialog()
{
    this->setModal(true);
    if(creatingNewCustomer) ui->btnCancel->setEnabled(false);
    else
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
        ui->txtFirstName->setText(QString::fromStdString(customer.getFirstName()));
        ui->txtLastName->setText(QString::fromStdString(customer.getLastName()));
        ui->txtPhoneNumber->setText(QString::fromStdString(std::to_string(customer.getPhoneNumber())));
        ui->txtPhoneNumber->setEnabled(false);
        ui->txtEmail->setText(QString::fromStdString(customer.getEmail()));
    }
    this->setFixedSize(QSize(440, 240));
    this->exec();
}

void CustomerDialog::on_btnCancel_clicked()
{
    this->close();
}

void CustomerDialog::on_btnSave_clicked()
{
    if(ui->txtFirstName->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid First Name", "The first name can't be empty");
        msgBox.exec();
        return;
    }
    if(ui->txtPhoneNumber->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Phone Number", "The phone number can't be empty");
        msgBox.exec();
        return;
    }
    Customer customer;
    customer.setFirstName(ui->txtFirstName->text().toStdString());
    customer.setLastName(ui->txtLastName->text().toStdString());
    try
    {
        customer.setPhoneNumber(std::stol(ui->txtPhoneNumber->text().toStdString()));
    }
    catch (...)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Phone Number", "Make sure the phone number is a number");
        msgBox.exec();
        return;
    }
    customer.setEmail(ui->txtEmail->text().toStdString());
    if(creatingNewCustomer)
    {
        for(auto& c : CustomerDatabase::getAllCustomers())
        {
            if(customer == c)
            {
                QMessageBox msgBox(QMessageBox::Warning, "Invalid Phone Number", "A customer already exists with that phone number");
                msgBox.exec();
                return;
            }
        }
        CustomerDatabase::addCustomer(customer);
    }
    else CustomerDatabase::updateCustomer(customer);
    this->close();
}
