#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QSlider>
#include<slider.h>
#include<QChart.h>
#include<chartview.h>
#include<QPushButton.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QSlider *qslider;
    slider *_slider;
    ChartView *chartview;
};
#endif // WIDGET_H
