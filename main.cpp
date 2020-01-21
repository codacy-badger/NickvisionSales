#include "Views/loginview.h"

#include <QApplication>
#include <filesystem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::filesystem::create_directory("POS");
    std::filesystem::create_directory("POS/Users");
    std::filesystem::create_directory("POS/Items");
    std::filesystem::create_directory("POS/Customers");
    std::filesystem::create_directory("POS/Receipts");
    LoginView loginView;
    return a.exec();
}
