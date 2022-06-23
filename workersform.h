#ifndef WORKERSFORM_H
#define WORKERSFORM_H

#include <QWidget>
#include "caretaker.h"
#include "veterinarian.h"
#include "updateworkersform.h"
#include "viewanimalsform.h"
#include "database.h"
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class WorkersForm;
}

class WorkersForm : public QWidget
{
    Q_OBJECT

public:
    explicit WorkersForm(QWidget *parent = nullptr);
    void displayCaretakersInRelationTable();
    void displayVeterinariansInRelationTable();
    ~WorkersForm();

private slots:
    void on_pushButton_2_clicked();

    void on_caretakerCheckBox_stateChanged(int arg1);

    void on_veterinariancheckBox_stateChanged(int arg1);

    void on_caretakerCheckBox_2_stateChanged(int arg1);

    void on_veterinariancheckBox_2_stateChanged(int arg1);

    void on_searchButton_clicked();

    void on_updateButton_clicked();

    void on_updateButton_2_clicked();

private:
    Ui::WorkersForm *ui;
    Caretaker caretaker;
    Veterinarian veterinarian;
    DataBase database;
    QSqlRelationalTableModel *model;
    QSqlDatabase db;

    void hideFillingControls();
    void showFillingControls();
    void clearControls();
    bool isVeterinarianAdded();
    bool isCaretakerAdded();
    void hideSearchControls();
    void showSearchControls();
    bool displayCaretakerInRelationTable();
    bool displayVeterinarianInRelationTable();

};

#endif // WORKERSFORM_H
