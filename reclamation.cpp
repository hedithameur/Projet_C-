#include "reclamation.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Reclamation::Reclamation()
{
    id=0;description="";
}
Reclamation::Reclamation(int id,QString description)
{
    this->id=id;
    this->description=description;
}

void Reclamation::setid(int id)
{
    this->id=id;
}
void Reclamation::setdescription(QString description)
{
    this->description=description;
}
int Reclamation::getid()
{
    return id;
}
QString Reclamation::getdescription()
{
    return description;
}
bool Reclamation::ajouterreclam()
{

    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO reclamation (id,description)"
                  "VALUES (:id,:description)");

    query.bindValue(":id",id);
    query.bindValue(":description",description);


    return query.exec();
}




