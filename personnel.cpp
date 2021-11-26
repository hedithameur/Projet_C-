#include "personnel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Personnel::Personnel()
{
    id=0;periode_conger=0; nom="";prenom="";mois_conger="";
}
Personnel::Personnel(int id,int periode_conger,QString nom,QString prenom,QString mois_conger)
{
    this->id=id;
    this->periode_conger=periode_conger;
    this->nom=nom;
    this->prenom=prenom;
    this->mois_conger=mois_conger;

}

QString Personnel::getnom(){return nom;}
QString Personnel::getprenom(){return prenom;}
QString Personnel::getmoisconger(){return mois_conger;}
int Personnel::getid(){return id;}
int Personnel::getperiode(){return periode_conger;}

void Personnel::setnom(QString nom){this->nom=nom;}
void Personnel::setprenom(QString prenom){this->prenom=prenom;}
void Personnel::setmoisconger(QString mois_conger){this->mois_conger=mois_conger;}
void Personnel::setid(int id){this->id=id;}
void Personnel::setperiode(int periode_conger){this->periode_conger= periode_conger;}

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


bool Personnel::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO personnel (id,nom,prenom,periode_conger,mois_conger)"
                  "VALUES (:id,:nom,:prenom,:periode_conger,:mois_conger)");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":periode_conger",periode_conger);
    query.bindValue(":mois_conger",mois_conger);

    return query.exec();
}
bool Personnel::modifier()
{

    QSqlQuery query;
    QString rest = QString::number(id);

    query.prepare("UPDATE personnel set nom= :nom, prenom= :prenom,periode_conger= :periode_conger,mois_conger=:mois_conger  where id= :id ");


    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":periode_conger",periode_conger);
    query.bindValue(":mois_conger",mois_conger);


    return query.exec();
}


QSqlQueryModel* Personnel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM personnel");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
         // model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM TACHE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode conger"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Reclamer"));

     return model;
}


bool Personnel::supprimer(int id)
{
    QSqlQuery query;
    QString rest = QString::number(id);

    query.prepare("Delete from personnel where id=:id");
    query.bindValue(":id",id);

    return query.exec();
}

QSqlQueryModel * Personnel::chercherid(int id)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from personnel WHERE id = :id");
query.bindValue(":id",id);
query.exec();
model ->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode Conger"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mois_Conger"));

return model;
}
QSqlQueryModel * Personnel::cherchernomouprenom(QString nom,QString prenom)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from personnel WHERE nom = :nom or prenom=:prenom");
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.exec();
model ->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
// model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM TACHE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode Conger"));

return model;
}

QSqlQueryModel * Personnel::chercherperiode(int periode)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from personnel WHERE periode_conger = :periode_conger");
query.bindValue(":periode_conger",periode);
query.exec();
model ->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
// model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM TACHE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode Conger"));
return model;
}

QSqlQueryModel * Personnel::trierid()
{
QSqlQueryModel * model = new QSqlQueryModel();
model ->setQuery("select * from personnel ORDER BY id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
// model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM TACHE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode Conger"));
return model;
}
QSqlQueryModel * Personnel::triernom()
{
QSqlQueryModel * model = new QSqlQueryModel();
model ->setQuery("select * from personnel ORDER BY nom ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
// model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM TACHE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode Conger"));
return model;
}
QSqlQueryModel * Personnel::trierperiode()
{
QSqlQueryModel * model = new QSqlQueryModel();
model ->setQuery("select * from personnel ORDER BY periode_conger");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
// model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM TACHE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode Conger"));
return model;
}
