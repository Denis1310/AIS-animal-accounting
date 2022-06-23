#include "veterinarian.h"

Veterinarian::Veterinarian()
{

}

Veterinarian::~Veterinarian()
{
    delete this->query;
}

QString Veterinarian::getFullNameByID(int id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

        this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "SELECT full_name FROM Veterinarian "
        "WHERE veterinarian_id = ?"
    );
    query->addBindValue(id);
    query->exec();
    query->next();
        this->db.close();
    return query->value(0).toString();
}

bool Veterinarian::addEmployee(QString full_name, QString phone_number, QString date_of_birth)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery();

        query->prepare(
            "INSERT INTO Veterinarian ("
            "    full_name,"
            "    phone_number,"
            "    date_of_birth "
            ")"
            "VALUES ("
            "    :full_name,"
            "    :phone_number,"
            "    :date_of_birth "
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
        return !query->lastError().isValid();
    }
    else return false;
}

bool Veterinarian::updateEmployee(int id, QString full_name, QString phone_number, QString date_of_birth)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery();

        query->prepare(
            "UPDATE Veterinarian "
            "SET "
            "full_name = :full_name, "
            "phone_number = :phone_number, "
            "date_of_birth = :date_of_birth "
            "WHERE veterinarian_id = :veterinarian_id;"
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
        query->bindValue(
            ":veterinarian_id", id
        );
        query->exec();
            this->db.close();
        return !query->lastError().isValid();
    }
    else return false;
}

void Veterinarian::syncWithDb(int id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

        this->db.open();
    query = new QSqlQuery();
    query->prepare(
        "SELECT full_name, phone_number, date_of_birth "
        "FROM Veterinarian "
        "WHERE veterinatian_id = :id;"
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

