#include "updateworkersform.h"
#include "ui_updateworkersform.h"

UpdateWorkersForm::UpdateWorkersForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWorkersForm)
{
    ui->setupUi(this);
}

UpdateWorkersForm::~UpdateWorkersForm()
{
    delete ui;
}

void UpdateWorkersForm::setValues(int id, QString type)
{
    this->worker_id = id;
    this->worker_type = type;
}

void UpdateWorkersForm::todo()
{
    syncData();
}

void UpdateWorkersForm::syncData()
{
    if (worker_type == "Доглядач")
    {
        this->caretaker.syncWithDb(worker_id);
        qDebug() << caretaker.getFullName();
        qDebug() << caretaker.getPhoneNumber();
        qDebug() << caretaker.getDateOfBirth();
        setDataForCaretakerControls();
    }

    if (worker_type == "Ветеринар")
    {
        this->veterinarian.syncWithDb(worker_id);
        setDataForVeterinarianControls();
    }

}

void UpdateWorkersForm::setDataForCaretakerControls()
{
    ui->dateOfBirthText->setPlainText(caretaker.getDateOfBirth());
    ui->phoneNumText->setPlainText(caretaker.getPhoneNumber());
    ui->pibText->setPlainText(caretaker.getFullName());
}

void UpdateWorkersForm::setDataForVeterinarianControls()
{
    ui->dateOfBirthText->setPlainText(veterinarian.getDateOfBirth());
    ui->phoneNumText->setPlainText(veterinarian.getPhoneNumber());
    ui->pibText->setPlainText(veterinarian.getFullName());
}


void UpdateWorkersForm::on_pushButton_clicked()
{
    if (worker_type == "Ветеринар")
    {
        if (!isVeterinarianUpdated())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час редагування даних");
        }
        else
        {
            QMessageBox::information(this, "Успіх", "Дані успішно змінені");
            emit displayData();
            this->close();
        }

    }

    if (worker_type == "Доглядач")
    {
        if (!isCaretakerUpdated())
        {
            QMessageBox::critical(this, "Помилка", "Помилка під час редагування даних");
        }
        else
        {
            QMessageBox::information(this, "Успіх", "Дані успішно змінені");
            emit displayData();
            this->close();
        }
    }
}

bool UpdateWorkersForm::isCaretakerUpdated()
{
    return caretaker.updateEmployee
    (
        this->worker_id,
        ui->pibText->toPlainText(),
        ui->phoneNumText->toPlainText(),
        ui->dateOfBirthText->toPlainText()
    );
}

bool UpdateWorkersForm::isVeterinarianUpdated()
{
    return veterinarian.updateEmployee
    (
        this->worker_id,
        ui->pibText->toPlainText(),
        ui->phoneNumText->toPlainText(),
        ui->dateOfBirthText->toPlainText()
    );
}

