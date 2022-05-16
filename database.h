#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#include <QSqlError>
#include <QDebug>
#ifndef DATABASE_H
#define DATABASE_H

class DataBase
{
private:
    QSqlDatabase db;
    QSqlQuery *query;
    void checkExistsDbFile();
    void directoryCheck();
    void createDbFile();
    void fillRationInDb();
    void fillRationTypeInDb();
    void fillLivingAreasInDb();

public:
    DataBase();
    ~DataBase();
};

#endif // DATABASE_H
