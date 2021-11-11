#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include <QString>
#include<QSqlQueryModel>

class Personnel
{

public:
    Personnel();
    Personnel(int,QString,QString,QString);

    int getid();
    QString getnom();
    QString getprenom();
    QString getPR();



    void setid(int );
    void setnom(QString );
    void setprenom(QString );
    void setPR(QString);


    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool valid(int);

private:
    int id;
    QString nom,prenom,PR;


};

#endif // PERSONNEL_H
