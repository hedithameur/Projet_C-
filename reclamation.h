#ifndef RECLAMATION_H
#define RECLAMATION_H

#include<QString>
#include<QSqlQueryModel>
#include"personnel.h"
class Reclamation
{


public:
    Reclamation();
    Reclamation(int,QString);
    void setid(int);
    void setdescription(QString);
    int getid();
    QString getdescription();
    bool ajouterreclam();

private:
    int id;
    QString description;
};

#endif // RECLAMATION_H
