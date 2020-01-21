#include "newsaledialog.h"
#include "ui_newsaledialog.h"
#include <string>
#include <QMessageBox>
#include <QInputDialog>
#include "Database/itemdatabase.h"

NewSaleDialog::NewSaleDialog(Customer customer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSaleDialog)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setFixedSize(QSize(625, 550));
    this->receipt = Receipt(customer);
    this->updateListAllItems();
}

NewSaleDialog::~NewSaleDialog()
{
    delete ui;
}



void NewSaleDialog::on_btnCloseSale_clicked()
{
    this->close();
}

void NewSaleDialog::on_btnListAllItems_clicked()
{
    entityListDialog = new EntityListDialog(eItem);
    delete entityListDialog;
}

void NewSaleDialog::updateListAllItems()
{
    ui->listAllItems->clear();
    for(std::string s : receipt.getReceipt())
    {
        ui->listAllItems->addItem(QString::fromStdString(s));
    }
    ui->lblTotal->setText(QString::fromStdString("Total:\n" + std::to_string(receipt.getTotal())));
}

void NewSaleDialog::on_btnAddItem_clicked()
{
    Item item;
    bool isValid = false;
    if(!ui->txtItemCode->text().isEmpty())
    {
        int itemCode;
        try
        {
            itemCode = std::stoi(ui->txtItemCode->text().toStdString());
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
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Item Code", "No item exists with that item code");
        msgBox.exec();
        return;
    }
    receipt.addItem(item);
    this->updateListAllItems();
    ui->txtItemCode->setText("");
}

void NewSaleDialog::on_btnRemoveItem_clicked()
{
    Item item;
    bool isValid = false;
    if(!ui->txtItemCode->text().isEmpty())
    {
        int itemCode;
        try
        {
            itemCode = std::stoi(ui->txtItemCode->text().toStdString());
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
    if(!isValid)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Item Code", "No item exists with that item code");
        msgBox.exec();
        return;
    }
    receipt.removeItem(item);
    this->updateListAllItems();
    ui->txtItemCode->setText("");
}

void NewSaleDialog::on_btnCheckout_clicked()
{
    double amountGiven = 0;
    bool ok;
    QString txtChangeGive = QInputDialog::getText(0, "Checkout", "Total: " + QString::number(receipt.getTotal()) + "\nEnter Change Given:", QLineEdit::Normal, "", &ok);
    if(ok && !txtChangeGive.isEmpty())
    {
        try
        {
            amountGiven = std::stod(txtChangeGive.toStdString());
        }
        catch (...)
        {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid Change", "Make sure the change is a number");
            msgBox.exec();
            return;
        }
    }
    if(amountGiven < receipt.getTotal())
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Change", "Make sure the change is greater than or equal to the total");
        msgBox.exec();
        return;
    }
    double change = receipt.checkout(amountGiven);
    QMessageBox msgBox(QMessageBox::Information, "Change", "Change: " + QString::number(change));
    msgBox.exec();
    receipt.saveReceipt();
    this->close();
}
