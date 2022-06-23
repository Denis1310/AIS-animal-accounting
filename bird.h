#include "structures.h"
#include "animal.h"
#ifndef BIRD_H
#define BIRD_H

class Bird : public Animal
{
private:
    WinteringPlace wintering_place;
    QSqlQuery *query;

public:
    Bird();
    ~Bird();
    bool addAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString,QString,QString,QString, QString);
    bool updateAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString,QString,QString,QString, QString);
    bool delAnimal(QString id) override;
    QString getCountryCode();
    QString getCountryName();
    QString getStartDate();
    QString getEndDate();
    void syncWithDb(QString) override;
};

#endif // BIRD_H
