#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "personnel.h"
#include "tache.h"
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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);







    grand = 999999;
    petit = 100000;
    ui->le_id->setValidator( new QIntValidator(00, 999999, this));
    ui->id_mod->setValidator( new QIntValidator(00, 999999, this));
    ui->id_supp->setValidator( new QIntValidator(00, 999999, this));


#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator *car= new QRegExpValidator(rxNom,this);
    ui->le_nom->setValidator(car);
    ui->le_prenom->setValidator(car);
    ui->nom_mod->setValidator(car);
    ui->prenom_mod->setValidator(car);

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
    QString mois_conger=ui->le_mois->text();
    int periode_conger=ui->la_periode->text().toInt();
    Personnel P(id,periode_conger,nom,prenom,mois_conger);

    bool test=P.ajouter();
    QMessageBox msgbox;

    if(! P.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}
    else if(test)
    {msgbox.setText("Ajout avec succes.");
        ui->tab_personnel->setModel(P.afficher());
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}
void MainWindow::on_pb_generate_clicked()
{
    qsrand(qrand());  ui->le_id->setText(QString::number(qrand() % ((grand + 1) - petit) + petit));
}


void MainWindow::on_pb_mod_clicked()
{
    int id=ui->id_mod->text().toInt();
    QString nom=ui->nom_mod->text();
    QString prenom=ui->prenom_mod->text();
    QString mois_conger=ui->mois_mod->text();
    int periode_conger=ui->periode_mod->text().toInt();
    Personnel P2(id,periode_conger,nom,prenom,mois_conger);

    QMessageBox msgbox;
    bool test=P2.modifier();
    if(! P2.valid(id))
    {
        msgbox.setText("ID n'existe pas");
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

    Personnel P1;
    P1.setid(ui->id_supp->text().toInt());
    bool test=P1.supprimer(P1.getid());
    QMessageBox msgBox;

    if(! P1.valid(P1.getid()))
    {
        msgBox.setText("ID n'existe pas");
    msgBox.exec();
    }

   else if(test)
     {   msgBox.setText("Suppression avec succes");
        ui->tab_personnel->setModel(P1.afficher());
     }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}
void MainWindow::on_Chercher_clicked()
{
    if (ui->radioButton_id->isChecked())
        {
            int id= ui->chercher->text().toInt() ;
            ui->tab_recherche->setModel(P.chercherid(id));
        }
    if (ui->radioButton_periode->isChecked())
        {
            int periode_conger= ui->chercher->text().toInt() ;
            ui->tab_recherche->setModel(P.chercherperiode(periode_conger));}
    if (ui->radioButton_nom->isChecked())
        {
            QString nom= ui->chercher->text();
             QString prenom= ui->chercher->text();
            ui->tab_recherche->setModel(P.cherchernomouprenom(nom,prenom));

        }
    if (!(ui->radioButton_id->isChecked())&&!(ui->radioButton_periode->isChecked())&&!((ui->radioButton_nom->isChecked())))
    {
            QMessageBox::critical (nullptr, QObject::tr("chercher echouer"),
                                  QObject::tr("connection failed .\n"
                                               "click cancel to exit ."), QMessageBox::Cancel);

    }
}


void MainWindow::on_trier_clicked()
{
    if (ui->radioButton_id_tri->isChecked())
        {
            ui->tab_trier->setModel(P.trierid());
        }
    if (ui->radioButton_periode_tri->isChecked())
        {

            ui->tab_trier->setModel(P.trierperiode());}
    if (ui->radioButton_nom_tri->isChecked())
        {

            ui->tab_trier->setModel(P.triernom());

        }
    if (!(ui->radioButton_id_tri->isChecked())&&!(ui->radioButton_periode_tri->isChecked())&&!((ui->radioButton_nom_tri->isChecked())))
    {
            QMessageBox::critical (nullptr, QObject::tr("chercher echouer"),
                                  QObject::tr("connection failed .\n"
                                               "click cancel to exit ."), QMessageBox::Cancel);

    }
}

void MainWindow::on_reclamer_clicked()
{
    int id=ui->id_rec->text().toInt();
    QString description=ui->Description->text();

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


void MainWindow::on_ajout_tache_clicked()
{
    int id=ui->id_tache->text().toInt();
    QString nom_tache=ui->nom_tache->text();
    tache T(id,nom_tache);

    bool test=T.ajoutertache();
    QMessageBox msgbox;

    /*if(! P.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}*/
    if(test)
    {msgbox.setText("Ajout de la tache avec succes.");
        ui->tab_tache->setModel(T.affichertache());
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}



void MainWindow::on_mod_tache_clicked()
{
    int id=ui->id_tache_mod->text().toInt();
    QString nom_tache=ui->nom_tache_mod->text();
    tache T(id,nom_tache);

    bool test=T.modifiertache();
    QMessageBox msgbox;

    /*if(! P.valid(id))
    {
        msgbox.setText("ID n'existe pas");
    msgbox.exec();}*/
    if(test)
    {msgbox.setText("Modification de la tache avec succes.");
        ui->tab_tache->setModel(T.affichertache());
    }
    else
        msgbox.setText("Echec d'ajout");

    msgbox.exec();
}


void MainWindow::on_supp_tache_clicked()
{
    tache T;
    T.setid(ui->id_tache_supp->text().toInt());
    bool test=T.supprimertache(T.getid());
    QMessageBox msgBox;

    /*if(! P1.valid(P1.getid()))
    {
        msgBox.setText("ID n'existe pas");
    msgBox.exec();
    }*/

    if(test)
     {   msgBox.setText("Suppression de la tache avec succes");
        ui->tab_tache->setModel(T.affichertache());
     }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_gestion_des_personnel_currentChanged(int index)
{
    QSqlQueryModel * modal = new QSqlQueryModel;
    QSqlQueryModel * modal2 = new QSqlQueryModel;
    QBarSeries *series = new QBarSeries();
    QStringList categories;
    modal->setQuery("select prenom from personnel group by prenom ");
    modal2->setQuery("select mois_conger from personnel group by mois_conger");
     for(int i=0;i<10;i++){
        QString prenom=modal->index(i,0).data().toString();
        QBarSet *set0 = new QBarSet(prenom);
        if(prenom.length()){
   for(int j=0;j<13;j++){

      QString mois=modal2->index(j,0).data().toString();
        if(mois.length()){
        QSqlQueryModel * modal1 = new QSqlQueryModel;
        modal1->setQuery("select periode_conger from personnel where prenom='"+ prenom +"' and mois_conger='"+ mois +"'");
        int periode=modal1->index(0,0).data().toInt();
        set0->append(periode);

    }
         series->append(set0);
         series->setLabelsVisible(set0);
      categories.append(mois);

    }
        }

}


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique des personnels ");
        chart->setAnimationOptions(QChart::SeriesAnimations);





        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);


        QChartView *chartView = new QChartView(chart);
        chartView->setParent(ui->stat);

}
