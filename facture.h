#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQueryModel>

class Facture
{
public:
    Facture();
    Facture(int,int,QString,QString,float,int,float,int);//,int,QString,QString,float,int,float,QString,int);
    int getid_facture();
    int getid_client();
    QString getdate();
    QString getdes();
    float getprix_uni();
    int getquantite();
    float getmontant();
    int gettype();
    void setid_facture(int);
    void setid_client(int);
    void setdate(QString);
    void setdes(QString);
    void setprix_uni(float);
    void setquantite(int);
    void setmontant(float);
    void settype(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *tri_facture_date();
    QSqlQueryModel *tri_facture_id();
    QSqlQueryModel *tri_facture_prix_uni();
    bool recherche_id_facture(int);
    QSqlQueryModel *afficher_recherche_id(int );
    bool recherche_date(QString);
    QSqlQueryModel *afficher_recherche_date(QString);


private:
   int id_facture,id_client,type,quantite;//,id_client,quantite,type; /*1 si achat, 2 si vente*/
   QString des,date_facture;
   float prix_uni,montant;
   //float prix_uni,montant;
   //QString date_facture,des,mail_facture;

};

#endif // FACTURE_H



