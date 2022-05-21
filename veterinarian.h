#include "employee.h"
#ifndef VETERINARIAN_H
#define VETERINARIAN_H


class Veterinarian : public Employee
{
public:
    Veterinarian();
    ~Veterinarian();
    void addEmployee(QString,QString,QString) override;
    void updateEmployee(int,QString,QString,QString) override;
    void syncWithDb(int) override;
};

#endif // VETERINARIAN_H
