#ifndef ANIMALSFORM_H
#define ANIMALSFORM_H

#include "animal.h"
#include "mammal.h"
#include "reptile.h"
#include "bird.h"
#include "database.h"
#include "caretaker.h"
#include "updateanimalform.h"
#include "veterinarian.h"
#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <iostream>
#include <QMessageBox>
#include "updateanimalform.h"

namespace Ui {
class AnimalsForm;
}

class AnimalsForm : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalsForm(QWidget *parent = nullptr);
    ~AnimalsForm();
    void displayMammalsInRelationTable();
    void displayReptilesInRelationTable();
    void displayBirdsInRelationTable();

private slots:

    void on_mammalCheckBox_stateChanged(int arg1);

    void on_birdCheckBox_stateChanged(int arg1);

    void on_reptileCheckBox_stateChanged(int arg1);

    void on_pushButton_7_clicked();

    void on_mammalCheckBox_2_stateChanged(int arg1);

    void on_birdCheckBox_2_stateChanged(int arg1);

    void on_reptileCheckBox_2_stateChanged(int arg1);

    void on_searchButton_clicked();

    void on_deleteButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::AnimalsForm *ui;
    Mammal mammal;
    Bird bird;
    Reptile reptile;
    Caretaker caretaker;
    Veterinarian veterinarian;
    DataBase database;
    QSqlRelationalTableModel *model;
    QSqlDatabase db;
    void hideFillingControls();
    void hideSearchControls();
    void showFillingControlsForMammal();
    void showFillingControlsForReptile();
    void showFillingControlsForBird();
    void showSearchControls();
    void displayComboBoxes();
    void clearControls();
    void searchAnimalByID(QString id);
    bool displayReptileInRelationTable();
    bool displayMammalInRelationTable();
    bool displayBirdInRelationTable();
    bool isMammalAdded();
    bool isBirdAdded();
    bool isReptileAdded();

};

#endif // ANIMALSFORM_H
