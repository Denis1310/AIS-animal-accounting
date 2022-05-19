#include <QString>
#ifndef STRUCTURES_H
#define STRUCTURES_H

struct WinteringPlace
{
    QString country_code;
    QString country_name;
    QString start_date;
    QString end_date;
};

struct LivingArea
{
    QString name;
    QString characteristic;
};

#endif // STRUCTURES_H
