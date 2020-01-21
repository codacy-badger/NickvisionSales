#include "Views/userdialog.h"
#include "ui_userdialog.h"
#include <QMessageBox>
#include "utils.h"
#include "Database/userdatabase.h"

UserDialog::UserDialog(bool creatingNewUser, bool mustBeAdmin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    this->creatingNewUser = creatingNewUser;
    this->mustBeAdmin = mustBeAdmin;
    this->setupDialog();
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::setupDialog()
{
    ui->txtUserType->addItem("Admin");
    ui->txtUserType->addItem("Sales");
    this->setModal(true);
    if(creatingNewUser)
    {
        ui->btnCancel->setEnabled(false);
        if(mustBeAdmin)
        {
            ui->txtUserType->setItemText(0, "Admin");
            ui->txtUserType->setEnabled(false);
        }
    }
    else
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
        ui->txtFirstName->setText(QString::fromStdString(user.getFirstName()));
        ui->txtLastName->setText(QString::fromStdString(user.getLastName()));
        ui->txtLoginID->setText(QString::fromStdString(std::to_string(user.getLoginID())));
        ui->txtLoginID->setEnabled(false);
        if(user.getUserType() == Admin) ui->txtUserType->setCurrentText("Admin");
        else ui->txtUserType->setCurrentText("Sales");
    }
    this->setFixedSize(QSize(440, 240));
    this->exec();
}

void UserDialog::on_btnCancel_clicked()
{
    this->close();
}

void UserDialog::on_btnSave_clicked()
{
    if(ui->txtFirstName->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid First Name", "The first name can't be empty");
        msgBox.exec();
        return;
    }
    if(ui->txtLoginID->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Login ID", "The login id can't be empty");
        msgBox.exec();
        return;
    }
    if(ui->txtUserType->itemText(0).isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid First Name", "The user type can't be empty");
        msgBox.exec();
        return;
    }
    User user;
    user.setFirstName(ui->txtFirstName->text().toStdString());
    user.setLastName(ui->txtLastName->text().toStdString());
    try
    {
        user.setLoginID(std::stoi(ui->txtLoginID->text().toStdString()));
    }
    catch (...)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Login ID", "Make sure the login id is a number");
        msgBox.exec();
        return;
    }
    if(ui->txtUserType->currentText() == "Admin") user.setUserType(Admin);
    else user.setUserType(Sales);
    if(creatingNewUser)
    {
        for(auto& u : UserDatabase::getAllUsers())
        {
            if(user == u)
            {
                QMessageBox msgBox(QMessageBox::Warning, "Invalid Login ID", "A user already exists with that login id");
                msgBox.exec();
                return;
            }
        }
        UserDatabase::addUser(user);
    }
    else UserDatabase::updateUser(user);
    this->close();
}
