#include "Views/loginview.h"
#include "ui_loginview.h"
#include <QMessageBox>
#include <QStyle>
#include <QDesktopWidget>
#include "Database/userdatabase.h"
#include "Views/userdialog.h"
#include "Views/adminview.h"
#include "Views/salesview.h"

LoginView::LoginView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);
    if(!adminExists())
    {
        QMessageBox msgBox(QMessageBox::Information, "First Login", "Welcome to Nickvision Sales\nPlease create an admin user for your POS");
        msgBox.exec();
        userDialog = new UserDialog(true, true);
        delete userDialog;
    }
    this->setFixedSize(QSize(480, 210));
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()));
    ui->lblVersion->setText("Version: 1.0.0");
    this->show();
}

LoginView::~LoginView()
{
    delete ui;
}

bool LoginView::adminExists()
{
    int adminUsers = 0;
    for(auto& user : UserDatabase::getAllUsers())
    {
        if(user.getUserType() == Admin) adminUsers++;
    }
    return adminUsers != 0;
}

void LoginView::on_btnLogin_clicked()
{
    User loginUser;
    int loginID = 0;
    bool validLogin = false;
    try
    {
        loginID = std::stoi(ui->txtLoginID->text().toStdString());
    }
    catch (std::invalid_argument& e)
    {
        ui->txtLoginID->setText("");
        QMessageBox msgBox(QMessageBox::Critical, "Invalid Login ID", "Make sure the login id is a number");
        msgBox.exec();
        return;
    }
    ui->txtLoginID->setText("");
    for(auto& u : UserDatabase::getAllUsers())
    {
        if(u == loginID)
        {
            loginUser = u;
            validLogin = true;
        }
    }
    if(!validLogin)
    {
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Login ID", "No user exists with that login id");
        msgBox.exec();
        return;
    }
    if(loginUser.getUserType() == Admin)
    {
        adminView = new AdminView(loginUser);
        this->hide();
        adminView->exec();
        delete adminView;
        this->show();
    }
    else
    {
        salesView = new SalesView(loginUser);
        this->hide();
        salesView->exec();
        delete salesView;
        this->show();
    }
}
