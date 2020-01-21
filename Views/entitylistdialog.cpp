#include "Views/entitylistdialog.h"
#include "ui_entitylistdialog.h"
#include "Database/userdatabase.h"
#include "Database/itemdatabase.h"
#include "Database/customerdatabase.h"

EntityListDialog::EntityListDialog(EntityType entityType, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntityListDialog)
{
    ui->setupUi(this);
    this->entityType = entityType;
    this->setupDialog();
}

EntityListDialog::~EntityListDialog()
{
    delete ui;
}

void EntityListDialog::setupDialog()
{
    this->setModal(true);
    ui->table->setColumnCount(4);
    if(entityType == eUser)
    {
        QStringList headerNames;
        headerNames << "First Name" << "Last Name" << "Login ID" << "User Type";
        ui->table->setHorizontalHeaderLabels(headerNames);
        int row;
        for(auto& u : UserDatabase::getAllUsers())
        {
            ui->table->insertRow(ui->table->rowCount());
            row = ui->table->rowCount() - 1;
            ui->table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(u.getFirstName())));
            ui->table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(u.getLastName())));
            ui->table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(u.getLoginID()))));
            if(u.getUserType() == Admin) ui->table->setItem(row, 3, new QTableWidgetItem("Admin"));
            else ui->table->setItem(row, 3, new QTableWidgetItem("Sales"));

        }
    }
    else if(entityType == eItem)
    {
        QStringList headerNames;
        headerNames << "Name" << "Description" << "Item Code" << "Price";
        ui->table->setHorizontalHeaderLabels(headerNames);
        int row;
        for(auto& i : ItemDatabase::getAllItems())
        {
            ui->table->insertRow(ui->table->rowCount());
            row = ui->table->rowCount() - 1;
            ui->table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(i.getName())));
            ui->table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(i.getDescription())));
            ui->table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(i.getItemCode()))));
            ui->table->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(std::to_string(i.getPrice()))));
        }
    }
    else
    {
        QStringList headerNames;
        headerNames << "First Name" << "Last Name" << "Phone Number" << "Email";
        ui->table->setHorizontalHeaderLabels(headerNames);
        int row;
        for(auto& c : CustomerDatabase::getAllCustomers())
        {
            ui->table->insertRow(ui->table->rowCount());
            row = ui->table->rowCount() - 1;
            ui->table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(c.getFirstName())));
            ui->table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c.getLastName())));
            ui->table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(c.getPhoneNumber()))));
            ui->table->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(c.getEmail())));
        }
    }
    this->setFixedSize(QSize(700, 575));
    this->exec();
}
