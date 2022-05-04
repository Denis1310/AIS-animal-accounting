#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "structures.h"
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
protected:
    int id;
    int age;
    QString sex;
    QString name;
    QString caretaker_name;
    QString veterinarian_name;
    LivingArea living_area;
    QString ration;
    QString ration_type;

public:
    Animal();
    ~Animal();
    void setValues();
    void addAnimal();
    void updateAnimal();
    void delAnimal();
    virtual int getID() = 0;
    virtual int getAge() = 0;
    virtual QString getSex() = 0;
    virtual QString getName() = 0;
    virtual QString getCaretakerName() = 0;
    virtual QString getVeterinarianName() = 0;
    virtual QString getLivingAreaName() = 0;
    virtual QString getLivingAreaCharacteristic() = 0;
    virtual QString getRation() = 0;
    virtual QString getRationType() = 0;

protected:
    QSqlQuery *query;
    void syncWithDb();
    void setValuesInDb();
};

#endif // ANIMAL_H
