#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QTimer>

class ChartView : public QChartView
{
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = nullptr);

    void addDataPoint(double x, double y);

public slots:
    void subscribe(int n);
    void Figure();

private:
    QTimer *m_timer;
    QLineSeries *m_series;
    QChart *m_chart;
    double m_x=0;
    double m_y=100;
};

#endif // CHARTVIEW_H
