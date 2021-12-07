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
    Personnel(int,int,QString,QString,QString,int);

    int getid();
    QString getnom();
    QString getprenom();
    int getperiode();
    QString getmoisconger();
    int getnombreperso();



    void setid(int );
    void setnom(QString );
    void setprenom(QString );
    void setperiode(int);
    void setmoisconger(QString);
    void setnombreperso(int);


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


private:
    int id,periode_conger,nombre_perso;
    QString nom,prenom,mois_conger;
};

#endif // PERSONNEL_H
