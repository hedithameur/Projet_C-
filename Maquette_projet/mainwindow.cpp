#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bp_ajouter_clicked()
{
  int id_facture=ui->le_id_facture->text().toInt();
  int id_client=ui->le_id_client->text().toInt();
  QString nom=ui->le_nom->text();
  QString prenom=ui->le_prenom->text();
  int cin=ui->le_cin->text().toInt();
  QString date=ui->la_date->text();
  QString des=ui->la_des->text();
  float prix_uni=ui->le_prix_uni->text().toFloat();
  int quantite=ui->la_quantite->text().toInt();
  float montant=ui->le_montant->text().toFloat();
  QString mail=ui->le_mail->text();
  int type=ui->le_type->text().toInt();


  Facture F(id_facture,id_client,nom,prenom,cin,date,des,prix_uni,quantite,montant,mail,type);


}
