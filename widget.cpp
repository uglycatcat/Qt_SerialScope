#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , qslider(new QSlider(this))
    , _slider(new slider(this))
    , chartview(new ChartView(this))
{
    setFixedSize(600, 400);

    chartview->setGeometry(50, 50, 400, 300);

    _slider->sliderinit(qslider);
    connect(qslider, &QSlider::valueChanged, chartview, &ChartView::subscribe);
}
Widget::~Widget() {
    delete qslider;
    delete _slider;
    delete chartview;
}
