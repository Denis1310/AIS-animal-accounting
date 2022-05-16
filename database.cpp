#include "database.h"
#include "queries.h"

DataBase::~DataBase()
{
    delete this->query;
}

DataBase::DataBase()
{
    checkExistsDbFile();
}

void DataBase::checkExistsDbFile()
{
    QString path = ".\\data\\database.db";

    if (QFile::exists(path) != true)
    {
        directoryCheck();
        createDbFile();
        fillRationInDb();
        fillRationTypeInDb();
        fillLivingAreasInDb();
    }
}

void DataBase::directoryCheck()
{
    QDir directory;
    directory.mkdir(".\\data");
}

void DataBase::createDbFile()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    this->db.open();
    this->query = new QSqlQuery();

    query->exec(
        "CREATE TABLE Caretaker ("
        "    caretaker_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    full_name TEXT CHECK (full_name != ''),"
        "    phone_number TEXT CHECK (phone_number != ''),"
        "    date_of_birth TEXT CHECK (date_of_birth != '')"
        ");"
    );

    query->exec(
        "CREATE TABLE Veterinarian ( "
        "    veterinarian_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    full_name TEXT CHECK (full_name != ''),"
        "    phone_number TEXT CHECK (phone_number != ''),"
        "    date_of_birth TEXT CHECK (date_of_birth != '')"
        "); "
    );

    query->exec(
        "CREATE TABLE LivingArea ( "
        "    living_area_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "    living_area_name TEXT CHECK (living_area_name != ''), "
        "    living_area_charactetistic TEXT CHECK (living_area_charactetistic != '') "
        "); "
    );

    query->exec(
        "CREATE TABLE Ration ("
        "    ration_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    ration_name TEXT CHECK (ration_name != '')"
        ");"
    );

    query->exec(
        "CREATE TABLE RationType ("
        "    ration_type_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    ration_type_name TEXT CHECK (ration_type_name != '')"
        ");"
    );

    query->exec(
        "CREATE TABLE Mammal ("
        "    mammal_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    identifier TEXT CHECK(identifier !=''),"
        "    name TEXT CHECK(name != ''),"
        "    age INTEGER CHECK(age >= 0 AND age < 100),"
        "    sex TEXT CHECK (sex != ''),"
        "    fk_l_a_id INTEGER,"
        "    fk_c_id INTEGER,"
        "    fk_v_id INTEGER,"
        "    fk_r_n_id INTEGER,"
        "    fk_r_t_id INTEGER,"
        "    FOREIGN KEY ( fk_l_a_id )"
        "      REFERENCES LivingArea ( living_area_id ),"
        "    FOREIGN KEY ( fk_c_id )"
        "      REFERENCES Caretaker ( caretaker_id ),"
        "    FOREIGN KEY ( fk_v_id )"
        "      REFERENCES Veterinarian ( veterinarian_id ),"
        "    FOREIGN KEY ( fk_r_n_id )"
        "      REFERENCES Ration ( ration_id ),"
        "    FOREIGN KEY ( fk_r_t_id )"
        "      REFERENCES Ration ( ration_type_id )"
        ");"
    );

    query->exec(
        "CREATE TABLE Bird ("
        "    bird_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    identifier TEXT CHECK(identifier !=''),"
        "    name TEXT CHECK(name != ''),"
        "    age INTEGER CHECK(age >= 0 AND age < 100),"
        "    sex TEXT CHECK (sex != ''),"
        "    country_code TEXT CHECK(country_code != ''),"
        "    country_name TEXT CHECK(country_name != ''),"
        "    start_date TEXT CHECK(start_date != ''),"
        "    end_date TEXT CHECK(end_date != ''),"
        "    fk_l_a_id INTEGER,"
        "    fk_c_id INTEGER,"
        "    fk_v_id INTEGER,"
        "    fk_r_n_id INTEGER,"
        "    fk_r_t_id INTEGER,"
        "    FOREIGN KEY ( fk_l_a_id ) "
        "      REFERENCES LivingArea ( living_area_id ),"
        "    FOREIGN KEY ( fk_c_id ) "
        "      REFERENCES Caretaker ( caretaker_id ),"
        "    FOREIGN KEY ( fk_v_id ) "
        "      REFERENCES Veterinarian ( veterinarian_id ),"
        "    FOREIGN KEY ( fk_r_n_id ) "
        "      REFERENCES Ration ( ration_id ),"
        "    FOREIGN KEY ( fk_r_t_id ) "
        "      REFERENCES Ration ( ration_type_id )"
        ");"
    );

    query->exec(
        "CREATE TABLE Reptile ("
        "    reptile_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    identifier TEXT CHECK(identifier !=''),"
        "    name TEXT CHECK(name != ''),"
        "    age INTEGER CHECK(age >= 0 AND age < 100),"
        "    sex TEXT CHECK (sex != ''),"
        "    avarage_temperature TEXT CHECK (avarage_temperature != ''),"
        "    wintering_start_date TEXT CHECK (wintering_start_date !=''),"
        "    wintering_end_date TEXT CHECK (wintering_end_date !=''),"
        "    fk_l_a_id INTEGER,"
        "    fk_c_id INTEGER,"
        "    fk_v_id INTEGER,"
        "    fk_r_n_id INTEGER,"
        "    fk_r_t_id INTEGER,"
        "    FOREIGN KEY ( fk_l_a_id ) "
        "      REFERENCES LivingArea ( living_area_id ),"
        "    FOREIGN KEY ( fk_c_id ) "
        "      REFERENCES Caretaker ( caretaker_id ),"
        "    FOREIGN KEY ( fk_v_id ) "
        "      REFERENCES Veterinarian ( veterinarian_id ),"
        "    FOREIGN KEY ( fk_r_n_id ) "
        "      REFERENCES Ration ( ration_id ),"
        "    FOREIGN KEY ( fk_r_t_id ) "
        "      REFERENCES Ration ( ration_type_id )"
        ");"
    );

    this->db.close();
}

void DataBase::fillRationInDb()
{
    this->db.open();

    this->query = new QSqlQuery();
    query->exec(
        "INSERT INTO Ration ("
        "    ration_name"
        " ) VALUES"
        "('корм для птахів'), "
        "('корм для ссавців'),"
        "('корм для рептилій');"
    );

    this->db.close();
}

void DataBase::fillRationTypeInDb()
{
    this->db.open();

    this->query = new QSqlQuery();
    query->exec(
        "INSERT INTO RationType ("
        "    ration_type_name"
        ") VALUES"
        "('дитячий'),"
        "('дієтичний'),"
        "('збалансований');"

    );

    this->db.close();
}

void DataBase::fillLivingAreasInDb()
{
    this->db.open();

    this->query = new QSqlQuery();
    query->exec(
        "INSERT INTO LivingArea ("
        "   living_area_name,"
        "   living_area_characteristic,"
        ") VALUES "
        "('1 зона', 'для птахів'),"
        "('2 зона', 'для птахів'),"
        "('3 зона', 'для птахів'),"
        "('4 зона', 'для птахів'),"
        "('5 зона', 'для птахів'),"
        "('6 зона', 'для рептилій'),"
        "('7 зона', 'для рептилій'),"
        "('8 зона', 'для рептилій'),"
        "('9 зона', 'для рептилій'),"
        "('10 зона', 'для рептилій'),"
        "('11 зона', 'для ссавців'),"
        "('12 зона', 'для ссавців'),"
        "('13 зона', 'для ссавців'),"
        "('14 зона', 'для ссавців'),"
        "('15 зона', 'для ссавців'),"
    );

    this->db.close();
}
