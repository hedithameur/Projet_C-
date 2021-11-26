#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQueryModel>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "reclamation.h"

class Personnel
{

public:
    Personnel();
    Personnel(int,int,QString,QString,QString);

    int getid();
    QString getnom();
    QString getprenom();
    int getperiode();
    QString getmoisconger();




    void setid(int );
    void setnom(QString );
    void setprenom(QString );
    void setperiode(int);
    void setmoisconger(QString);


    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool valid(int);
    QSqlQueryModel* chercherid(int );
    QSqlQueryModel* cherchernomouprenom(QString,QString );
    QSqlQueryModel* chercherperiode(int );
    QSqlQueryModel* trierid();
    QSqlQueryModel* triernom();
    QSqlQueryModel* trierperiode();

    int Stat_1();
    int Stat_2();
    int Stat_3();


private:
    int id,periode_conger;
    QString nom,prenom,mois_conger;
};

#endif // PERSONNEL_H
