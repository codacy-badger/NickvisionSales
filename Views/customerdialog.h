#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(bool, QWidget *parent = nullptr);
    ~CustomerDialog();

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::CustomerDialog *ui;
    bool creatingNewCustomer;
    void setupDialog();
};

#endif // CUSTOMERDIALOG_H
