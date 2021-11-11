#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "personnel.h"
#include <QMessageBox>
#include <QIntValidator>
#include <qglobal.h>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grand = 999999;
    petit = 100000;
    ui->le_id->setValidator( new QIntValidator(00, 999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator *car= new QRegExpValidator(rxNom,this);
    ui->le_nom->setValidator(car);
    ui->le_prenom->setValidator(car);


ui->tab_personnel->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Personnel P(id,nom,prenom);

    bool test=P.ajouter();
    QMessageBox msgbox;

    if(test)
    {msgbox.setText("Ajout avec succes.");
        ui->tab_personnel->setModel(P.afficher());
    }
    /*else (ui->le_id==NULL);
        {msgbox.setText("Il faut ajouter un identifiant");}*/
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}
void MainWindow::on_pb_generate_clicked()
{
    qsrand(qrand());
    ui->le_id->setText(QString::number(qrand() % ((grand + 1) - petit) + petit));
}


void MainWindow::on_pb_mod_clicked()
{
    int id=ui->id_mod->text().toInt();
    QString nom=ui->nom_mod->text();
    QString prenom=ui->prenom_mod->text();
    Personnel P2(id,nom,prenom);
    QMessageBox msgbox;
    bool test=P2.modifier();
    if(! P2.valid(id))
    {
        msgbox.setText("id existe pas");
    msgbox.exec();
    }

    else if(test)
    {msgbox.setText("Modification avec succes.");
        ui->tab_personnel->setModel(P2.afficher());
    }
    else
        msgbox.setText("Echec de modification");

  msgbox.exec();
}
void MainWindow::on_pb_supp_clicked()
{
    Personnel P1; P1.setid(ui->id_supp->text().toInt());
    bool test=P1.supprimer(P1.getid());
    QMessageBox msgBox;

    if(test)
     {   msgBox.setText("Suppression avec succes");
        ui->tab_personnel->setModel(P1.afficher());
     }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_rec_clicked()
{

    Reclam R(id,PR);

}
