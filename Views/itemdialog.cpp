#include "Views/itemdialog.h"
#include "ui_itemdialog.h"
#include <QMessageBox>
#include "utils.h"
#include "Database/itemdatabase.h"

ItemDialog::ItemDialog(bool creatingNewItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDialog)
{
    ui->setupUi(this);
    this->creatingNewItem = creatingNewItem;
    this->setupDialog();
}

ItemDialog::~ItemDialog()
{
    delete ui;
}

void ItemDialog::setupDialog()
{
    this->setModal(true);
    if(creatingNewItem) ui->btnCancel->setEnabled(false);
    else
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
        ui->txtName->setText(QString::fromStdString(item.getName()));
        ui->txtDescription->setText(QString::fromStdString(item.getDescription()));
        ui->txtItemCode->setText(QString::fromStdString(std::to_string(item.getItemCode())));
        ui->txtItemCode->setEnabled(false);
        ui->txtPrice->setText(QString::fromStdString(std::to_string(item.getPrice())));
    }
    this->setFixedSize(QSize(440, 240));
    this->exec();
}

void ItemDialog::on_btnCancel_clicked()
{
    this->close();
}

void ItemDialog::on_btnSave_clicked()
{
    if(ui->txtName->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Name", "The name can't be empty");
        msgBox.exec();
        return;
    }
    if(ui->txtItemCode->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Item Code", "The item code can't be empty");
        msgBox.exec();
        return;
    }
    if(ui->txtPrice->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Price", "The price can't be empty");
        msgBox.exec();
        return;
    }
    Item item;
    item.setName(ui->txtName->text().toStdString());
    item.setDescription(ui->txtDescription->text().toStdString());
    try
    {
        item.setItemCode(std::stoi(ui->txtItemCode->text().toStdString()));
    }
    catch (...)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Item Code", "Make sure the item code is a number");
        msgBox.exec();
        return;
    }
    try
    {
        item.setPrice(std::stod(ui->txtPrice->text().toStdString()));
    }
    catch (...)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Price", "Make sure the price is a number");
        msgBox.exec();
        return;
    }
    if(creatingNewItem)
    {
        for(auto& i : ItemDatabase::getAllItems())
        {
            if(item == i)
            {
                QMessageBox msgBox(QMessageBox::Warning, "Invalid Item Code", "An item already exists with that item code");
                msgBox.exec();
                return;
            }
        }
        ItemDatabase::addItem(item);
    }
    else ItemDatabase::updateItem(item);
    this->close();
}
