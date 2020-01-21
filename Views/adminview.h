#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QDialog>
#include "Entities/user.h"
#include "Views/userdialog.h"
#include "Views/itemdialog.h"
#include "Views/customerdialog.h"
#include "Views/entitylistdialog.h"
#include "Views/newsaledialog.h"

namespace Ui {
class AdminView;
}

class AdminView : public QDialog
{
    Q_OBJECT

public:
    explicit AdminView(User, QWidget *parent = nullptr);
    ~AdminView();

private slots:
    void on_btnLogout_clicked();
    void on_btnExitApp_clicked();
    void on_btnNewSale_clicked();
    void on_btnNewUser_clicked();
    void on_btnEditUser_clicked();
    void on_btnViewUser_clicked();
    void on_btnDeleteUser_clicked();
    void on_btnListAllUsers_clicked();
    void on_btnNewItem_clicked();
    void on_btnEditItem_clicked();
    void on_btnViewItem_clicked();
    void on_btnDeleteItem_clicked();
    void on_btnListAllItems_clicked();
    void on_btnNewCustomer_clicked();
    void on_btnEditCustomer_clicked();
    void on_btnViewCustomer_clicked();
    void on_btnDeleteCustomer_clicked();
    void on_btnListAllCustomers_clicked();

private:
    Ui::AdminView *ui;
    User user;
    UserDialog *userDialog;
    ItemDialog *itemDialog;
    CustomerDialog *customerDialog;
    EntityListDialog *entityListDialog;
    NewSaleDialog *newSaleDialog;
};

#endif // ADMINVIEW_H
