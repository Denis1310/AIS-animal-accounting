#include "updateanimalform.h"
#include "ui_updateanimalform.h"

UpdateAnimalForm::UpdateAnimalForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateAnimalForm)
{
    ui->setupUi(this);
}

UpdateAnimalForm::~UpdateAnimalForm()
{
    delete ui;
}

void UpdateAnimalForm::todo()
{
    hideFillingControls();
    displayComboBoxes();
    syncData();
}

void UpdateAnimalForm::setValues(QString a_id, QString a_type)
{
   this->animal_id = a_id;
   this->animal_type = a_type;
}

void UpdateAnimalForm::hideFillingControls()
{
   ui->birdInfoGroupBox->hide();
   ui->jointGroupBox->hide();
   ui->pushButton_7->hide();
   ui->reptileInfoGroupBox->hide();
   ui->sampleGroupBox->hide();
}

void UpdateAnimalForm::showFillingControlsForBird()
{
   ui->jointGroupBox->show();
   ui->sampleGroupBox->show();
   ui->birdInfoGroupBox->setGeometry(20,260,171,241);
   ui->birdInfoGroupBox->show();
   ui->pushButton_7->show();


}

void UpdateAnimalForm::showFillingControlsForReptile()
{
   ui->jointGroupBox->show();
   ui->sampleGroupBox->show();
   ui->reptileInfoGroupBox->setGeometry(20,260,171,191);
   ui->reptileInfoGroupBox->show();
   ui->pushButton_7->show();

}

void UpdateAnimalForm::showFillingControlsForMammal()
{
   ui->jointGroupBox->show();
   ui->sampleGroupBox->show();
   ui->pushButton_7->show();
}

void UpdateAnimalForm::syncData()
{

   if (this->animal_type == "Ссавець")
   {
       mammal.syncWithDb(animal_id);
       showFillingControlsForMammal();
       setValuesForMammalControls();
   }
   if (this->animal_type == "Птах")
   {
       bird.syncWithDb(animal_id);
       showFillingControlsForBird();
       setValuesForBirdControls();
   }
   if (this->animal_type == "Рептилія")
   {
       reptile.syncWithDb(animal_id);
       showFillingControlsForReptile();
       setValuesForReptileControls();
   }
}

void UpdateAnimalForm::displayComboBoxes()
{
   int caretakers_count = db.getCaretakersCount();

   for (int i = 0; i <= caretakers_count; ++i)
   {
       ui->caretakerComboBox->addItem(caretaker.getFullNameByID(i));
   }

   int veterinarians_count = db.getVeterinariansCount();

   for (int i = 0; i <= veterinarians_count; ++i)
   {
       ui->veterinarianComboBox->addItem(veterinarian.getFullNameByID(i));
   }

   int rations_count = db.getRationsCount();

   for (int i = 0; i <= rations_count; ++i)
   {
       ui->rationComboBox->addItem(db.getRationNameByID(i));
   }

   int ration_types_count = db.getRationTypesCount();

   for (int i = 0; i <= ration_types_count; ++i)
   {
       ui->rationTypeComboBox->addItem(db.getRationTypeByID(i));
   }

   int living_areas_count = db.getLivingAreasCount();

   for (int i = 0; i <= living_areas_count; ++i)
   {
       ui->livANComboBox->addItem(db.getLivingAreaByID(i));
   }
}

void UpdateAnimalForm::setValuesForReptileControls()
{
   ui->ageText->setPlainText(QString::number(reptile.getAge()));
   ui->identifierText->setPlainText(reptile.getID());
   ui->nameText->setPlainText(reptile.getName());
   ui->sexText->setPlainText(reptile.getSex());
   ui->caretakerComboBox->setCurrentText(reptile.getCaretakerName());
   ui->livANComboBox->setCurrentText(reptile.getLivingAreaName());
   ui->rationComboBox->setCurrentText(reptile.getRation());
   ui->rationTypeComboBox->setCurrentText(reptile.getRationType());
   ui->veterinarianComboBox->setCurrentText(reptile.getVeterinarianName());
   ui->avarageTemperatureText->setPlainText(reptile.getAvTemperature());
   ui->endDateRText->setPlainText(reptile.getEndDate());
   ui->stardDateRText->setPlainText(reptile.getStartDate());
}

void UpdateAnimalForm::setValuesForMammalControls()
{
   ui->ageText->setPlainText(QString::number(mammal.getAge()));
   ui->identifierText->setPlainText(mammal.getID());
   ui->nameText->setPlainText(mammal.getName());
   ui->sexText->setPlainText(mammal.getSex());
   ui->caretakerComboBox->setCurrentText(mammal.getCaretakerName());
   ui->livANComboBox->setCurrentText(mammal.getLivingAreaName());
   ui->rationComboBox->setCurrentText(mammal.getRation());
   ui->rationTypeComboBox->setCurrentText(mammal.getRationType());
   ui->veterinarianComboBox->setCurrentText(mammal.getVeterinarianName());
}

void UpdateAnimalForm::setValuesForBirdControls()
{
   ui->identifierText->setPlainText(bird.getID());
   ui->nameText->setPlainText(bird.getName());
   ui->ageText->setPlainText(QString::number(bird.getAge()));
   ui->sexText->setPlainText(bird.getSex());
   ui->caretakerComboBox->setCurrentText(bird.getCaretakerName());
   ui->livANComboBox->setCurrentText(bird.getLivingAreaName());
   ui->rationComboBox->setCurrentText(bird.getRation());
   ui->rationTypeComboBox->setCurrentText(bird.getRationType());
   ui->veterinarianComboBox->setCurrentText(bird.getVeterinarianName());
   ui->countryCodeText->setPlainText(bird.getCountryCode());
   ui->countryNameText->setPlainText(bird.getCountryName());
   ui->endDateBText->setPlainText(bird.getEndDate());
   ui->startDateBText->setPlainText(bird.getStartDate());
}

bool UpdateAnimalForm::isMammalUpdated()
{
   return  mammal.updateAnimal
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

bool UpdateAnimalForm::isReptileUpdated()
{
   return reptile.updateAnimal
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

bool UpdateAnimalForm::isBirdUpdated()
{
   return  bird.updateAnimal
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

void UpdateAnimalForm::on_pushButton_7_clicked()
{
   if (this->animal_type == "Ссавець")
   {
       if (!isMammalUpdated())
       {
           QMessageBox::critical(this, "Помилка", "Помилка під час редагування даних");
       }
       else
       {
           QMessageBox::information(this, "Успіх", "Дані успішно змінені");
           emit displayRelationTables();
           this->close();
       }
   }

   if (this->animal_type == "Рептилія")
   {
       if (!isReptileUpdated())
       {
           QMessageBox::critical(this, "Помилка", "Помилка під час редагування даних");
       }
       else
       {
           QMessageBox::information(this, "Успіх", "Дані успішно змінені");
           emit displayRelationTables();
           this->close();
       }
   }

   if (this->animal_type == "Птах")
   {
       if (!isBirdUpdated())
       {
            QMessageBox::critical(this, "Помилка", "Помилка під час редагування даних");
       }
       else
       {
           QMessageBox::information(this, "Успіх", "Дані успішно змінені");
           emit displayRelationTables();
           this->close();
       }
   }
}


