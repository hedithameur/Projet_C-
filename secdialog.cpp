#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"
#include "cheque.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    QPixmap pix1("C:/Users/benai/Desktop/LOGO.png");
    ui ->Logo1_2->setPixmap(pix1);
}

SecDialog::~SecDialog()
{
    delete ui;
}


void SecDialog::on_pushButton_clicked()
{

}

void SecDialog::on_pushButton_2_clicked()
{
    close();
}

void SecDialog::on_modifier_clicked()
{
    int num_cheque=ui->mod_num_cheque->setLineWidth(num_cheque);
    int montant=ui->mod_montant->text().toInt();
    int date_echeance=ui->mod_date->text().toInt();
    int endosse=ui->mod__endosse->text().toInt();

    //affectation des donnees
    bool test=tmp.modifier(num_cheque,date_echeance,montant,endosse)
    if (test)
    {
        ui->tableView_abonement->setModel(tmp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","abonnement modifié");
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un abonnement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    };
}
