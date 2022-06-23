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
    ~Reptile();
    QString getAvTemperature();
    QString getStartDate();
    QString getEndDate();
    bool addAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    bool updateAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    bool delAnimal(QString) override;
    void syncWithDb(QString) override;

private:
    QSqlQuery *query;
};

#endif // REPTILE_H
