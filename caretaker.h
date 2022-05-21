#include "employee.h"
#ifndef CARETAKER_H
#define CARETAKER_H


class Caretaker : public Employee
{
public:
    Caretaker();
    ~Caretaker();
    void addEmployee(QString,QString,QString) override;
    void updateEmployee(int,QString,QString,QString) override;
    void syncWithDb(int) override;

};

#endif // CARETAKER_H
