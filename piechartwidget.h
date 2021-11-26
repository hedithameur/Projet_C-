#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <personnel.h>
#include <QDialog>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace ki { class PieChartWidget; }
QT_END_NAMESPACE
class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    ~PieChartWidget();
protected:




private:
    ki::PieChartWidget *ui;
    Personnel P;
 signals:
};

#endif // PIECHARTWIDGET_H
