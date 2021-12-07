#include "ajouter.h"
#include "ui_ajouter.h"
#include "cheque.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QRegExpValidator>

Ajouter::Ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter)
{
    ui->setupUi(this);
    QPixmap pix1("C:/Users/benai/Desktop/LOGO.png");
    ui ->Logo1_2_3->setPixmap(pix1);
}

Ajouter::~Ajouter()
{
    delete ui;
}

void Ajouter::on_ajouter_clicked()
{
               QString banque=ui->banque_ajout->text() ;
               int montant=ui->montant_ajout->text().toInt();
               int num_cheque=ui->numero_cheque_ajout->text().toInt();
               QString date_echeance=ui->dateEdit->text() ;
               int id_client=ui->id_client_ajout->text().toInt();
               int endosse = 0;

               //affectation des donnees
               Cheque C (banque,montant,num_cheque,date_echeance,id_client,endosse);
               bool test=C.ajouter();
               if(test)
                           {

                              QMessageBox msgBox ;
                              QMessageBox::information(this,"information","Cheque ajouté");
                              }
                               else
                               {
                                   QMessageBox msgBox ;
                                   msgBox.setText("Cheque non ajouté ");
                               }
   }


void Ajouter::on_id_client_ajout_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx ("^[0-9]{4}$");
    QRegExpValidator * validid = new QRegExpValidator(rx,this);
    ui->id_client_ajout->setValidator(validid);
}

void Ajouter::on_numero_cheque_ajout_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx ("^[0-9]{9}$");
    QRegExpValidator * validnumero_cheque = new QRegExpValidator(rx,this);
    ui->id_client_ajout->setValidator(validnumero_cheque);
}

void Ajouter::on_banque_ajout_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx ("^[A-Z]$");
    QRegExpValidator * validid = new QRegExpValidator(rx,this);
    ui->id_client_ajout->setValidator(validid);
}

void Ajouter::on_Annuler_1_clicked()
{
       close();
}
