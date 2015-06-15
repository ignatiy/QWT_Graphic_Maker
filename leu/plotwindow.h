#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QLabel>
#include <QTimer>
#include <QWidget>
#include "qcustomplot.h"
class PlotWindow : public QLabel
{
    Q_OBJECT
public:
    explicit PlotWindow(QWidget *parent = 0);    
signals:

public slots:
    void        setXStep(double dStep);
    void        setYStep(double dStep);
    void        setXLims(double dMin, double dMax);
    void        setYLims(double dMin, double dMax);
    int          createPlot(QString strName, QColor color);// return number of plot
    void        addDataToGraph(int iGraph,double dblX,double dblY);

private:
    QTimer                  *m_tmr;
    QCPItemTracer   *itemTracer;
    QCustomPlot        *plotWdg;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *evnt);
};

#endif // PLOTWINDOW_H
