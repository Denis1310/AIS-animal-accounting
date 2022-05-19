#include "mammal.h"

Mammal::Mammal()
{

}

Mammal::~Mammal()
{
    delete this->query;
}

void Mammal::addAnimal(QString id, QString name, int age, QString sex, QString l_a_name, QString l_a_characteristic, QString caretaker_name, QString veterinarian_name, QString ration_name, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "INSERT INTO Mammal"
        "("
        "    identifier, "
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
        "    SELECT living_area_id FROM LivingArea "
        "      WHERE living_area_name = :living_area_name "
        "      AND living_area_charactetistic = :living_area_charactetistic,"
        "    SELECT caretaker_id FROM Caretaker "
        "      WHERE full_name = :caretaker_full_name,"
        "    SELECT veterinarian_id FROM Veterinarian"
        "      WHERE full_name = :veterinarian_full_name,"
        "    SELECT ration_id FROM Ration "
        "      WHERE ration_name  = :ration_name,"
        "    SELECT ration_type_id FROM RationType "
        "      WHERE ration_type_name  = :ration_type_name "
        ");"
    );

    query->bindValue(
        ":identifer", id
    );
    query->bindValue(
        ":name", name
    );
    query->bindValue(
        "age", age
    );
    query->bindValue(
        "sex", sex
    );
    query->bindValue(
        ":living_area_name", l_a_name
    );
    query->bindValue(
        ":living_area_charactetistic",
        l_a_characteristic
    );
    query->bindValue(
        ":caretaker_full_name",
        caretaker_name
    );
    query->bindValue(
        ":veterinarian_full_name",
        veterinarian_name
    );
    query->bindValue(
        ":ration_name", ration_name
    );
    query->bindValue(
        ":ration_type_name", ration_type
    );

    this->db.close();

}

void Mammal::updateAnimal(QString id, QString name, int age, QString sex, QString l_a_name, QString l_a_characteristic, QString caretaker_name, QString veterinarian_name, QString ration_name, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "UPDATE Mammal "
        ""
        "    SET "
        "      name = :name,"
        "      age = :age,"
        "      sex = :sex,"
        "      fk_l_a_id = "
        "      (SELECT living_area_id FROM LivingArea"
        "        WHERE living_area_name = :living_area_name"
        "        AND living_area_characteristic = :living_area_characteristic),"
        "      fk_e_c_id = "
        "      (SELECT caretaker_id FROM Caretaker "
        "        WHERE full_name = :caretaker_fn),"
        "      fk_e_v_id = "
        "      (SELECT veterinarian_id FROM Veterinarian"
        "        WHERE full_name = :veterinarian_fn),"
        "      fk_r_n_id = "
        "      (SELECT ration_id FROM Ration "
        "        WHERE ration_name = :ration_name),"
        "      fk_r_t_id = "
        "      (SELECT ration_type_id FROM RationType "
        "        WHERE ration_type_name = :ration_type_name);"
    );

    query->bindValue(
        ":identifier", id
    );
    query->bindValue(
        ":name", name
    );
    query->bindValue(
        "age", age
    );
    query->bindValue(
        "sex", sex
    );
    query->bindValue(
        ":living_area_name", l_a_name
    );
    query->bindValue(
        ":living_area_charactetistic",
        l_a_characteristic
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

}

void Mammal::delAnimal(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query->prepare("DELETE FROM Mamnal WHERE identifier = :id");
    query->bindValue(":id", id);

    query->exec();

    this->db.close();

}

void Mammal::syncWithDb(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query->prepare(
        "SELECT M.name, M.age, M.sex,"
        "LA.living_area_name, LA.living_area_characteristic,"
        "C.full_name,"
        "V.full_name,"
        "R.ration_name,"
        "RT.ration_type_name"
        "FROM Mammal AS M"
        "JOIN LivingArea AS LA "
        "ON LA.living_area_id = M.fk_l_a_id"
        "JOIN Caretaker AS C"
        "ON C.caretaker_id = M.fk_e_c_id"
        "JOIN Veterinarian AS V"
        "ON V.veterinarian_id = M.fk_e_v_id"
        "JOIN Ration AS R"
        "ON R.ration_id = M.fk_r_n_id"
        "JOIN RationType AS RT"
        "ON RT.ration_type_id = M.fk_r_t_id"
        "WHERE M.identifier = :identifier;"
    );

    query->bindValue(
        ":identifier", id
    );

    query->exec();

    query->next();

    name = query->value(0).toString();

    age = query->value(1).toInt();

    sex = query->value(2).toString();

    living_area.name =
      query->value(3).toString();

    living_area.characteristic =
      query->value(4).toString();

    caretaker_name =
      query->value(5).toString();

    veterinarian_name =
      query->value(6).toString();

    ration = query->value(7).toString();

    ration_type = query->value(8).toString();

    this->db.close();
}

