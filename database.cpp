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

bool DataBase::createDbFile()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".\\data\\database.db");

    if (db.open() == true)
    {
        this->query = new QSqlQuery();
        query->exec(table_creation_text);
        db.close();
            return true;
    }
    else
    {
        return false;
    }
}

bool DataBase::fillRationInDb()
{
    if (db.open() == true)
    {
        this->query = new QSqlQuery();
        query->exec(fill_ration_text);
        db.close();
            return true;
    }
    else
    {
       return false;
    }
}

bool DataBase::fillRationTypeInDb()
{
    if (db.open() == true)
    {
        this->query = new QSqlQuery();
        query->exec(fill_ration_type_text);
        db.close();
            return true;
    }
    else
    {
       return false;
    }
}

bool DataBase::fillLivingAreasInDb()
{
    if (db.open() == true)
    {
        this->query = new QSqlQuery();
        query->exec(fill_living_area_text);
        db.close();
            return true;
    }
    else
    {
       return false;
    }
}
