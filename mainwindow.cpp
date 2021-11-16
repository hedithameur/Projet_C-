#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_facture->setModel(F.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_le_pb_supprimer_clicked()
{
    Facture F1;
        F1.setid_facture(ui->le_id_supp->text().toInt());
        bool test=F1.supprimer(F1.getid_facture());
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                     QObject::tr("Suppression effectuée\n"
                             "Click Cancel to exit,"), QMessageBox::Cancel);
            ui->tab_facture->setModel(F.afficher());

        }

        else QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                  QObject::tr("Suppression non effectuée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_bp_ajouter_clicked()
{
    int id_facture=ui->le_id_facture->text().toInt();
   // int id_client=ui->le_id_client->text().toInt();
    QString date_facture=ui->la_date->text();
    QString des=ui->la_des->text();
    float prix_uni=ui->le_prix_uni->text().toFloat();
   // int quantite=ui->la_quantite->text().toInt();
   // float montant=ui->le_montant->text().toFloat();
   // QString mail_facture=ui->le_mail->text();
    int type=ui->le_type->text().toInt();
    Facture F(id_facture,des,type,date_facture,prix_uni);//,id_client,date,des,prix_uni,quantite,montant,mail_facture,type);
    bool test=F.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("Ajout effectué\n"
                         "Click Cancel to exit,"), QMessageBox::Cancel);
        ui->tab_facture->setModel(F.afficher());

    }

    else QMessageBox::critical(nullptr, QObject::tr("Not OK"),
              QObject::tr("Ajout non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_Tri_date_clicked()
{   QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM facture_2 order by date_facture ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("désignation"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


             ui->tab_facture->setModel(model);
             ui->tab_facture->show();
             msgBox.setText("Tri par date avec succès.");
             msgBox.exec();
}

void MainWindow::on_pb_tri_id_clicked()
{
    QMessageBox msgBox ;

      QSqlQueryModel *model = new QSqlQueryModel();
               model->setQuery("SELECT * FROM facture_2 order by id_facture ASC");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("désignation"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));

               ui->tab_facture->setModel(model);
               ui->tab_facture->show();
               msgBox.setText("Tri par identifiant avec succès.");
               msgBox.exec();
}

void MainWindow::on_pb_tri_prix_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM facture_2 order by prix_unitaire ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("désignation"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


                 ui->tab_facture->setModel(model);
                 ui->tab_facture->show();
                 msgBox.setText("Tri par prix unitaire avec succès.");
                 msgBox.exec();
}



void MainWindow::on_pb_recherche_clicked()
{
   // Facture F1;
    if (ui->comboBox_recherche->currentText()=="ID client")
    {
        int id=ui->critere->text().toInt();
        if(F.recherche_id_facture(id)){
            ui->tab_recherche->setModel(F.afficher_recherche_id(id));
        }
    }
    else if (ui->comboBox_recherche->currentText()=="Date")
    {
        QString date=ui->critere->text();
                    if (F.recherche_date(date))
                    {
                        ui->tab_recherche->setModel(F.afficher_recherche_date(date));
                    }
    }

}



void MainWindow::on_pb_imprimer_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void MainWindow::on_pb_browse_clicked()
{
    files.clear();

        QFileDialog dialog(this);
        dialog.setDirectory(QDir::homePath());
        dialog.setFileMode(QFileDialog::ExistingFiles);

        if (dialog.exec())
            files = dialog.selectedFiles();

        QString fileListString;
        foreach(QString file, files)
            fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

        ui->contenu->setText( fileListString );
}
