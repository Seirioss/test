#include "db.h"
#include <QMouseEvent>
#include <QtGui>

DB::DB()
{
}
void DB::CreateDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
      db.setDatabaseName( "./database.db" );
      if( !db.open() )
      {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
      }
      qDebug( "Connected!" );
      QSqlQuery qry;
      qry.prepare( "CREATE TABLE IF NOT EXISTS names (ID INTEGER UNIQUE PRIMARY KEY, Map VARCHAR(30), Major int, PointID int, X VARCHAR(30), Y VARCHAR(30)");
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug() << "Table created!";
}

 void  DB::DataOutput()
{
    QSqlQuery qry;
    qry.prepare( "SELECT * FROM names" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
      {
        qDebug( "Selected!" );
        while(qry.next())
        {
            int id=qry.value(0).toInt();
            QString map=qry.value(1).toString();
            int major=qry.value(2).toInt();
            int pointid=qry.value(3).toInt();
            QString x=qry.value(4).toString();
            QString y=qry.value(5).toString();
            qDebug()<<"ID:"<<id<<""<<"Map:"<<map<<""<<"Major"<<major<<""<<"PointID:"<<pointid<<""<<"X:"<<x<<""<<"Y:"<<y<<endl;}
      }
}

