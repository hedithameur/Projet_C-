#ifndef FACTURE_H
#define FACTURE_H
#include <QString>

class Facture
{
public:
    Facture();
    Facture(int,int,QString,QString,int,QString,QString,float,int,float,QString);
    int getid_facture();
    int getid_client();
    QString getnom();
    QString getprenom();
    int getcin();
    QString getdate();
    QString getdes();
    float getprix_uni();
    int getquantite();
    float getmontant();
    QString getmail();
    void setid_facture(int);
    void setid_client(int);
    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    void setdate(QString);
    void setdes(QString);
    void setprix_uni(float);
    void setquantite(int);
    void setmontant(float);
    void setmail(QString);

private:
   int id_facture,id_client,cin,quantite;
   float prix_uni,montant;
   QString date,des,mail,nom,prenom;

};

#endif // FACTURE_H
