#include "garage.h"
#include "ui_garage.h"
#include "personnel.h"
#include "tache.h"
#include "reclamation.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include <qglobal.h>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QPainter>

Garage::Garage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Garage)
{
    ui->setupUi(this);


    grand = 999999;
    petit = 100000;
}

Garage::~Garage()
{
    delete ui;
}

void Garage::on_pb_ajouter_2_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString mois_conger=ui->le_mois_2->text();
    int periode_conger=ui->la_periode_2->text().toInt();
    int nombre_perso=ui->le_nombre_2->text().toInt();
    Personnel P(id,periode_conger,nom,prenom,mois_conger,nombre_perso);

    bool test=P.ajouter();
    QMessageBox msgbox;

    if(! P.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}
    else if(test)
    {msgbox.setText("Ajout avec succes.");
        ui->tab_personnel_2->setModel(P.afficher());
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}


void Garage::on_pb_generate_2_clicked()
{
    qsrand(qrand());  ui->le_id_2->setText(QString::number(qrand() % ((grand + 1) - petit) + petit));
}

void Garage::on_pb_mod_2_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString mois_conger=ui->le_mois_2->text();
    int periode_conger=ui->la_periode_2->text().toInt();
    int nombre_perso=ui->le_nombre_2->text().toInt();
    Personnel P2(id,periode_conger,nom,prenom,mois_conger,nombre_perso);


    QMessageBox msgbox;
    bool test=P2.modifier();
    if(! P2.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();
    }

    else if(test)
    {msgbox.setText("Modification avec succes.");
        ui->tab_personnel_2->setModel(P2.afficher());
    }
    else
        msgbox.setText("Echec de modification");

  msgbox.exec();
}

void Garage::on_pb_supp_2_clicked()
{
    Personnel P1;
    P1.setid(ui->le_id_2->text().toInt());
    bool test=P1.supprimer(P1.getid());
    QMessageBox msgBox;

    if(! P1.valid(P1.getid()))
    {
        msgBox.setText("ID n'existe pas");
    msgBox.exec();
    }

   else if(test)
     {   msgBox.setText("Suppression avec succes");
        ui->tab_personnel_2->setModel(P1.afficher());
     }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void Garage::on_Chercher_2_clicked()
{
    if (ui->radioButton_id_2->isChecked())
        {
            int id= ui->chercher_2->text().toInt() ;
            ui->tab_recherche->setModel(P.chercherid(id));
        }
    if (ui->radioButton_periode_2->isChecked())
        {
            int periode_conger= ui->chercher_2->text().toInt() ;
            ui->tab_recherche->setModel(P.chercherperiode(periode_conger));}
    if (ui->radioButton_nom_2->isChecked())
        {
            QString nom= ui->chercher_2->text();
             QString prenom= ui->chercher_2->text();
            ui->tab_recherche->setModel(P.cherchernomouprenom(nom,prenom));

        }
    if (!(ui->radioButton_id_2->isChecked())&&!(ui->radioButton_periode_2->isChecked())&&!((ui->radioButton_nom_2->isChecked())))
    {
            QMessageBox::critical (nullptr, QObject::tr("chercher echouer"),
                                  QObject::tr("connection failed .\n"
                                               "click cancel to exit ."), QMessageBox::Cancel);

    }
}

void Garage::on_trier_2_clicked()
{
    if (ui->radioButton_id_2->isChecked())
        {
            ui->tab_recherche->setModel(P.trierid());
        }
    if (ui->radioButton_periode_2->isChecked())
        {

            ui->tab_recherche->setModel(P.trierperiode());}
    if (ui->radioButton_nom_2->isChecked())
        {
            ui->tab_recherche->setModel(P.triernom());

        }
    if (!(ui->radioButton_id_2->isChecked())&&!(ui->radioButton_periode_2->isChecked())&&!((ui->radioButton_nom_2->isChecked())))
    {
            QMessageBox::critical (nullptr, QObject::tr("chercher echouer"),
                                  QObject::tr("connection failed .\n"
                                               "click cancel to exit ."), QMessageBox::Cancel);
    }
}

void Garage::on_reclamer_2_clicked()
{
    int id=ui->id_rec_2->text().toInt();
    QString description=ui->Description_2->text();

    Reclamation R(id,description);

    bool test=R.ajouterreclam();
    QMessageBox msgbox;

  /*  if(! P.valid(P.getid()))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}*/
    if(test)
    {msgbox.setText("Ajout de reclamation avec succes.");
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}



void Garage::on_ajout_tache_2_clicked()
{int id=ui->id_tache_2->text().toInt();
    QString nom_tache=ui->nom_tache_2->text();
    tache T(id,nom_tache);

    bool test=T.ajoutertache();
    QMessageBox msgbox;

    /*if(! P.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}*/
    if(test)
    {msgbox.setText("Ajout de la tache avec succes.");
        ui->tab_tache_2->setModel(T.affichertache());
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();

}


void Garage::on_mod_tache_2_clicked()
{
    int id=ui->id_tache_2->text().toInt();
    QString nom_tache=ui->nom_tache_2->text();
    tache T(id,nom_tache);

    bool test=T.modifiertache();
    QMessageBox msgbox;

    /*if(! P.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}*/
    if(test)
    {msgbox.setText("Modification de la tache avec succes.");
        ui->tab_tache_2->setModel(T.affichertache());
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}

void Garage::on_supp_tache_2_clicked()
{
    tache T;
    T.setid(ui->id_tache_2->text().toInt());
    bool test=T.supprimertache(T.getid());
    QMessageBox msgBox;

    /*if(! P1.valid(P1.getid()))
    {
        msgBox.setText("ID n'existe pas");
    msgBox.exec();
    }*/

    if(test)
     {   msgBox.setText("Suppression de la tache avec succes");
        ui->tab_tache_2->setModel(T.affichertache());
     }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}






