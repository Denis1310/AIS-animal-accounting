#include "reptile.h"

Reptile::Reptile()
{

}

Reptile::~Reptile()
{
    delete this->query;
}

QString Reptile::getAvTemperature()
{
    return this->average_temperature;
}

QString Reptile::getStartDate()
{
    return this->wintering_start_date;
}

QString Reptile::getEndDate()
{
    return this->wintering_end_date;
}

void Reptile::addAnimal(QString id, QString name, int age, QString sex,QString av_temp, QString wint_st_d,QString wint_en_d, QString l_a_name, QString l_a_characteristic, QString caretaker_name, QString veterinarian_name, QString ration_name, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "INSERT INTO Reptile"
        "("
        "    identifier, "
        "    name,"
        "    age,"
        "    sex,"
        "    avarage_temperature,"
        "    wintering_start_date,"
        "    wintering_end_date,"
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
        "    :avarage_temperature,"
        "    :wintering_start_date,"
        "    :wintering_end_date"
        "    SELECT living_area_id FROM LivingArea "
        "      WHERE living_area_name = :living_area_name"
        "      AND living_area_charactetistic = :living_area_charactetistic,"
        "    SELECT caretaker_id FROM Caretaker "
        "      WHERE full_name = :caretaker_full_name,"
        "    SELECT veterinarian_id FROM Veterinarian"
        "      WHERE full_name = :veterinarian_full_name,"
        "    SELECT ration_id FROM Ration "
        "      WHERE ration_name  = :ration_name,"
        "    SELECT ration_type_id FROM RationType "
        "      WHERE ration_type_name  = :ration_type_name"
        ");"
    );
    // : <--> + ?
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
        ":avarage_temperature", av_temp
    );
    query->bindValue(
        ":wintering_start_date", wint_st_d
    );
    query->bindValue(
        ":wintering_end_date", wint_en_d
    );
    query->bindValue(
        ":living_area_name", l_a_name
    );
    query->bindValue(
        ":living_area_characteristic", l_a_characteristic
    );
    query->bindValue(
        ":caretaker_full_name", caretaker_name
    );
    query->bindValue(
        "veterinarian_full_name", veterinarian_name
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

void Reptile::updateAnimal(QString id, QString name, int age, QString sex,QString av_temp, QString wint_st_d,QString wint_en_d, QString l_a_name, QString l_a_characteristic, QString caretaker_name, QString veterinarian_name, QString ration_name, QString ration_type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query->prepare(
        "UPDATE Reptile "
        ""
        "    SET "
        "      name = :name,"
        "      age = :age,"
        "      sex = :sex,"
        "      avarage_temperature = :avarage_temperature,"
        "      wintering_start_date = :wintering_start_date,"
        "      wintering_end_date = : wintering_end_date,"
        "      fk_l_a_id = "
        "      (SELECT living_area_id FROM LivingArea"
        "        WHERE living_area_name = :living_area_name"
        "        AND living_area_characteristic = :living_area_characteristic),"
        "      fk_e_c_id = "
        "      (SELECT caretaker_id FROM Caretaker"
        "        WHERE full_name = :caretaker_fn),"
        "      fk_e_v_id = "
        "      (SELECT veterinarian_id FROM Veterinarian "
        "        WHERE full_name = :veterinarian_fn),"
        "      fk_r_n_id = "
        "      (SELECT ration_id FROM Ration "
        "        WHERE ration_name = :ration_name),"
        "      fk_r_t_id = "
        "      (SELECT ration_type_id FROM RationType"
        "        WHERE ration_type_name = :ration_type_name)"
        ""
        "    WHERE identifier = :identifier"
        ";"
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
        ":avarage_temperature", av_temp
    );
    query->bindValue(
        ":wintering_start_date", wint_st_d
    );
    query->bindValue(
        ":wintering_end_date", wint_en_d
    );
    query->bindValue(
        ":living_area_name", l_a_name
    );
    query->bindValue(
        ":living_area_characteristic", l_a_characteristic
    );
    query->bindValue(
        ":caretaker_full_name", caretaker_name
    );
    query->bindValue(
        "veterinarian_full_name", veterinarian_name
    );
    query->bindValue(
        ":ration_name", ration_name
    );
    query->bindValue(
        ":ration_type_name", ration_type
    );
    query->bindValue(
        ":identifier", id
    );

    query->exec();

    this->db.close();

}

void Reptile::delAnimal(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare("DELETE FROM Reptile WHERE identifier = :identifier");

    query->bindValue(":identifier", id);

    query->exec();

    this->db.close();
}

void Reptile::syncWithDb(QString id)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();

    query = new QSqlQuery();

    query->prepare(
        "SELECT Rpt.name, Rpt.age, Rpt.sex,"
        "Rpt.avarage_temperature, Rpt.wintering_start_date,"
        "Rpt.wintering_end_date,"
        "LA.living_area_name, LA.living_area_characteristic,"
        "C.full_name,"
        "V.full_name,"
        "R.ration_name,"
        "RT.ration_type_name"
        "FROM Reptile AS Rpt"
        "JOIN LivingArea AS LA "
        "ON LA.living_area_id = Rpt.fk_l_a_id"
        "JOIN Caretaker AS C"
        "ON C.caretaker_id = Rpt.fk_e_c_id"
        "JOIN Veterinarian AS V"
        "ON V.veterinarian_id = Rpt.fk_e_v_id"
        "JOIN Ration AS R"
        "ON R.ration_id = Rpt.fk_r_n_id"
        "JOIN RationType AS RT"
        "ON RT.ration_type_id = Rpt.fk_r_t_id"
        "WHERE Rpt.identifier = :identifier;"
    );

    query->bindValue(
        ":identifier", id
    );

    query->exec();

    query->next();

    this->id = id;

    name = query->value(0).toString();

    age = query->value(1).toInt();

    sex = query->value(2).toString();

    average_temperature = query->value(3).toString();

    wintering_start_date = query->value(4).toString();

    wintering_end_date = query->value(5).toString();

    living_area.name =
      query->value(6).toString();

    living_area.characteristic =
      query->value(7).toString();

    caretaker_name = query->value(8).toString();

    veterinarian_name = query->value(9).toString();

    ration = query->value(10).toString();

    ration_type = query->value(11).toString();

    this->db.close();

}

