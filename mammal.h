#include "animal.h"
#ifndef MAMMAL_H
#define MAMMAL_H


class Mammal : public Animal
{
private:
    QSqlDatabase db;
    QSqlQuery *query;

public:
    Mammal();
    ~Mammal();
    void addAnimal(QString,QString,int,QString,QString,QString,
                   QString,QString,QString,QString);
    void updateAnimal(QString,QString,int,QString,QString,QString,
                   QString,QString,QString,QString);
    void delAnimal(QString);
    void syncWithDb(QString);
};

#endif // MAMMAL_H
