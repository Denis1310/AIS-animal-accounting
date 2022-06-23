#ifndef UPDATEWORKERSFORM_H
#define UPDATEWORKERSFORM_H

#include <QDialog>
#include "veterinarian.h"
#include "caretaker.h"
#include "workersform.h"

namespace Ui {
class UpdateWorkersForm;
}

class UpdateWorkersForm : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateWorkersForm(QWidget *parent = nullptr);
    void setValues(int,QString);
    void todo();

    ~UpdateWorkersForm();

signals:
    void displayData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UpdateWorkersForm *ui;
    Veterinarian veterinarian;
    Caretaker caretaker;
    int worker_id;
    QString worker_type;
    void syncData();
    void setDataForVeterinarianControls();
    void setDataForCaretakerControls();
    bool isVeterinarianUpdated();
    bool isCaretakerUpdated();
};

#endif // UPDATEWORKERSFORM_H
