#include "mammal.h"

Mammal::~Mammal()
{
    delete this->query;
}

bool Mammal::addAnimal(QString id, QString name, int age, QString sex, QString l_a_name, QString caretaker_name, QString veterinarian_name, QString ration_name, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery();

        query->prepare(
            "INSERT INTO Mammal"
            "("
            "    identifier,"
            "    name,"
            "    age,"
            "    sex,"
            "    fk_l_a_id, "
            "    fk_c_id, "
            "    fk_v_id,"
            "    fk_r_n_id,"
            "    fk_r_t_id "
            ")"
            "VALUES "
            "("
            "    :identifier,"
            "    :name,"
            "    :age,"
            "    :sex,"
            "    (SELECT living_area_id FROM LivingArea"
            "      WHERE living_area_name = :living_area_name),"
            "    (SELECT caretaker_id FROM Caretaker "
            "      WHERE full_name = :caretaker_full_name),"
            "    (SELECT veterinarian_id FROM Veterinarian"
            "      WHERE full_name = :veterinarian_full_name),"
            "    (SELECT ration_id FROM Ration "
            "      WHERE ration_name  = :ration_name),"
            "    (SELECT ration_type_id FROM RationType "
            "      WHERE ration_type_name = :ration_type_name)"
            ");"
        );

        query->bindValue(
            ":identifier", id
        );
        query->bindValue(
            ":name", name
        );
        query->bindValue(
            ":age", age
        );
        query->bindValue(
            ":sex", sex
        );
        query->bindValue(
            ":living_area_name", l_a_name
        );
        query->bindValue(
            ":caretaker_full_name", caretaker_name
        );
        query->bindValue(
            ":veterinarian_full_name", veterinarian_name
        );
        query->bindValue(
            ":ration_name", ration_name
        );
        query->bindValue(
            ":ration_type_name", ration_type
        );
        query->exec();
            this->db.close();
        return !query->lastError().isValid();
    }
    else return false;
}

bool Mammal::updateAnimal(QString id, QString name, int age, QString sex, QString l_a_name, QString caretaker_name, QString veterinarian_name, QString ration_name, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery();

        query->prepare(
            "UPDATE Mammal "
            " SET "
            "   name = :name, "
            "   age = :age, "
            "   sex = :sex, "
            "   fk_l_a_id = (SELECT living_area_id FROM LivingArea "
            "     WHERE living_area_name = :living_area_name), "
            "   fk_c_id = (SELECT caretaker_id FROM Caretaker "
            "     WHERE full_name = :caretaker_fn), "
            "   fk_v_id = (SELECT veterinarian_id FROM Veterinarian "
            "     WHERE full_name = :veterinarian_fn), "
            "   fk_r_n_id = (SELECT ration_id FROM Ration "
            "     WHERE ration_name = :ration_name), "
            "   fk_r_t_id = (SELECT ration_type_id FROM RationType "
            "      WHERE ration_type_name = :ration_type_name) "
            "WHERE identifier = :identifier; "
        );

        query->bindValue(
            ":identifier", id
        );
        query->bindValue(
            ":name", name
        );
        query->bindValue(
            ":age", age
        );
        query->bindValue(
            ":sex", sex
        );
        query->bindValue(
            ":living_area_name", l_a_name
        );
        query->bindValue(
            ":caretaker_fn",
            caretaker_name
        );
        query->bindValue(
            ":veterinarian_fn",
            veterinarian_name
        );
        query->bindValue(
            ":ration_name", ration_name
        );
        query->bindValue(
            ":ration_type_name", ration_type
        );

        query->exec();
            this->db.close();
        return !query->lastError().isValid();
    }
    else return false;
}

bool Mammal::delAnimal(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery;

        query->exec("DELETE FROM Mammal WHERE identifier = " + id + ";");
        qDebug() << query->lastError().text();
            this->db.close();
        return !query->lastError().isValid();
    }
    else return false;
}

void Mammal::syncWithDb(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    db.open();
    query = new QSqlQuery();
    query->prepare(
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
        "WHERE Mammal.identifier = :id; "
    );
    query->bindValue(":id", id);
    query->exec();

    query->next();

    this->id = id;

    name = query->value(0).toString();

    age = query->value(1).toInt();

    sex = query->value(2).toString();

    living_area.name = query->value(3).toString();

    living_area.characteristic = query->value(4).toString();

    caretaker_name = query->value(5).toString();

    veterinarian_name = query->value(6).toString();

    ration = query->value(7).toString();

    ration_type = query->value(8).toString();

        this->db.close();
}


