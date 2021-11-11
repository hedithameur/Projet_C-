#include "personnel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Personnel::Personnel()
{
    id=0; nom="";prenom="",PR="";
}
Personnel::Personnel(int id,QString nom,QString prenom,QString PR)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->PR=PR;
}

QString Personnel::getnom(){return nom;}
QString Personnel::getprenom(){return prenom;}
int Personnel::getid(){return id;}
QString Personnel::getPR(){return PR;}

void Personnel::setnom(QString nom){this->nom=nom;}
void Personnel::setprenom(QString prenom){this->prenom=prenom;}
void Personnel::setid(int id){this->id=id;}
void Personnel::setPR(QString PR){this->PR=PR;}



bool Personnel::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO personnel (id,nom,prenom)"
                  "VALUES (:id,:nom,:prenom)");

    query.bindValue(0,id);
    query.bindValue(1,nom);
    query.bindValue(2,prenom);


    return query.exec();
}
bool Personnel::modifier()
{

    QSqlQuery query;
    QString rest = QString::number(id);

    query.prepare("UPDATE personnel set nom= :nom, prenom= :prenom where id= :id ");


    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":id",rest);



    return query.exec();
}
bool Personnel::valid(int id)
{
    QSqlQuery* qry=new QSqlQuery;
    QSqlQueryModel* model=new QSqlQueryModel();
     QString idmod = QString::number(id);
    qry->prepare("select * from personnel where id=:id");
    qry->bindValue(":id",idmod);
    qry->exec();
    model->setQuery(*qry);
    if(!model->index(0,0).data().toString().length())
    {
        return false;
    }
    return true;
}

QSqlQueryModel* Personnel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM personnel");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));

     return model;
}
bool Personnel::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from personnel where id=:id");
    query.bindValue(0,id);

    return query.exec();
}
