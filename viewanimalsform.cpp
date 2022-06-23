#include "viewanimalsform.h"
#include "ui_viewanimalsform.h"

ViewAnimalsForm::ViewAnimalsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAnimalsForm)
{
    ui->setupUi(this);
}

ViewAnimalsForm::~ViewAnimalsForm()
{
    delete ui;
    delete this->model;
}

void ViewAnimalsForm::setValues(int id, QString type)
{
    this->worker_id = id;
    this->worker_type = type;
}

void ViewAnimalsForm::todo()
{
    if (worker_type == "Veterinarian")
    {
        this->worker_full_name = veterinarian.getFullNameByID(worker_id);
        displayMammals();
        displayReptiles();
        displayBirds();
    }

    if (worker_type == "Caretaker")
    {
        this->worker_full_name = caretaker.getFullNameByID(worker_id);
        displayMammals();
        displayReptiles();
        displayBirds();
    }

}

void ViewAnimalsForm::displayReptiles()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlQueryModel();

    model->setQuery(
        "SELECT Reptile.name, Reptile.age, Reptile.sex, "
        "Reptile.avarage_temperature, Reptile.wintering_start_date, "
        "Reptile.wintering_end_date, "
        "LivingArea.living_area_name, LivingArea.living_area_charactetistic, "
        "Caretaker.full_name, "
        "Veterinarian.full_name, "
        "Ration.ration_name, "
        "RationType.ration_type_name "
        "FROM Reptile "
        "JOIN LivingArea "
        "ON LivingArea.living_area_id = Reptile.fk_l_a_id "
        "JOIN Caretaker "
        "ON Caretaker.caretaker_id = Reptile.fk_c_id "
        "JOIN Veterinarian "
        "ON Veterinarian.veterinarian_id = Reptile.fk_v_id "
        "JOIN Ration "
        "ON Ration.ration_id = Reptile.fk_r_n_id "
        "JOIN RationType "
        "ON RationType.ration_type_id = Reptile.fk_r_t_id "
        "WHERE " + worker_type + ".full_name = '" + worker_full_name + "';"
    );

    std::string headers[] =
    {
        "ID",
        "Ідентифікатор",
        "Ім'я",
        "Вік",
        "Стать",
        "Середня температура",
        "Початок зим.сплячки",
        "Кінець зим.сплячки",
        "Зона проживання",
        "Доглядач",
        "Ветеринар",
        "Назва раціону",
        "Тип раціону"
    };

    for (int i = 0; i < 13; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    db.close();
    ui->reptilesView_2->setModel(model);
}

void ViewAnimalsForm::displayBirds()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlQueryModel();

    model->setQuery(
        "SELECT Bird.name, Bird.age, "
        "Bird.country_code, Bird.country_name, Bird.start_date, "
        "Bird.end_date, Bird.sex, "
        "LivingArea.living_area_name, LivingArea.living_area_charactetistic, "
        "Caretaker.full_name, "
        "Veterinarian.full_name, "
        "Ration.ration_name, "
        "RationType.ration_type_name "
        "FROM Bird "
        "JOIN LivingArea "
        "ON LivingArea.living_area_id = Bird.fk_l_a_id "
        "JOIN Caretaker "
        "ON Caretaker.caretaker_id = Bird.fk_c_id "
        "JOIN Veterinarian "
        "ON Veterinarian.veterinarian_id = Bird.fk_v_id "
        "JOIN Ration "
        "ON Ration.ration_id = Bird.fk_r_n_id "
        "JOIN RationType "
        "ON RationType.ration_type_id = Bird.fk_r_t_id "
        "WHERE " + worker_type + ".full_name = '" + worker_full_name + "';"
    );

    std::string headers[] =
    {
        "ID",
        "Ідентифікатор",
        "Ім'я",
        "Вік",
        "Код країни",
        "Назва країни",
        "Дата початку",
        "Дата кінця",
        "Стать",
        "Зона проживання",
        "Доглядач",
        "Ветеринар",
        "Назва раціону",
        "Тип раціону"
    };



    for (int i = 0; i < 14; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    db.close();

    ui->birdsView_2->setModel(model);
}

void ViewAnimalsForm::displayMammals()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlQueryModel();

    model->setQuery(
        "SELECT Mammal.name, Mammal.age, Mammal.sex, "
        "LivingArea.living_area_name, LivingArea.living_area_charactetistic, "
        "Caretaker.full_name, "
        "Veterinarian.full_name, "
        "Ration.ration_name, "
        "RationType.ration_type_name "
        "FROM Mammal "
        "JOIN LivingArea "
        "ON LivingArea.living_area_id = Mammal.fk_l_a_id "
        "JOIN Caretaker "
        "ON Caretaker.caretaker_id = Mammal.fk_c_id "
        "JOIN Veterinarian "
        "ON Veterinarian.veterinarian_id = Mammal.fk_v_id "
        "JOIN Ration "
        "ON Ration.ration_id = Mammal.fk_r_n_id "
        "JOIN RationType "
        "ON RationType.ration_type_id = Mammal.fk_r_t_id "
        "WHERE " + worker_type + ".full_name = '" + worker_full_name + "';"
    );

    std::string headers[] =
    {
        "ID",
        "Ідентифікатор",
        "Ім'я",
        "Вік",
        "Стать",
        "Зона проживання",
        "Доглядач",
        "Ветеринар",
        "Назва раціону",
        "Тип раціону"
    };

    for (int i = 0; i < 10; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    db.close();
    ui->mammalsView_2->setModel(model);
}

void ViewAnimalsForm::on_pushButton_clicked()
{
    this->close();
}

