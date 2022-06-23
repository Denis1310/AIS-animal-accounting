#include "bird.h"

Bird::Bird()
{

}

Bird::~Bird()
{
    delete this->query;
}

bool Bird::addAnimal(QString id, QString name, int age, QString sex, QString country_code, QString country_name,QString start_date, QString end_date, QString la_name, QString caretaker_name, QString veterinarian_name,QString ration, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
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
        "    start_date,"
        "    end_date,"
        "    fk_l_a_id,"
        "    fk_c_id,"
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

        return !query->lastError().isValid();
    }
    else return false;
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

bool Bird::updateAnimal(QString id, QString name, int age, QString sex, QString country_code, QString country_name,QString start_date, QString end_date, QString la_name, QString caretaker_name, QString veterinarian_name,QString ration, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        this->query = new QSqlQuery();

        query->prepare(
            "UPDATE Bird "
            " SET "
            "   name = :name, "
            "   age = :age, "
            "   country_code = :country_code, "
            "   country_name = :country_name, "
            "   start_date = :start_date, "
            "   end_date = :end_date, "
            "   sex = :sex, "
            "   fk_l_a_id = "
            "   (SELECT living_area_id FROM LivingArea "
            "   WHERE living_area_name = :living_area_name), "
            "   fk_c_id = "
            "   (SELECT caretaker_id FROM Caretaker "
            "   WHERE full_name = :caretaker_fn), "
            "   fk_v_id = "
            "   (SELECT veterinarian_id FROM Veterinarian "
            "   WHERE full_name = :veterinarian_fn), "
            "   fk_r_n_id = "
            "   (SELECT ration_id FROM Ration "
            "   WHERE ration_name = :ration_name),"
            "   fk_r_t_id = "
            "   (SELECT ration_type_id FROM RationType "
            "   WHERE ration_type_name = :ration_type_name)"
            " WHERE identifier = :identifier;"
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
            ":caretaker_fn", caretaker_name
        );
        query->bindValue(
            ":veterinarian_fn", veterinarian_name
        );
        query->bindValue(
            ":ration_name", ration
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

bool Bird::delAnimal(QString id)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (this->db.open() == true)
    {
        query = new QSqlQuery();
        query->exec(
            "DELETE FROM Bird WHERE identifier = " + id + ";"
        );
            this->db.close();
        return !query->lastError().isValid();
    }
    else return false;
}

void Bird::syncWithDb(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");
    this->db.open();

    query = new QSqlQuery();
    query->prepare(
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
        "WHERE Bird.identifier = :identifier; "
    );
    query->bindValue(
        ":identifier", id
    );
    query->exec();
    query->next();

    this->id = id;

    name = query->value(0).toString();

    age = query->value(1).toInt();

    wintering_place.country_code = query->value(2).toString();

    wintering_place.country_name = query->value(3).toString();

    wintering_place.start_date = query->value(4).toString();

    wintering_place.end_date = query->value(5).toString();

    sex = query->value(6).toString();

    living_area.name = query->value(7).toString();

    living_area.characteristic = query->value(8).toString();

    caretaker_name = query->value(9).toString();

    veterinarian_name = query->value(10).toString();

    ration = query->value(11).toString();

    ration_type = query->value(12).toString();

    db.close();
}
