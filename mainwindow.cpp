#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include "cheque.h"
#include "mail.h"
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "qcustomplot.h"
#include <QVector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //affichage logo
    QPixmap pix1("C:/Users/benai/Desktop/LOGO.png");
    ui ->Logo1->setPixmap(pix1);
    QPixmap pix2("C:/Users/benai/Desktop/LOGO.png");
    ui ->Logo2->setPixmap(pix2);
    QPixmap pix3("C:/Users/benai/Desktop/LOGO.png");
    ui ->Logo3->setPixmap(pix3);
    QPixmap pix4("C:/Users/benai/Desktop/LOGO.png");
    ui ->Logo1_2->setPixmap(pix4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connection_clicked()
{
    QString Indentifiant=ui->identifiant->text();
            QString motdepasse=ui->mdp_abn->text();

            if(Indentifiant=="142001"&& motdepasse=="123456")
                {
                    QMessageBox::information(this,"connecter","connecter");
                    //hide();
                   ui->stackedWidget->setCurrentIndex(1);


                }

            else
                {
                    QMessageBox::warning(this,"connecter","erreur");
                    //hide();
                }
}

void MainWindow::on_pushButton_clicked()
{
    ajout = new Ajouter(this);
    ajout->show();
}
//*******************************************
void MainWindow::on_endosse_clicked()
{
     ui->table_endosse->setModel(tmp.afficher_endosse());
     ui->table_endosse->setModel(tmp.trier2());
}

void MainWindow::on_non_endosse_clicked()
{
   ui->table_endosse->setModel(tmp.afficher_non_endosse());
   ui->table_endosse->setModel(tmp.trier());
}





void MainWindow::on_modifier_2_clicked()
{
    int num_cheque=ui->mod_num_cheque->text().toInt();
        int montant=ui->mod_montant->text().toInt();
        QString date=ui->mod_date->text();
        int endosse=ui->mod_endosse->text().toInt();

        if (ui->mod_endosse->isChecked())
        {
            endosse = 1;
        }
        else {
            endosse = 0;
        }





        //affectation des donnees
        bool test=tmp.modifier(num_cheque,date,montant,endosse);
        if (test)
        {
            ui->table_endosse->setModel(tmp.afficher_endosse());//refresh
            QMessageBox msgBox ;
            QMessageBox::information(this,"information","abonnement modifié");
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un abonnement"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void MainWindow::on_mod_endosse_stateChanged(int endosse)
{
    if (ui->mod_endosse->isChecked())
    {
        endosse =  1;
    }
    else {
        endosse = 0;
    }

}


void MainWindow::on_commandLinkButton_clicked()
{
    mail Mail;
    Mail.setModal(true);
    Mail.exec();

}

void MainWindow::on_Annuler_2_clicked()
{
    close();
}

void MainWindow::on_supprimer_clicked()
{
    Cheque C1;
        C1.set_num_cheque( ui->mod_num_cheque->text().toInt());
        bool test=C1.supprimer(C1.get_num_cheque());
        QMessageBox msgBox;

         if(test)
         {   msgBox.setText("Suppression avec succes");
            ui->table_endosse->setModel(C1.afficher_endosse());
            ui->table_endosse->setModel(C1.afficher_non_endosse());
         }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}


QSqlQueryModel * MainWindow :: afficher_banque()
  {
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery(" select BANQUE from CHEQUE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("banque"));
        return model;

  }

void MainWindow::on_comboBox_banque_activated(const QString &arg1)
{
    ui->comboBox_banque->setModel(afficher_banque());
}

void MainWindow::on_mod_num_cheque_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_rechercher_clicked()
{
    if (ui->radioButton_banque->isChecked())
            {
                QString banque= ui->rechercher->text();
                ui->table_endosse->setModel(tmp.chercher2(banque));
            }
        if (ui->radioButton_cheque->isChecked())
            {
                int num_cheque= ui->rechercher->text().toInt() ;
                ui->table_endosse->setModel(tmp.chercher(num_cheque));}

        if (!(ui->radioButton_banque->isChecked())&&!(ui->radioButton_cheque->isChecked()))
        {
                QMessageBox::critical (nullptr, QObject::tr("chercher echouer"),
                                      QObject::tr("connection failed .\n"
                                                   "click cancel to exit ."), QMessageBox::Cancel);

        }
}

void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(11), y3(11);
    for (int i=0; i<x3.size(); ++i)
    {
        x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
        y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12;
    QVector<QString> labels;
    labels<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}

QVector<double> MainWindow::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(11);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    stat[5]=0;
    stat[6]=0;
    stat[7]=0;
    stat[8]=0;
    stat[9]=0;
    stat[10]=0;
    stat[11]=0;

   //SELECT * FROM table WHERE month = NOW() + INTERVAL 1 MONTH

    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=1 ");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=2");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=3");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=4 ");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=5 ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=6 ");
    q.exec();
    while (q.next())
    {
        stat[5]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=7 ");
    q.exec();
    while (q.next())
    {
        stat[6]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=8 ");
    q.exec();
    while (q.next())
    {
        stat[7]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=9 ");
    q.exec();
    while (q.next())
    {
        stat[8]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=10 ");
    q.exec();
    while (q.next())
    {
        stat[9]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=11 ");
    q.exec();
    while (q.next())
    {
        stat[10]++;
    }
    q.prepare("SELECT * FROM CHEQUE WHERE ENDOSSE=1 AND MONTH(DATE_ECHEANCE)=12 ");
    q.exec();
    while (q.next())
    {
        stat[11]++;
    }
    return stat;
}


QSqlQueryModel * MainWindow :: afficher_client()
  {
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery(" select ID_CLIENT from CHEQUE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
        return model;

  }



void MainWindow::on_comboBox_client_activated(const QString &arg1)
{
    ui->comboBox_client->setModel(afficher_client());
}

void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::makePlot();
}

