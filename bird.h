#include "structures.h"
#include "queries.h"
#include "animal.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#ifndef BIRD_H
#define BIRD_H


class Bird : public Animal
{
private:
    WinteringPlace wintering_place;
    void upValuesInDb();
    QSqlDatabase db;
    QSqlQuery *query;

public:
    Bird();
    ~Bird();
    void addAnimal(QString,QString,QString,
           QString,QString,QString,QString,
           QString,int,QString,QString,QString,
           QString,QString);
    void updateAnimal (QString,QString,QString,
           QString,QString,QString,QString,
           QString,int,QString,QString,QString,
           QString,QString);
    void delAnimal(QString id);
    QString getCountryCode();
    QString getCountryName();
    QString getStartDate();
    QString getEndDate();
    void syncWithDb(QString id);
};

#endif // BIRD_H
