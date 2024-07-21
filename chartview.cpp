#include "chartview.h"

ChartView::ChartView(QWidget *parent)
    : QChartView(new QChart(), parent) // Use QChartView as the base class
    , m_series(new QLineSeries)
    , m_chart(chart())
    , m_timer(new QTimer(this))
{
    m_chart->addSeries(m_series);
    m_chart->setTitle("Real Time Monitor");

    QValueAxis *xAxis = new QValueAxis;
    xAxis->setRange(0, 100);
    xAxis->setLabelFormat("%.1f");
    m_chart->setAxisX(xAxis, m_series);
    xAxis->setTickCount(6);

    QValueAxis *yAxis = new QValueAxis;
    yAxis->setRange(0, 300);
    yAxis->setLabelFormat("%.1f");
    m_chart->setAxisY(yAxis, m_series);
    yAxis->setTickCount(7);

    m_chart->legend()->setVisible(false);
    setChart(m_chart);

    setRenderHint(QPainter::Antialiasing);

    connect(m_timer, &QTimer::timeout, this, &ChartView::Figure);
    m_timer->start(50); // 100 ms interval
}

void ChartView::addDataPoint(double x, double y) {
    m_series->append(x, y);
}

void ChartView::Figure(){

    if(m_x<=100){
        m_x++;
        addDataPoint(m_x,m_y);
    }
    else{
        qreal dwidth = chart()->plotArea().width() / 100;
        m_x++;
        addDataPoint(m_x,m_y);
        chart()->scroll(dwidth, 0);
    }
}
void ChartView::subscribe(int n){
    m_y=n;
}
