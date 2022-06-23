#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "structures.h"
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
protected:
    QString id;
    int age;
    QString sex;
    QString name;
    QString caretaker_name;
    QString veterinarian_name;
    LivingArea living_area;
    QString ration;
    QString ration_type;

public:
    virtual bool delAnimal(QString) = 0;
    virtual void syncWithDb(QString) = 0;
    QString getID();
    int getAge();
    QString getSex();
    QString getName();
    QString getCaretakerName();
    QString getVeterinarianName();
    QString getLivingAreaName();
    QString getLivingAreaCharacteristic();
    QString getRation();
    QString getRationType();

protected:
    QSqlDatabase db;
};

#endif // ANIMAL_H
