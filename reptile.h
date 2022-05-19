#include "animal.h"
#ifndef REPTILE_H
#define REPTILE_H


class Reptile : public Animal
{
private:
    QString average_temperature;
    QString wintering_start_date;
    QString wintering_end_date;

public:
    Reptile();
    ~Reptile();
    QString getAvTemperature();
    QString getStartDate();
    QString getEndDate();
    void addAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString,
                   QString,QString,QString,QString);
    void updateAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString,
                      QString,QString,QString,QString);
    void delAnimal(QString);
    void syncWithDb(QString);


private:
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // REPTILE_H
