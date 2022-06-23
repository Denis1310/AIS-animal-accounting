#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
protected:
    QString full_name;
    QString phone_number;
    QString date_of_birth;

public:
    virtual void syncWithDb(int) = 0;
    virtual bool addEmployee(QString,QString,QString) = 0;
    virtual bool updateEmployee(int,QString,QString,QString) = 0;
    virtual QString getFullNameByID(int id) = 0;
    QString getFullName();
    QString getPhoneNumber();
    QString getDateOfBirth();

protected:
    QSqlDatabase db;

};

#endif // EMPLOYEE_H
