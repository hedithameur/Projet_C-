#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "mainwindow.h"
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


QT_CHARTS_USE_NAMESPACE


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;


    QBarSet *set0=new QBarSet("BH");
    QBarSet *set1=new QBarSet("BNA");
    QBarSet *set2=new QBarSet("AMEN");

    *set0 <<1;
    *set1 <<0;
    *set2 <<0;

    QBarSeries *series = new QBarSeries;
    series ->append(set0);
    series ->append(set1);
    series ->append(set2);

    QChart * chart = new QChart();
    chart ->addSeries(series);
    chart ->setTitle("endosse");

    //no animation

    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;

    categories <<"janvier" <<"fevrier" <<"mars" ;
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis , series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp ->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);


    QMainWindow window;

    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    w.show(); //affichage logo
     }

    return a.exec();


}
