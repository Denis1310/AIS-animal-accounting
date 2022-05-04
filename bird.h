#include "structures.h"
#include "animal.h"
#ifndef BIRD_H
#define BIRD_H


class Bird : public Animal
{
private:
    WinteringPlace wintering_place;

public:
    Bird();
    void addAnimal(QString,QString,QString,
           QString,QString,QString,QString,
       QString,int,QString,QString,QString,
                   QString,QString);
    QString getCountryCode();
    QString getCountryName();
    QString getStartDate();
    QString getEndDate();
};

#endif // BIRD_H
