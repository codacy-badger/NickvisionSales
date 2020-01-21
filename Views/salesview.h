#ifndef SALESVIEW_H
#define SALESVIEW_H

#include <QDialog>
#include "Entities/user.h"
#include "Views/itemdialog.h"
#include "Views/customerdialog.h"
#include "Views/entitylistdialog.h"
#include "Views/newsaledialog.h"

namespace Ui {
class SalesView;
}

class SalesView : public QDialog
{
    Q_OBJECT

public:
    explicit SalesView(User, QWidget *parent = nullptr);
    ~SalesView();

private slots:
    void on_btnLogout_clicked();
    void on_btnNewSale_clicked();
    void on_btnViewItem_clicked();
    void on_btnListAllItems_clicked();
    void on_btnNewCustomer_clicked();
    void on_btnEditCustomer_clicked();
    void on_btnViewCustomer_clicked();
    void on_btnListAllCustomers_clicked();

private:
    Ui::SalesView *ui;
    User user;
    ItemDialog *itemDialog;
    CustomerDialog *customerDialog;
    EntityListDialog *entityListDialog;
    NewSaleDialog *newSaleDialog;
};

#endif // SALESVIEW_H
