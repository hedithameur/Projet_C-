#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include "cheque.h"

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

private:
    Ui::SecDialog *ui;
    Cheque tmp;
};

#endif // SECDIALOG_H
