#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>
#include<QSlider>
class slider : public QWidget
{
    Q_OBJECT
public:
    explicit slider(QWidget *parent = nullptr);

signals:


public:
    void sliderinit(QSlider *tempslider);
};

#endif // SLIDER_H
