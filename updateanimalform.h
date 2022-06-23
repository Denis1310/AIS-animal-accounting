#ifndef UPDATEANIMALFORM_H
#define UPDATEANIMALFORM_H

#include <QDialog>
#include "bird.h"
#include "mammal.h"
#include "reptile.h"
#include "database.h"
#include "veterinarian.h"
#include "workersform.h"
#include "animal.h"
#include "caretaker.h"
#include "animalsform.h"

namespace Ui {
class UpdateAnimalForm;
}

class UpdateAnimalForm : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateAnimalForm(QWidget *parent = nullptr);

     ~UpdateAnimalForm();

public:
     void setValues(QString a_id,QString a_type);
     void todo();

signals:
     void displayRelationTables();

private slots:
     void on_pushButton_7_clicked();

private:
    Ui::UpdateAnimalForm *ui;
    Bird bird;
    Reptile reptile;
    Mammal mammal;
    Caretaker caretaker;
    Veterinarian veterinarian;
    DataBase db;

    void hideFillingControls();
    void showFillingControlsForMammal();
    void showFillingControlsForReptile();
    void showFillingControlsForBird();
    void syncData();
    void displayComboBoxes();
    void setValuesForMammalControls();
    void setValuesForReptileControls();
    void setValuesForBirdControls();
    QString animal_type;
    QString animal_id;
    bool isMammalUpdated();
    bool isReptileUpdated();
    bool isBirdUpdated();

};

#endif // UPDATEANIMALFORM_H
