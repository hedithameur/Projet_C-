#ifndef GARAGE_H
#define GARAGE_H

#include <QMainWindow>
#include <tache.h>
#include <reclamation.h>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <personnel.h>


namespace Ui {
class Garage;
}

class Garage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Garage(QWidget *parent = nullptr);
    ~Garage();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_pb_generate_2_clicked();

    void on_pb_mod_2_clicked();

    void on_pb_supp_2_clicked();

    void on_Chercher_2_clicked();

    void on_trier_2_clicked();

    void on_reclamer_2_clicked();

    void on_ajout_tache_2_clicked();

    void on_mod_tache_2_clicked();

    void on_supp_tache_2_clicked();

private:
    Ui::Garage *ui;
    Personnel P;
    tache T;
    Reclamation R;
    int grand,petit;
};

#endif // GARAGE_H
