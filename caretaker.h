#include "employee.h"
#ifndef CARETAKER_H
#define CARETAKER_H

class Caretaker : public Employee
{
private:
    QSqlQuery *query;
public:
    ~Caretaker();
    bool addEmployee(QString,QString,QString) override;
    bool updateEmployee(int,QString,QString,QString) override;
    void syncWithDb(int) override;
    QString getFullNameByID(int id) override;

};

#endif // CARETAKER_H
