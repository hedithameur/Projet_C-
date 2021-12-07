#include "mail.h"
#include "ui_mail.h"

mail::mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail)
{
    ui->setupUi(this);
}

mail::~mail()
{
    delete ui;
}


void mail::on_pushButton_2_clicked()
{
    close();
}
