#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#ifndef DATABASE_H
#define DATABASE_H

class DataBase
{
private:
    QSqlDatabase db;
    QSqlQuery *query;
    void checkExistsDbFile();
    void directoryCheck();
    bool createDbFile();
    bool fillRationInDb();
    bool fillRationTypeInDb();
    bool fillLivingAreasInDb();

public:
    DataBase();
    ~DataBase();
};

#endif // DATABASE_H
