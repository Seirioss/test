#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
class DB
{
public:
    DB();
    static void CreateDataBase();
    static void DataOutput();
};

#endif // DB_H
