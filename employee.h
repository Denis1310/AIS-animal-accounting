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
    virtual void addEmployee(QString,QString,QString) = 0;
    virtual void updateEmployee(int,QString,QString,QString) = 0;
    virtual void syncWithDb(int) = 0;
    virtual QString getFullName() = 0;
    virtual QString getPhoneNumber() = 0;
    virtual QString getDateOfBirth() = 0;

protected:
    QSqlQuery *query;
    QSqlDatabase db;

};

#endif // EMPLOYEE_H
