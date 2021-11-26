#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <personnel.h>
#include <reclamation.h>
#include <tache.h>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_mod_clicked();

    void on_pb_generate_clicked();

    void on_Chercher_clicked();

    void on_trier_clicked();

    void on_reclamer_clicked();

    void on_ajout_tache_clicked();

    void on_mod_tache_clicked();

    void on_supp_tache_clicked();

    void on_gestion_des_personnel_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Personnel P;
    Reclamation R;
    tache T;
    int grand;
    int petit;
};
#endif // MAINWINDOW_H
