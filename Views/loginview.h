#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QMainWindow>
#include "Views/userdialog.h"
#include "Views/adminview.h"
#include "Views/salesview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginView; }
QT_END_NAMESPACE

class LoginView : public QMainWindow
{
    Q_OBJECT

public:
    LoginView(QWidget *parent = nullptr);
    ~LoginView();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginView *ui;
    UserDialog *userDialog;
    AdminView *adminView;
    SalesView *salesView;
    bool adminExists();
};
#endif // LOGINVIEW_H
