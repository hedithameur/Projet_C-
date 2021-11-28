#ifndef AJOUTER_H
#define AJOUTER_H

#include <QDialog>

namespace Ui {
class Ajouter;
}

class Ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter(QWidget *parent = nullptr);
    ~Ajouter();

private slots:
    void on_pushButton_2_clicked();

    void on_ajouter_clicked();

    void on_id_client_ajout_cursorPositionChanged(int arg1, int arg2);

    void on_numero_cheque_ajout_cursorPositionChanged(int arg1, int arg2);

    void on_banque_ajout_cursorPositionChanged(int arg1, int arg2);

    void on_Annuler_1_clicked();

private:
    Ui::Ajouter *ui;
};

#endif // AJOUTER_H
