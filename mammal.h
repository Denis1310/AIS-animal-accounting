#include "animal.h"
#ifndef MAMMAL_H
#define MAMMAL_H

class Mammal : public Animal
{
private:
    QSqlQuery *query;

public:
    ~Mammal();
    bool addAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString);
    bool updateAnimal(QString,QString,int,QString,QString,QString,QString,QString,QString);
    bool delAnimal(QString) override;
    void syncWithDb(QString) override;
};

#endif // MAMMAL_H
