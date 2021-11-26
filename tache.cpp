#include "personnel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include "tache.h"


tache::tache()
{
    id=0;nom_tache="";

}
tache::tache(int id,QString nom_tache)
{
    this->id=id;
    this->nom_tache=nom_tache;
}
void tache::setid(int id)
{
    this->id=id;
}
void tache::settache(QString nom_tache)
{
    this->nom_tache=nom_tache;
}
int tache::getid()
{
    return id;
}
QString tache::gettache()
{
    return nom_tache;
}

bool tache::ajoutertache()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO tache (id,nom_tache)"
                  "VALUES (:id,:nom_tache)");

    query.bindValue(":id",id);
    query.bindValue(":nom_tache",nom_tache);

    return query.exec();
}

bool tache::modifiertache()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("UPDATE tache set nom_tache = :nom_tache  where id= :id ");

    query.bindValue(":id",id);
    query.bindValue(":nom_tache",nom_tache);
    return query.exec();
}

QSqlQueryModel* tache::affichertache()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM tache");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Tache"));
          return model;
}

bool tache::supprimertache(int id)
{
    QSqlQuery query;
    QString rest = QString::number(id);

    query.prepare("Delete from tache where id=:id");
    query.bindValue(":id",id);

    return query.exec();
}



