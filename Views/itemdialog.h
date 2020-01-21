#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include <QDialog>

namespace Ui {
class ItemDialog;
}

class ItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemDialog(bool, QWidget *parent = nullptr);
    ~ItemDialog();

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::ItemDialog *ui;
    bool creatingNewItem;
    void setupDialog();
};

#endif // ITEMDIALOG_H
