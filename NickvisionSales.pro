QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database/customerdatabase.cpp \
    Database/itemdatabase.cpp \
    Database/userdatabase.cpp \
    Entities/customer.cpp \
    Entities/item.cpp \
    Entities/receipt.cpp \
    Entities/user.cpp \
    Views/adminview.cpp \
    Views/customerdialog.cpp \
    Views/entitylistdialog.cpp \
    Views/itemdialog.cpp \
    Views/loginview.cpp \
    Views/newsaledialog.cpp \
    Views/salesview.cpp \
    Views/userdialog.cpp \
    main.cpp \
    utils.cpp

HEADERS += \
    Database/customerdatabase.h \
    Database/itemdatabase.h \
    Database/userdatabase.h \
    Entities/customer.h \
    Entities/item.h \
    Entities/receipt.h \
    Entities/user.h \
    Views/adminview.h \
    Views/customerdialog.h \
    Views/entitylistdialog.h \
    Views/itemdialog.h \
    Views/loginview.h \
    Views/newsaledialog.h \
    Views/salesview.h \
    Views/userdialog.h \
    utils.h

FORMS += \
    Views/adminview.ui \
    Views/customerdialog.ui \
    Views/entitylistdialog.ui \
    Views/itemdialog.ui \
    Views/loginview.ui \
    Views/newsaledialog.ui \
    Views/salesview.ui \
    Views/userdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
