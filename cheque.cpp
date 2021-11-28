#include "cheque.h"
#include "mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

Cheque::Cheque()
{
    num_cheque=0;
    montant=0;
    date_echeance="";
    banque="";
    id_client =0;
    endosse =0;
}


Cheque::Cheque(QString banque  , int montant , int num_cheque , QString date_echeance , int id_client,int endosse)
{
    this->banque=banque;
    this->montant=montant;
    this->num_cheque = num_cheque;
    this->date_echeance=date_echeance;
    this->id_client=id_client;
    this->endosse=endosse;
}

 void Cheque::set_num_cheque(int num_cheque)
 {
     this->num_cheque=num_cheque;
 }

 int Cheque::get_num_cheque()
 {
     return num_cheque;
 }
//***************AJOUTER*************************************************************

bool Cheque::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(num_cheque);

    query.prepare("INSERT INTO CHEQUE (banque,montant,num_cheque,date_echeance,id_client,endosse)"
                  "VALUES (:banque,:montant,:num_cheque,:date_echeance,:id_client,:endosse) ");

    query.bindValue(":banque",banque);
    query.bindValue(":montant",montant);
    query.bindValue(":num_cheque",res);
    query.bindValue(":date_echeance",date_echeance);
    query.bindValue(":id_client",id_client);
     query.bindValue(":endosse",endosse);

    return    query.exec();
}



//******************afficher*************************************************************

QSqlQueryModel * Cheque::afficher_endosse()
{

    QSqlQueryModel * model1= new QSqlQueryModel();

    model1->setQuery(" select * from CHEQUE WHERE ENDOSSE=1");
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("num_cheque"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("date_echeance"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("id_client"));

        return model1;


}




QSqlQueryModel * Cheque::afficher_non_endosse()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CHEQUE WHERE ENDOSSE =0 ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_cheque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_echeance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_client"));

        return model;
}

//**************************modifier***********************************************

bool  Cheque::modifier(int num_cheque ,QString date_echeance,int montant,int endosse)
{
        QSqlQuery query;
        QString res= QString::number(num_cheque);

        query.prepare("update CHEQUE set num_cheque=:num_cheque,montant=:montant,date_echeance=:date_echeance,endosse=:endosse where num_cheque=:num_cheque");
        query.bindValue(":num_cheque",res);
        query.bindValue(":montant", montant);
        query.bindValue(":date_echeance",date_echeance);
        query.bindValue(":endosse",endosse);


        return    query.exec();

}

//****************************supprimer**************************
bool Cheque::supprimer(int endosse)
{
    QSqlQuery query;
    QString rest = QString::number(endosse);

    query.prepare("Delete from CHEQUE where NUM_CHEQUE=:num_cheque");
    query.bindValue(":num_cheque",endosse);

    return query.exec();
}
//******************************************trier*********************************

QSqlQueryModel * Cheque::trier()
{
    QSqlQueryModel * model2= new QSqlQueryModel();

    model2->setQuery("select * FROM CHEQUE WHERE ENDOSSE=0 ORDER BY DATE_ECHEANCE");
    model2->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
    model2->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
    model2->setHeaderData(2, Qt::Horizontal, QObject::tr("num_cheque"));
    model2->setHeaderData(3, Qt::Horizontal, QObject::tr("date_echeance"));
    model2->setHeaderData(4, Qt::Horizontal, QObject::tr("id_client"));

    return model2;
}

QSqlQueryModel * Cheque::trier2()
{
    QSqlQueryModel * model2= new QSqlQueryModel();

    model2->setQuery("select * FROM CHEQUE WHERE ENDOSSE=1 ORDER BY DATE_ECHEANCE");
    model2->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
    model2->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
    model2->setHeaderData(2, Qt::Horizontal, QObject::tr("num_cheque"));
    model2->setHeaderData(3, Qt::Horizontal, QObject::tr("date_echeance"));
    model2->setHeaderData(4, Qt::Horizontal, QObject::tr("id_client"));

    return model2;
}

//****************************recherche***************************


QSqlQueryModel * Cheque ::chercher(int num_cheque)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from CHEQUE WHERE NUM_CHEQUE = :num_cheque");
query.bindValue(":num_cheque",num_cheque);
query.exec();
model ->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_cheque"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_echeance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_client"));

return model;
}

QSqlQueryModel * Cheque ::chercher2(QString banque)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from CHEQUE WHERE BANQUE = :banque");
query.bindValue(":banque",banque);
query.exec();
model ->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_cheque"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_echeance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_client"));

return model;
}






