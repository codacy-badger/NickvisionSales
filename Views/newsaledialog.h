#ifndef NEWSALEDIALOG_H
#define NEWSALEDIALOG_H

#include <QDialog>
#include "Entities/receipt.h"
#include "Views/entitylistdialog.h"

namespace Ui {
class NewSaleDialog;
}

class NewSaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewSaleDialog(Customer, QWidget *parent = nullptr);
    ~NewSaleDialog();

private slots:
    void on_btnCloseSale_clicked();
    void on_btnListAllItems_clicked();
    void on_btnAddItem_clicked();
    void on_btnRemoveItem_clicked();
    void on_btnCheckout_clicked();

private:
    Ui::NewSaleDialog *ui;
    Receipt receipt;
    EntityListDialog *entityListDialog;
    void updateListAllItems();
};

#endif // NEWSALEDIALOG_H
