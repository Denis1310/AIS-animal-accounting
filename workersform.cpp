#include "workersform.h"
#include "ui_workersform.h"

WorkersForm::WorkersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkersForm)
{
    ui->setupUi(this);
    displayCaretakersInRelationTable();
    displayVeterinariansInRelationTable();
    hideFillingControls();
    hideSearchControls();
}

WorkersForm::~WorkersForm()
{
    delete ui;
    delete this->model;
}

void WorkersForm::on_pushButton_2_clicked()
{
    if (ui->caretakerCheckBox->isChecked())
    {
         if (!isCaretakerAdded())
         {
             QMessageBox::critical(this, "Помилка", "Помилка під час внесення даних");
         }
         else
         {
              QMessageBox::information(this, "Успіх", "Дані успішно внесені");
              displayCaretakersInRelationTable();
              clearControls();
         }
    }
    if (ui->veterinariancheckBox->isChecked())
    {
         if (!isVeterinarianAdded())
         {
             QMessageBox::critical(this, "Помилка", "Помилка під час внесення даних");
         }
         else
         {
              QMessageBox::information(this, "Успіх", "Дані успішно внесені");
              displayVeterinariansInRelationTable();
              clearControls();
         }
    }

}

void WorkersForm::displayCaretakersInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Caretaker");

    std::string headers[] = {"ID", "ПІБ", "Телефон", "Дата народження"};

    for (int i = 0; i < 4; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    model->select();

    ui->caretakersTableView->setModel(model);

    db.close();
}

void WorkersForm::displayVeterinariansInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Veterinarian");

    std::string headers[] = {"ID", "ПІБ", "Телефон", "Дата народження"};

    for (int i = 0; i < 4; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    model->select();

    ui->veterinariansTableView->setModel(model);

    db.close();
}

void WorkersForm::on_caretakerCheckBox_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->veterinariancheckBox->setChecked(false);
        clearControls();
        showFillingControls();
    }
    else
    {
        hideFillingControls();
    }
}

void WorkersForm::on_veterinariancheckBox_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->caretakerCheckBox->setChecked(false);
        clearControls();
        showFillingControls();
    }
    else
    {
        hideFillingControls();
    }
}

void WorkersForm::hideFillingControls()
{
    ui->insertGroupBox->hide();
    ui->pushButton_2->hide();
}

void WorkersForm::showFillingControls()
{
    ui->insertGroupBox->show();
    ui->pushButton_2->show();
}

void WorkersForm::clearControls()
{
    ui->dateOfBirthText->setPlainText("");

    ui->phoneNumText->setPlainText("");

    ui->pibText->setPlainText("");
}

bool WorkersForm::isVeterinarianAdded()
{
    return veterinarian.addEmployee
    (
        ui->pibText->toPlainText(),
        ui->phoneNumText->toPlainText(),
        ui->dateOfBirthText->toPlainText()
    );
}

bool WorkersForm::isCaretakerAdded()
{
    return caretaker.addEmployee
    (
        ui->pibText->toPlainText(),
        ui->phoneNumText->toPlainText(),
        ui->dateOfBirthText->toPlainText()
    );
}

void WorkersForm::on_caretakerCheckBox_2_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->groupBox_6->setTitle("Доглядач");
        model = new QSqlRelationalTableModel();
        ui->employeersViewer->setModel(model);
        ui->veterinariancheckBox_2->setChecked(false);
        showSearchControls();
    }
     else hideSearchControls();
}


void WorkersForm::on_veterinariancheckBox_2_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->groupBox_6->setTitle("Ветеринар");
        model = new QSqlRelationalTableModel();
        ui->employeersViewer->setModel(model);
        ui->caretakerCheckBox_2->setChecked(false);
        showSearchControls();
    }
     else hideSearchControls();
}


void WorkersForm::hideSearchControls()
{
    ui->groupBox_6->hide();
    ui->searchButton->hide();
}

void WorkersForm::showSearchControls()
{
    ui->groupBox_6->show();
    ui->searchButton->show();
}

void WorkersForm::on_searchButton_clicked()
{
    if (ui->caretakerCheckBox_2->isChecked())
    {
        if (!displayCaretakerInRelationTable())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час пошуку даних");
        }
    }

    if (ui->veterinariancheckBox_2->isChecked())
    {
        if (!displayVeterinarianInRelationTable())
        {
             QMessageBox::critical(this, "Помилка", "Помилка під час пошуку даних");
        }
    }

    bool okChecked = ui->caretakerCheckBox_2->isChecked() || ui->veterinariancheckBox_2->isChecked();

    if (!okChecked)
    {
        QMessageBox::critical(this, "Помилка", "Співробітника не вибрано");
    }
}

bool WorkersForm::displayCaretakerInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Caretaker");

    std::string headers[] = {"ID", "ПІБ", "Телефон", "Дата народження"};

    QString condition = "full_name = '" + ui->pibText_2->toPlainText() + "'";
    model->setFilter(condition);
      model->select();
    db.close();

    for (int i = 0; i < 4; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    if (model->rowCount() == 0)
    {
        return false;
    }
    else
    {
         ui->employeersViewer->setModel(model);
            return true;
    }
}

bool WorkersForm::displayVeterinarianInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Veterinarian");

    std::string headers[] = {"ID", "ПІБ", "Телефон", "Дата народження"};

    QString condition = "full_name = '" + ui->pibText_2->toPlainText() + "'";
    model->setFilter(condition);

    model->select();
    db.close();

    for (int i = 0; i < 4; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    if (model->rowCount() == 0)
    {
        return false;
    }
    else
    {
         ui->employeersViewer->setModel(model);
            return true;
    }
}



void WorkersForm::on_updateButton_clicked()
{
    if (model->rowCount() == 0)
    {
        QMessageBox::critical(this, "Помилка", "Неможливо редагувати співробітника");
    }
    else
    {
        if (ui->veterinariancheckBox_2->isChecked())
        {
            UpdateWorkersForm *updateworkersform = new UpdateWorkersForm;
            connect(updateworkersform, &UpdateWorkersForm::displayData, this, &WorkersForm::displayVeterinariansInRelationTable);
            updateworkersform->setValues(model->index(0, 0).data().toInt(), "Ветеринар");
            updateworkersform->todo();
            updateworkersform->exec();
        }

        if (ui->caretakerCheckBox_2->isChecked())
        {
            UpdateWorkersForm *updateworkersform = new UpdateWorkersForm;
            connect(updateworkersform, &UpdateWorkersForm::displayData, this, &WorkersForm::displayCaretakersInRelationTable);
            updateworkersform->setValues(model->index(0, 0).data().toInt(), "Доглядач");
            updateworkersform->todo();
            updateworkersform->exec();
        }

    }


}

void WorkersForm::on_updateButton_2_clicked()
{
    if (model->rowCount() == 0)
    {
        QMessageBox::critical(this, "Помилка", "Неможливо переглянути");
    }
    else
    {
        if (ui->veterinariancheckBox_2->isChecked())
        {
            ViewAnimalsForm *viewanimalsform = new ViewAnimalsForm;
            viewanimalsform->setValues(model->index(0, 0).data().toInt(), "Veterinarian");
            viewanimalsform->todo();
            viewanimalsform->exec();
        }

        if (ui->caretakerCheckBox_2->isChecked())
        {
            ViewAnimalsForm *viewanimalsform = new ViewAnimalsForm;
            viewanimalsform->setValues(model->index(0, 0).data().toInt(), "Caretaker");
            viewanimalsform->todo();
            viewanimalsform->exec();
        }

    }

}

