#include "piechartwidget.h"
#include <QPainter>
#include "personnel.h"
#include "ui_piechartwidget.h"

PieChartWidget::PieChartWidget(QWidget *parent) : QWidget(parent)
{
    ui(new ki::PieChartWidget)
            ui->setupUi(this);

}
PieChartWidget::~PieChartWidget()
{
    delete ui;
}

void PieChartWidget::paintEvent(QPaintEvent *)
{
        int b=P.Stat_1();
        int c=P.Stat_2();
        int d=P.Stat_3();


        float s1= b*100 ;
                float s2=c*100;
                float nb = b+c+d ;
                float q1 ;
                q1 = s1/nb ;
                float q2;
                q2=s2/nb;
                float y  ;
                y = (q1*360)/100 ;
                float m;
                m= (q2*360)/100;
                float z  ;
                z=360-(y+m) ;



        QPainter painter(this);
            QRectF size=QRectF(50,50,this->width()-200,this->width()-200);

            painter.setBrush(Qt::blue);
            painter.drawPie(size,0,16*y);
            //Entre 0 et 9
            painter.setBrush(Qt::green);
            painter.drawPie(size,16*y,16*m);
            //Entre 10 et 15
            painter.setBrush(Qt::red);
            painter.drawPie(size,16*(m+y),16*z);
            //Plus que 15

}



