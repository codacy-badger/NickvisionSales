#ifndef ENTITYLISTDIALOG_H
#define ENTITYLISTDIALOG_H

#include <QDialog>

namespace Ui {
class EntityListDialog;
}

enum EntityType
{
    eUser,
    eItem,
    eCustomer
};

class EntityListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntityListDialog(EntityType, QWidget *parent = nullptr);
    ~EntityListDialog();

private:
    Ui::EntityListDialog *ui;
    EntityType entityType;
    void setupDialog();
};

#endif // ENTITYLISTDIALOG_H
