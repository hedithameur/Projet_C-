#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include "ajouter.h"
#include "cheque.h"
#include "mail.h"
#include "qcustomplot.h"
#include <QVector>
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
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_connection_clicked();

    void on_endosse_clicked();

    void on_non_endosse_clicked();

    void on_modifier_2_clicked();

    void on_mod_endosse_stateChanged(int endosse);

    void on_mod_num_cheque_cursorPositionChanged(int arg1, int arg2);

    void on_supprimer_clicked();

    void on_commandLinkButton_clicked();

    void on_Annuler_2_clicked();

    void on_comboBox_banque_activated(const QString &arg1);

    QSqlQueryModel * afficher_banque() ;

    QSqlQueryModel * afficher_client() ;

    void on_comboBox_banque_2_activated(const QString &arg1);

    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_comboBox_client_activated(int index);

    void on_tableWidget_cellActivated(int row, int column);

    void on_rechercher_clicked();

    void on_stackedWidget_2_currentChanged(int arg1);

    void on_comboBox_client_activated(const QString &arg1);

    void makePlot();

    QVector<double>Statistique();

    void on_pushButton_2_clicked();

    void on_radioButton_cheque_clicked();

    void on_table_endosse_activated(const QModelIndex &index);
    
private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
    Ajouter *ajout;
    mail *Mail;
    Cheque tmp;
    QCustomPlot plot;
    QCustomPlot *customPlot;
   ;
};

#endif // MAINWINDOW_H
