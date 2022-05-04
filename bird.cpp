#include "bird.h"

Bird::Bird()
{

}

void Bird::addAnimal(QString name, QString caretaker_name,
  QString veterinarian_name, QString la_name,
  QString la_characteristic, QString ration,
  QString ration_type, QString id, int age,
  QString sex, QString country_code, QString country_name,
  QString start_date, QString end_date)
{
    this->name = name;
    this->caretaker_name = caretaker_name;
    this->veterinarian_name = veterinarian_name;
    this->living_area.name = la_name;
    this->living_area.characteristic = la_characteristic;
    this->ration = ration;
    this->ration_type = ration_type;
    this->id = id;
    this->age = age;
    this->sex = sex;
    this->wintering_place.country_code = country_code;
    this->wintering_place.country_name = country_name;
    this->wintering_place.start_date = start_date;
    this->wintering_place.end_date = end_date;

    // додати реалізацію для встановлення значень в БД


}

QString Bird::getCountryCode()
{
    return this->wintering_place.country_code;
}

QString Bird::getCountryName()
{
    return this->wintering_place.country_code;
}

QString Bird::getStartDate()
{
    return this->wintering_place.start_date;
}

QString Bird::getEndDate()
{
    return this->wintering_place.end_date;
}



