#include <QString>
#include <QSqlQuery>
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
    virtual int getID();
    virtual int getAge();
    virtual QString getSex();
    virtual QString getName();
    virtual QString getCaretakerName();
    virtual QString getVeterinarianName();
    virtual QString getLivingAreaName();
    virtual QString getLivingAreaCharacteristic();
    virtual QString getRation();
    virtual QString getRationType();

protected:
    QSqlQuery *query;
    void syncWithDb();
    void setValuesInDb();
};

#endif // ANIMAL_H
