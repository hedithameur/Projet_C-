#ifndef TACHE_H
#define TACHE_H
#include "personnel.h"

class tache
{
public:
    tache();
    tache(int,QString);


public:

    void setid(int);
    int getid();
    void settache(QString);
    QString gettache();

    bool ajoutertache();
    bool modifiertache();
    QSqlQueryModel* affichertache();
    bool supprimertache(int);
   // bool validtache(int);

private:
    int id;
    QString nom_tache;
};

#endif // TACHE_H
