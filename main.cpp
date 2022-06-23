#include "mainwindow.h"
#include "workersform.h"
#include "database.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DataBase db;

    return a.exec();
}
