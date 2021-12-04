
#include "facture.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

Facture::Facture()
{
    id_facture=0;
    id_client=0;
    date_facture="";
    des="";
    prix_uni=0;
    quantite=0;
    montant=0;
    type=0;
}

Facture::Facture(int id_facture,int id_client, QString des,QString date_facture, float prix_uni, int quantite, float montant, int type)//,int id_client,QString date_facture,QString des,float prix_uni,int quantite,float montant,QString mail_facture,int type)
{
    this->id_facture=id_facture;
    this->id_client=id_client;
    this->des=des;
    this->date_facture=date_facture;
    this->prix_uni=prix_uni;
    this->quantite=quantite;
    this->montant=montant;
    this->type=type;

}
int Facture::getid_facture(){return id_facture;}
int Facture::getid_client(){return id_client;}
QString Facture::getdate(){return date_facture;}
QString Facture::getdes(){return des;}
float Facture::getprix_uni(){return prix_uni;}
int Facture::getquantite(){return quantite;}
float Facture::getmontant(){return montant;}
int Facture::gettype(){return type;}
void Facture::setid_facture(int id_facture){this->id_facture=id_facture;}
void Facture::setid_client(int id_client){this->id_client=id_client;}
void Facture::setdate(QString date_facture){this->date_facture=date_facture;}
void Facture::setdes(QString des){this->des=des;}
void Facture::setprix_uni(float prix_uni){this->prix_uni=prix_uni;}
void Facture::setquantite(int quantite){this->quantite=quantite;}
void Facture::setmontant(float montant){this->montant=montant;}
void Facture::settype(int type){this->type=type;}

bool Facture::ajouter(){

    //bool test=false;

    QString id_facture_string=QString::number(id_facture);
    QString id_client_string=QString::number(id_client);
    QString prix_uni_string=QString::number(prix_uni);
    QString quantite_string=QString::number(quantite);
    QString montant_string=QString::number(montant);
    QString type_string=QString::number(type);
    QSqlQuery query;
    query.prepare("INSERT INTO facture_2 (id_facture,id_client,des,date_facture,prix_uni,quantite,montant,type)"
                        "VALUES (:id_facture,:id_client, :des, :date_facture, :prix_uni, :quantite, :montant, :type)");//, :id_client, :date_facture, :des, :prix_uni, :quantite, :montant, :mail_facture, :type)");
        query.bindValue(":id_facture",id_facture_string);
        query.bindValue(":id_client", id_client_string);
        query.bindValue(":des", des);
        query.bindValue(":date_facture", date_facture);
        query.bindValue(":prix_uni", prix_uni_string);
        query.bindValue(":quantite", quantite_string);
        query.bindValue(":montant", montant_string);
        query.bindValue(":type", type_string);

          return query.exec();




     //return test;
}

QSqlQueryModel* Facture::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM facture_2");
         /* model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Salary")); */
            // Si on supprime ces 2 lignes on affichera toute la table facture de la BD
return model;
}


bool Facture::supprimer(int id_facture){
     QSqlQuery query;
         query.prepare("Delete from facture_2 where id_facture=:id_facture");
         query.bindValue(0,id_facture);
    return query.exec();
}








bool Facture::recherche_id_facture(int id)
    {
        QSqlQuery query;
   QString id_string=QString::number(id);
        query.prepare("SELECT * FROM facture_2 WHERE id_facture= :id");
        query.bindValue(":id", id_string);
      return  query.exec();
    }

QSqlQueryModel* Facture::afficher_recherche_id(int id)
   {
       QSqlQueryModel* model= new QSqlQueryModel();
       QString id_string=QString::number(id);

             model->setQuery("SELECT * FROM facture_2 WHERE id_facture="+id_string+";");

       return model;
   }


bool Facture::recherche_date(QString date)
   {
       QMessageBox msgBox;
       QSqlQuery query;

       query.prepare("SELECT * FROM facture_2 WHERE date= :date_facture");
       query.bindValue(":date_facture", date);
       if (query.exec() && query.next())
       {
               return true;
       }
       else
       {
           msgBox.setText("produit inexistant");
           msgBox.exec();
           return false;
       }
   }
QSqlQueryModel* Facture::afficher_recherche_date(QString date)
   {
       QSqlQueryModel* model= new QSqlQueryModel();

             model->setQuery("SELECT * FROM facture_2 WHERE date_facture='"+date+"'");

       return model;
   }
bool Facture::modifier(){

}

