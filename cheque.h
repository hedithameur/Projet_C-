#ifndef CHEQUE_H
#define CHEQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Cheque
{
public:
    // constructeurs
 Cheque();
 Cheque(QString,int,int,QString,int,int);
 //gt set
 QString get_banque();
 QString set_banque();
 int get_num_cheque ();
 void set_num_cheque (int);
 int get_montant ();
 int set_montant();
 QString get_date ();
 QString set_date ();
 int get_id_client ();
 int set_id_client ();
 int get_endosse ();
 int set_endosse ();

 //Crud
 bool ajouter();
 bool supprimer(int);
 bool modifier(int,QString,int,int);
 QSqlQueryModel * afficher_endosse();
 QSqlQueryModel * afficher_non_endosse();
 QSqlQueryModel * trier();
 QSqlQueryModel * trier2();
 QSqlQueryModel * chercher(QString);

private:
   QString banque;
   int num_cheque ;
   int montant;
   QString date_echeance;
   int id_client;
   int endosse;
};

#endif // CHEQUE_H



