#include "employee.h"

Employee::Employee()
{

}

Employee::~Employee()
{
    delete this->query;
}

QString Employee::getFullName()
{
    return this->full_name;
}

QString Employee::getPhoneNumber()
{
    return this->phone_number;
}

QString Employee::getDateOfBirth()
{
    return this->date_of_birth;
}
