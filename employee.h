#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
protected:
    QString full_name;
    QString phone_number;
    QString date_of_birth;

public:
    Employee();
    ~Employee();
    void setValues();
    void addEmployee();
    void updateEmployee();
    virtual QString getFullName() = 0;
    virtual QString getPhoneNumber() = 0;
    virtual QString getDateOfBirth() = 0;

protected:
    QSqlQuery *query;
    void setValuesInDb();
    void syncWithDb();
};

#endif // EMPLOYEE_H
