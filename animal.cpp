#include "animal.h"

QString Animal::getID()
{
    return this->id;
}

int Animal::getAge()
{
   return this->age;
}

QString Animal::getSex()
{
    return this->sex;
}

QString Animal::getName()
{
    return this->name;
}

QString Animal::getCaretakerName()
{
    return this->caretaker_name;
}

QString Animal::getVeterinarianName()
{
    return this->veterinarian_name;
}

QString Animal::getLivingAreaName()
{
    return this->living_area.name;
}

QString Animal::getLivingAreaCharacteristic()
{
    return this->living_area.characteristic;
}

QString Animal::getRation()
{
    return this->ration;
}

QString Animal::getRationType()
{
    return this->ration_type;
}
