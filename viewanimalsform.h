#ifndef VIEWANIMALSFORM_H
#define VIEWANIMALSFORM_H

#include <QDialog>
#include "workersform.h"
#include "veterinarian.h"
#include "caretaker.h"
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class ViewAnimalsForm;
}

class ViewAnimalsForm : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAnimalsForm(QWidget *parent = nullptr);
    void setValues(int, QString);
    void todo();
    ~ViewAnimalsForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewAnimalsForm *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    Veterinarian veterinarian;
    Caretaker caretaker;
    int worker_id;
    QString worker_type;
    QString worker_full_name;
    void displayMammals();
    void displayReptiles();
    void displayBirds();
};

#endif // VIEWANIMALSFORM_H
