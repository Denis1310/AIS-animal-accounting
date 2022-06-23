#include "animalsform.h"
#include "ui_animalsform.h"

AnimalsForm::AnimalsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalsForm)
{
    ui->setupUi(this);

    displayMammalsInRelationTable();
    displayReptilesInRelationTable();
    displayBirdsInRelationTable();
    hideFillingControls();
    displayComboBoxes();
    hideSearchControls();
}

AnimalsForm::~AnimalsForm()
{
    delete ui;
    delete this->model;
}

void AnimalsForm::displayMammalsInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Mammal");
    model->setRelation(5, QSqlRelation("LivingArea","living_area_id","living_area_name"));
    model->setRelation(6, QSqlRelation("Caretaker","caretaker_id","full_name"));
    model->setRelation(7, QSqlRelation("Veterinarian","veterinarian_id","full_name"));
    model->setRelation(8, QSqlRelation("Ration","ration_id","ration_name"));
    model->setRelation(9, QSqlRelation("RationType","ration_type_id","ration_type_name"));

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

    model->select();

    ui->mammalsView->setModel(model);

    db.close();

}

void AnimalsForm::displayReptilesInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Reptile");

    model->setRelation(8, QSqlRelation("LivingArea","living_area_id","living_area_name"));
    model->setRelation(9, QSqlRelation("Caretaker","caretaker_id","full_name"));
    model->setRelation(10, QSqlRelation("Veterinarian","veterinarian_id","full_name"));
    model->setRelation(11, QSqlRelation("Ration","ration_id","ration_name"));
    model->setRelation(12, QSqlRelation("RationType","ration_type_id","ration_type_name"));

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

    model->select();

    for (int i = 0; i < 13; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    ui->reptilesView->setModel(model);

    db.close();

}

void AnimalsForm::displayBirdsInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Bird");

    model->setRelation(9, QSqlRelation("LivingArea","living_area_id","living_area_name"));
    model->setRelation(10, QSqlRelation("Caretaker","caretaker_id","full_name"));
    model->setRelation(11, QSqlRelation("Veterinarian","veterinarian_id","full_name"));
    model->setRelation(12, QSqlRelation("Ration","ration_id","ration_name"));
    model->setRelation(13, QSqlRelation("RationType","ration_type_id","ration_type_name"));

    std::string headers[] =
    {
        "ID",
        "Ідентифікатор",
        "Ім'я",
        "Вік",
        "Стать",
        "Код країни",
        "Назва країни",
        "Дата початку",
        "Дата кінця",
        "Зона проживання",
        "Доглядач",
        "Ветеринар",
        "Назва раціону",
        "Тип раціону"
    };

    model->select();

    for (int i = 0; i < 14; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

    ui->birdsView->setModel(model);

    db.close();

}

void AnimalsForm::displayComboBoxes()
{
    int caretakers_count = database.getCaretakersCount();

    for (int i = 0; i <= caretakers_count; ++i)
    {
        ui->caretakerComboBox->addItem(caretaker.getFullNameByID(i));
    }

    int veterinarians_count = database.getVeterinariansCount();

    for (int i = 0; i <= veterinarians_count; ++i)
    {
        ui->veterinarianComboBox->addItem(veterinarian.getFullNameByID(i));
    }

    int rations_count = database.getRationsCount();

    for (int i = 0; i <= rations_count; ++i)
    {
        ui->rationComboBox->addItem(database.getRationNameByID(i));
    }

    int ration_types_count = database.getRationTypesCount();

    for (int i = 0; i <= ration_types_count; ++i)
    {
        ui->rationTypeComboBox->addItem(database.getRationTypeByID(i));
    }

    int living_areas_count = database.getLivingAreasCount();

    for (int i = 0; i <= living_areas_count; ++i)
    {
        ui->livANComboBox->addItem(database.getLivingAreaByID(i));
    }

}

void AnimalsForm::on_mammalCheckBox_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->birdCheckBox->setChecked(false);
        ui->reptileCheckBox->setChecked(false);

        hideFillingControls();
        showFillingControlsForMammal();
    }
    else hideFillingControls();

}

void AnimalsForm::on_birdCheckBox_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->mammalCheckBox->setChecked(false);
        ui->reptileCheckBox->setChecked(false);

        hideFillingControls();
        showFillingControlsForBird();
    }
    else hideFillingControls();

}

void AnimalsForm::on_reptileCheckBox_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        ui->mammalCheckBox->setChecked(false);
        ui->birdCheckBox->setChecked(false);

        hideFillingControls();
        showFillingControlsForReptile();
    }
    else hideFillingControls();

}

void AnimalsForm::hideFillingControls()
{
    ui->jointGroupBox->hide();
    ui->reptileInfoGroupBox->hide();
    ui->birdInfoGroupBox->hide();
    ui->sampleGroupBox->hide();
    ui->pushButton_7->hide();
}

void AnimalsForm::showFillingControlsForMammal()
{
    clearControls();
    ui->jointGroupBox->show();
    ui->sampleGroupBox->setGeometry(190, 20, 261, 191);
    ui->sampleGroupBox->show();
    ui->pushButton_7->show();
}

void AnimalsForm::showFillingControlsForBird()
{
    clearControls();
    ui->jointGroupBox->show();
    ui->birdInfoGroupBox->show();
    ui->sampleGroupBox->setGeometry(370, 20, 261, 191);
    ui->sampleGroupBox->show();
    ui->pushButton_7->show();

}

void AnimalsForm::showFillingControlsForReptile()
{
    clearControls();
    ui->jointGroupBox->show();
    ui->reptileInfoGroupBox->setGeometry(190, 20, 171, 191);
    ui->reptileInfoGroupBox->show();
    ui->sampleGroupBox->setGeometry(370, 20, 261, 191);
    ui->sampleGroupBox->show();
    ui->pushButton_7->show();
}

void AnimalsForm::on_pushButton_7_clicked()
{
   if (ui->mammalCheckBox->isChecked())
   {
        if (!isMammalAdded())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час внесення даних");
        }
        else
        {
             QMessageBox::information(this, "Успіх", "Дані успішно внесені");
             displayMammalsInRelationTable();
             ui->mammalCheckBox->setChecked(false);
             hideFillingControls();
             clearControls();
        }
   }

   if (ui->birdCheckBox->isChecked())
   {
        if (!isBirdAdded())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час внесення даних");
        }
        else
        {
             QMessageBox::information(this, "Успіх", "Дані успішно внесені");
             displayBirdsInRelationTable();
             ui->birdCheckBox->setChecked(false);
             hideFillingControls();
             clearControls();
        }

   }
   if (ui->reptileCheckBox->isChecked())
   {
       if (!isReptileAdded())
       {
           QMessageBox::critical(this, "Помилка", "Помилка під час внесення даних");
       }
       else
       {
            QMessageBox::information(this, "Успіх", "Дані успішно внесені");
            displayReptilesInRelationTable();
            ui->reptileCheckBox->setChecked(false);
            hideFillingControls();
            clearControls();
       }

   }

}

bool AnimalsForm::isReptileAdded()
{
    return reptile.addAnimal
    (
        ui->identifierText->toPlainText(),
        ui->nameText->toPlainText(),
        ui->ageText->toPlainText().toInt(),
        ui->sexText->toPlainText(),
        ui->avarageTemperatureText->toPlainText(),
        ui->stardDateRText->toPlainText(),
        ui->endDateRText->toPlainText(),
        ui->livANComboBox->itemText(ui->livANComboBox->currentIndex()),
        ui->caretakerComboBox->itemText(ui->caretakerComboBox->currentIndex()),
        ui->veterinarianComboBox->itemText(ui->veterinarianComboBox->currentIndex()),
        ui->rationComboBox->itemText(ui->rationComboBox->currentIndex()),
        ui->rationTypeComboBox->itemText(ui->rationComboBox->currentIndex())
    );
}

bool AnimalsForm::isMammalAdded()
{
    return  mammal.addAnimal
    (
        ui->identifierText->toPlainText(),
        ui->nameText->toPlainText(),
        ui->ageText->toPlainText().toInt(),
        ui->sexText->toPlainText(),
        ui->livANComboBox->itemText(ui->livANComboBox->currentIndex()),
        ui->caretakerComboBox->itemText(ui->caretakerComboBox->currentIndex()),
        ui->veterinarianComboBox->itemText(ui->veterinarianComboBox->currentIndex()),
        ui->rationComboBox->itemText(ui->rationComboBox->currentIndex()),
        ui->rationTypeComboBox->itemText(ui->rationComboBox->currentIndex())
    );
}

bool AnimalsForm::isBirdAdded()
{
    return  bird.addAnimal
    (
        ui->identifierText->toPlainText(),
        ui->nameText->toPlainText(),
        ui->ageText->toPlainText().toInt(),
        ui->sexText->toPlainText(),
        ui->countryCodeText->toPlainText(),
        ui->countryNameText->toPlainText(),
        ui->startDateBText->toPlainText(),
        ui->endDateBText->toPlainText(),
        ui->livANComboBox->itemText(ui->livANComboBox->currentIndex()),
        ui->caretakerComboBox->itemText(ui->caretakerComboBox->currentIndex()),
        ui->veterinarianComboBox->itemText(ui->veterinarianComboBox->currentIndex()),
        ui->rationComboBox->itemText(ui->rationComboBox->currentIndex()),
        ui->rationTypeComboBox->itemText(ui->rationComboBox->currentIndex())
    );
}

void AnimalsForm::clearControls()
{
    ui->countryCodeText->setPlainText("");

    ui->countryNameText->setPlainText("");

    ui->endDateBText->setPlainText("");

    ui->startDateBText->setPlainText("");

    ui->ageText->setPlainText("");

    ui->identifierText->setPlainText("");

    ui->nameText->setPlainText("");

    ui->sexText->setPlainText("");

    ui->avarageTemperatureText->setPlainText("");

    ui->endDateRText->setPlainText("");

    ui->stardDateRText->setPlainText("");

    ui->livANComboBox->setCurrentIndex(0);

    ui->rationComboBox->setCurrentIndex(0);

    ui->rationTypeComboBox->setCurrentIndex(0);

    ui->veterinarianComboBox->setCurrentIndex(0);

    ui->caretakerComboBox->setCurrentIndex(0);
}

void AnimalsForm::on_mammalCheckBox_2_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        model = new QSqlRelationalTableModel();
        ui->Viewer->setModel(model);
        ui->reptileCheckBox_2->setChecked(false);
        ui->birdCheckBox_2->setChecked(false);
        showSearchControls();
        ui->searchAnimalGroupBox->setTitle("Ссавець");

    }
    else hideSearchControls();
}

void AnimalsForm::on_birdCheckBox_2_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        model = new QSqlRelationalTableModel();
        ui->Viewer->setModel(model);
        ui->mammalCheckBox_2->setChecked(false);
        ui->reptileCheckBox_2->setChecked(false);
        showSearchControls();
        ui->searchAnimalGroupBox->setTitle("Птах");
    }
    else hideSearchControls();
}

void AnimalsForm::on_reptileCheckBox_2_stateChanged(int arg1)
{
    if (bool(arg1) == true)
    {
        model = new QSqlRelationalTableModel();
        ui->Viewer->setModel(model);
        ui->mammalCheckBox_2->setChecked(false);
        ui->birdCheckBox_2->setChecked(false);
        showSearchControls();
        ui->searchAnimalGroupBox->setTitle("Рептилія");
    }
    else hideSearchControls();
}

void AnimalsForm::hideSearchControls()
{
    ui->deleteButton->hide();
    ui->searchAnimalGroupBox->hide();
    ui->updateButton->hide();
}

void AnimalsForm::showSearchControls()
{
    ui->deleteButton->show();
    ui->searchAnimalGroupBox->show();
    ui->updateButton->show();
}

bool AnimalsForm::displayReptileInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Reptile");

    model->setRelation(8, QSqlRelation("LivingArea","living_area_id","living_area_name"));
    model->setRelation(9, QSqlRelation("Caretaker","caretaker_id","full_name"));
    model->setRelation(10, QSqlRelation("Veterinarian","veterinarian_id","full_name"));
    model->setRelation(11, QSqlRelation("Ration","ration_id","ration_name"));
    model->setRelation(12, QSqlRelation("RationType","ration_type_id","ration_type_name"));

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

    QString condition = "identifier = " + ui->idText->toPlainText();

    model->setFilter(condition);

    model->select();

    for (int i = 0; i < 13; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }

      db.close();
    if (model->rowCount() == 0)
    {
        return false;
    }
    else
    {
         ui->Viewer->setModel(model);
            return true;
    }

}

bool AnimalsForm::displayBirdInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Bird");

    model->setRelation(9, QSqlRelation("LivingArea","living_area_id","living_area_name"));
    model->setRelation(10, QSqlRelation("Caretaker","caretaker_id","full_name"));
    model->setRelation(11, QSqlRelation("Veterinarian","veterinarian_id","full_name"));
    model->setRelation(12, QSqlRelation("Ration","ration_id","ration_name"));
    model->setRelation(13, QSqlRelation("RationType","ration_type_id","ration_type_name"));


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

    model->select();

    for (int i = 0; i < 14; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, QObject::tr(headers[i].c_str()));
    }
    QString condition = "identifier = " + ui->idText->toPlainText();

    model->setFilter(condition);

    db.close();

    if (model->rowCount() == 0)
    {
        return false;
    }
    else
    {
         ui->Viewer->setModel(model);
            return true;
    }
}

bool AnimalsForm::displayMammalInRelationTable()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    db.open();

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("Mammal");

    model->setRelation(5, QSqlRelation("LivingArea","living_area_id","living_area_name"));
    model->setRelation(6, QSqlRelation("Caretaker","caretaker_id","full_name"));
    model->setRelation(7, QSqlRelation("Veterinarian","veterinarian_id","full_name"));
    model->setRelation(8, QSqlRelation("Ration","ration_id","ration_name"));
    model->setRelation(9, QSqlRelation("RationType","ration_type_id","ration_type_name"));

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

    model->select();

    QString condition = "identifier = " + ui->idText->toPlainText();

    model->setFilter(condition);

    db.close();

    if (model->rowCount() == 0)
    {
        return false;
    }
    else
    {
         ui->Viewer->setModel(model);
            return true;
    }

}

void AnimalsForm::on_searchButton_clicked()
{
    if (ui->mammalCheckBox_2->isChecked())
    {
        if (!displayMammalInRelationTable())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час пошуку даних");
        }
    }

    if (ui->birdCheckBox_2->isChecked())
    {
        if (!displayBirdInRelationTable())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час пошуку даних");
        }

    }

    if (ui->reptileCheckBox_2->isChecked())
    {

        if (!displayReptileInRelationTable())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час пошуку даних");
        }
    }

    bool okChecked = ui->reptileCheckBox_2->isChecked() || ui->birdCheckBox_2->isChecked() || ui->mammalCheckBox_2->isChecked();

    if (!okChecked)
    {
        QMessageBox::critical(this, "Помилка", "Тварину не вибрано");
    }
}


void AnimalsForm::on_deleteButton_clicked()
{
    if (model->rowCount() == 0)
    {
        QMessageBox::critical(this, "Помилка", "Неможливо видалити тварину");
    }
    else
    {
       if (ui->mammalCheckBox_2->isChecked())
       {
           if (!mammal.delAnimal(ui->idText->toPlainText()))
           {
               QMessageBox::critical(this, "Помилка", "Неможливо видалити тварину");
           }
           else
           {
              QMessageBox::information(this, "Успіх", "Видалення відбулося");
              displayMammalsInRelationTable();
           }

       }
       if (ui->reptileCheckBox_2->isChecked())
       {
           if (!reptile.delAnimal(ui->idText->toPlainText()))
           {
               QMessageBox::critical(this, "Помилка", "Неможливо видалити тварину");
           }
           else
           {
              QMessageBox::information(this, "Успіх", "Видалення відбулося");
              displayReptilesInRelationTable();
           }
       }
       if (ui->birdCheckBox_2->isChecked())
       {
           if (!bird.delAnimal(ui->idText->toPlainText()))
           {
               QMessageBox::critical(this, "Помилка", "Неможливо видалити тварину");
           }
           else
           {
               QMessageBox::information(this, "Успіх", "Видалення відбулося");
               displayBirdsInRelationTable();
           }

       }

    }

}

void AnimalsForm::on_updateButton_clicked()
{
    if (model->rowCount() == 0)
    {
        QMessageBox::critical(this, "Помилка", "Неможливо редагувати тварину");
    }
    else
    {
        if (ui->mammalCheckBox_2->isChecked())
        {
            UpdateAnimalForm *updateanimalform = new UpdateAnimalForm();
            connect(updateanimalform, &UpdateAnimalForm::displayRelationTables, this, &AnimalsForm::displayMammalsInRelationTable);
            updateanimalform->setValues(ui->idText->toPlainText(), "Ссавець");
            updateanimalform->todo();
            updateanimalform->exec();
            hideSearchControls();
        }

        if (ui->reptileCheckBox_2->isChecked())
        {
            UpdateAnimalForm *updateanimalform = new UpdateAnimalForm();
            connect(updateanimalform, &UpdateAnimalForm::displayRelationTables, this, &AnimalsForm::displayReptilesInRelationTable);
            updateanimalform->setValues(ui->idText->toPlainText(), "Рептилія");
            updateanimalform->todo();
            updateanimalform->exec();
            hideSearchControls();
        }

        if (ui->birdCheckBox_2->isChecked())
        {
            UpdateAnimalForm *updateanimalform = new UpdateAnimalForm();
            connect(updateanimalform, &UpdateAnimalForm::displayRelationTables, this, &AnimalsForm::displayBirdsInRelationTable);
            updateanimalform->setValues(ui->idText->toPlainText(), "Птах");
            updateanimalform->todo();
            updateanimalform->exec();
            hideSearchControls();
         }
    }
}
