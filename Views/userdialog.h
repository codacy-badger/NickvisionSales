#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(bool, bool, QWidget *parent = nullptr);
    ~UserDialog();

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::UserDialog *ui;
    bool creatingNewUser;
    bool mustBeAdmin;
    void setupDialog();
};

#endif // USERDIALOG_H
