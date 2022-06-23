#include "caretaker.h"

QString Caretaker::getFullNameByID(int id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "SELECT full_name FROM Caretaker "
        "WHERE caretaker_id = :id"
    );
    query->bindValue(":id", id);
    query->exec();
    query->next();    
        this->db.close();
    return query->value(0).toString();
}

Caretaker::~Caretaker()
{
    delete this->query;
}

bool Caretaker::addEmployee(QString full_name, QString phone_number, QString date_of_birth)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");


    if (this->db.open() == true)
    {
        query = new QSqlQuery();

        query->prepare(
            "INSERT INTO Caretaker(full_name, phone_number, date_of_birth)"
            "VALUES("
            "    :full_name,"
            "    :phone_number,"
            "    :date_of_birth"
            ");"
        );
        query->bindValue(
            ":full_name", full_name
        );
        query->bindValue(
            ":phone_number", phone_number
        );
        query->bindValue(
            ":date_of_birth", date_of_birth
        );
        query->exec();
            this->db.close();
        query->next();
        return !query->lastError().isValid();
    }
    else return false;
}

bool Caretaker::updateEmployee(int id, QString full_name, QString phone_number, QString date_of_birth)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery();

        query->prepare(
            "UPDATE Caretaker "
            "SET "
            "full_name = :full_name, "
            "phone_number = :phone_number, "
            "date_of_birth = :date_of_birth "
            "WHERE caretaker_id = :id; "
        );
        query->bindValue(
            ":id", id
        );
        query->bindValue(
            ":full_name", full_name
        );
        query->bindValue(
            ":phone_number", phone_number
        );
        query->bindValue(
            ":date_of_birth", date_of_birth
        );
        query->exec();
            this->db.close();
        return !query->lastError().isValid();
    }
    else return false;
}

void Caretaker::syncWithDb(int id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

        this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "SELECT full_name, phone_number, date_of_birth "
        "FROM Caretaker "
        "WHERE caretaker_id = :id;"
    );
    query->bindValue(
        ":id", id
    );
    query->exec();
    query->next();

    full_name = query->value(0).toString();

    phone_number = query->value(1).toString();

    date_of_birth = query->value(2).toString();

        this->db.close();
}









