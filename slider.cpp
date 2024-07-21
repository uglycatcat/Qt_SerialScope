#include "slider.h"
#include <QDebug>
slider::slider(QWidget *parent)
    : QWidget{parent}
{}

void slider::sliderinit(QSlider *tempslider){
    tempslider->setOrientation(Qt::Vertical);
    tempslider->setGeometry(525,50,10,300);
    tempslider->setMinimum(0);  // 最小值
    tempslider->setMaximum(300);  // 最大值
    tempslider->setSingleStep(1);  // 步长
    tempslider->setValue(100);
}
