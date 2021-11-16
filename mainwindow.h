#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facture.h"

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
    void on_le_pb_supprimer_clicked();

    void on_bp_ajouter_clicked();

    void on_pb_Tri_date_clicked();

    void on_pb_tri_id_clicked();

    void on_pb_tri_prix_clicked();

    void on_pb_recherche_clicked();

    void on_pb_imprimer_clicked();

    void on_pb_browse_clicked();

private:
    Ui::MainWindow *ui;
    Facture F;
    QStringList files;
};
#endif // MAINWINDOW_H
