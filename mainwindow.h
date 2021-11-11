#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <personnel.h>
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

    void on_rec_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;
    int grand;
    int petit;
};
#endif // MAINWINDOW_H
