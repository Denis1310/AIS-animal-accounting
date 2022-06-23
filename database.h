#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#include <QSqlError>
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
    int getRationTypesCount();
    int getRationsCount();
    int getLivingAreasCount();
    int getCaretakersCount();
    int getVeterinariansCount();
    QString getRationNameByID(int id);
    QString getRationTypeByID(int id);
    QString getLivingAreaByID(int id);
    QSqlDatabase& getDB();

};

#endif // DATABASE_H
