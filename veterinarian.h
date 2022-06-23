#include "employee.h"
#ifndef VETERINARIAN_H
#define VETERINARIAN_H


class Veterinarian : public Employee
{
private:
    QSqlQuery *query;

public:
    Veterinarian();
    ~Veterinarian();
    bool addEmployee(QString,QString,QString) override;
    bool updateEmployee(int,QString,QString,QString) override;
    void syncWithDb(int) override;
    QString getFullNameByID(int id) override;
};

#endif // VETERINARIAN_H
