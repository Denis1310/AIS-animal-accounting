#include "veterinarian.h"

Veterinarian::Veterinarian()
{

}

Veterinarian::~Veterinarian()
{
    delete this->query;
}

void Veterinarian::addEmployee(QString full_name, QString phone_number, QString date_of_birth)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");


    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "INSERT INTO Veterinarian ("
        "    full_name,"
        "    phone_number,"
        "    date_of_birth"
        ")"
        "VALUES ("
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
        "date_of_birth", date_of_birth
    );
    query->exec();


    this->db.close();

}

void Veterinarian::updateEmployee(int id, QString full_name, QString phone_number, QString date_of_birth)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "UPDATE Veterinarian"
        "    SET "
        "      full_name = :full_name,"
        "      phone_number = :phone_number,"
        "      date_of_birth = :date_of_birth"
        "    WHERE caretaker_id = :caretaker_id;"
    );
    query->bindValue(
        ":full_name", full_name
    );
    query->bindValue(
        ":phone_number", phone_number
    );
    query->bindValue(
        "date_of_birth", date_of_birth
    );
    query->bindValue(
        ":caretaker_id", id
    );
    query->exec();


    this->db.close();
}

void Veterinarian::syncWithDb(int id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "SELECT full_name, phone_number, date_of_birth"
        "  FROM Veterinarian"
        "  WHERE veterinarian_id = :id;"
    );
    query->bindValue(
        ":caretaker_id", id
    );
    query->exec();
    query->next();

    full_name = query->value(0).toString();

    phone_number = query->value(1).toString();

    date_of_birth = query->value(2).toString();

    this->db.close();

}
