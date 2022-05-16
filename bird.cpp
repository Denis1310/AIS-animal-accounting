#include "bird.h"

Bird::Bird()
{

}

Bird::~Bird()
{
    delete this->query;
}

void Bird::addAnimal(QString name, QString caretaker_name, QString veterinarian_name, QString la_name,QString la_characteristic, QString ration,QString ration_type, QString id, int age,QString sex, QString country_code, QString country_name,QString start_date, QString end_date)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    db.open();

        this->query = new QSqlQuery();

    query->prepare(
        "INSERT INTO Bird"
        "("
        "    identifier,"
        "    name,"
        "    age,"
        "    sex,"
        "    country_code,"
        "    country_name,"
        "    start_date, "
        "    end_date,"
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
        "    :country_code,"
        "    :country_name,"
        "    :start_date,"
        "    :end_date,"
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
        "      WHERE ration_type_name  = :ration_type_name"
        ");");

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
        ":country_code", country_code
    );
    query->bindValue(
        ":country_name", country_name
    );
    query->bindValue(
        ":start_date", start_date
    );
    query->bindValue(
        ":end_date", end_date
    );
    query->bindValue(
        ":living_area_name", la_name
    );
    query->bindValue(
        ":living_area_characteristic",
          la_characteristic
    );
    query->bindValue(
        ":caretaker_full_name", caretaker_name
    );
    query->bindValue(
        ":veterinarian_full_name", veterinarian_name
    );
    query->bindValue(
        ":ration_name", ration
    );
    query->bindValue(
        ":ration_type_name", ration_type
    );

        query->exec();

    db.close();
}

QString Bird::getCountryCode()
{
    return this->wintering_place.country_code;
}

QString Bird::getCountryName()
{
    return this->wintering_place.country_code;
}

QString Bird::getStartDate()
{
    return this->wintering_place.start_date;
}

QString Bird::getEndDate()
{
    return this->wintering_place.end_date;
}

void Bird::updateAnimal(QString name, QString caretaker_name, QString veterinarian_name, QString la_name,QString la_characteristic, QString ration,QString ration_type, QString id, int age,QString sex, QString country_code, QString country_name,QString start_date, QString end_date)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    this->query = new QSqlQuery();
    query->prepare(
        "UPDATE Bird"
        ""
        "    SET "
        "      name = :name,"
        "      age = :age, "
        "      country_code = :country_code,"
        "      country_name = :country_name,"
        "      start_date = :start_date,"
        "      end_date = :end_date,"
        "      sex = :sex,   "
        "      fk_l_a_id = "
        "      (SELECT living_area_id FROM LivingArea"
        "        WHERE living_area_name = :living_area_name"
        "        AND living_area_characteristic = :living_area_characteristic),"
        "      fk_e_c_id = "
        "      (SELECT caretaker_id FROM Caretaker "
        "        WHERE full_name = :caretaker_fn),"
        "      fk_e_v_id = "
        "      (SELECT veterinarian_id FROM Veterinarian "
        "        WHERE full_name = :veterinarian_fn),"
        "      fk_r_n_id = "
        "      (SELECT ration_id FROM Ration "
        "        WHERE ration_name = :ration_name),"
        "      fk_r_t_id = "
        "      (SELECT ration_type_id FROM RationType "
        "        WHERE ration_type_name = :ration_type_name)"
        "    WHERE identifier = :identifier"
        ";"
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
        ":country_code", country_code
    );
    query->bindValue(
        ":country_name", country_name
    );
    query->bindValue(
        ":start_date", start_date
    );
    query->bindValue(
        ":end_date", end_date
    );
    query->bindValue(
        ":living_area_name", la_name
    );
    query->bindValue(
        ":living_area_characteristic",
          la_characteristic
    );
    query->bindValue(
        ":caretaker_full_name", caretaker_name
    );
    query->bindValue(
        ":veterinarian_full_name", veterinarian_name
    );
    query->bindValue(
        ":ration_name", ration
    );
    query->bindValue(
        ":ration_type_name", ration_type
    );

        query->exec();

    this->db.close();
}

void Bird::delAnimal(QString id)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();
    query->prepare(
        "DELETE FROM Bird "
        "WHERE identifier = :identifier"
    );
    query->bindValue(
        ":identifier", id
    );
        query->exec();

    this->db.close();

}

void Bird::syncWithDb(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    this->db.open();

    query = new QSqlQuery();
    query->prepare(
        "SELECT B.name, B.age, "
        "B.country_code, B.country_name, B.start_date,"
        "B.end_date, B.sex,"
        ""
        "LA.living_area_name, LA.living_area_characteristic,"
        "C.full_name,"
        "V.full_name,"
        "R.ration_name,"
        "RT.ration_type_name"
        "FROM Bird AS B"
        "JOIN LivingArea AS LA "
        "ON LA.living_area_id = B.fk_l_a_id"
        "JOIN Caretaker AS C"
        "ON C.caretaker_id = B.fk_e_c_id"
        "JOIN Veterinarian AS V"
        "ON V.veterinarian_id = B.fk_e_v_id"
        "JOIN Ration AS R"
        "ON R.ration_id = B.fk_r_n_id"
        "JOIN RationType AS RT"
        "ON RT.ration_type_id = B.fk_r_t_id"
        "WHERE B.identifier = :identifier;"
    );

    query->bindValue(":identifier", id);

    query->exec();
    query->next();

    this->id = id;
    name = query->value(2).toString();
    age = query->value(3).toInt();
    wintering_place.country_code =
      query->value(4).toString();
    wintering_place.country_name =
      query->value(5).toString();
    wintering_place.start_date =
      query->value(6).toString();
    wintering_place.end_date =
      query->value(7).toString();
    sex = query->value(8).toString();
    living_area.name =
      query->value(9).toString();
    living_area.characteristic =
      query->value(10).toString();
    caretaker_name = query->value(11).toString();
    veterinarian_name = query->value(12).toString();
    ration = query->value(13).toString();
    ration_type = query->value(14).toString();
}







