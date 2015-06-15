#include "plotwindow.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QVector>



PlotWindow::PlotWindow(QWidget *parent):
    QLabel(parent){
    m_tmr=new QTimer();
    m_tmr->stop();
    plotWdg=new QCustomPlot(parent);
    if(parent!=0){
        plotWdg->setMinimumSize(parent->size());
    }else{
        plotWdg->setMinimumSize(640,480);
    }
    QHBoxLayout *lt=new QHBoxLayout();
    lt->addWidget(plotWdg);
    setLayout(lt);
    setMargin(0);
}

void PlotWindow::setXStep(double dStep){
    plotWdg->xAxis->setTickStep(dStep);
}


void PlotWindow::setYStep(double dStep){
    plotWdg->yAxis->setTickStep(dStep);
}

void PlotWindow::setXLims(double dMin, double dMax){
    plotWdg->xAxis->setRangeLower(dMin);
    plotWdg->xAxis->setRangeUpper(dMax);
    plotWdg->update();
}

void PlotWindow::setYLims(double dMin, double dMax){
    plotWdg->yAxis->setRangeLower(dMin);
    plotWdg->yAxis->setRangeUpper(dMax);
    plotWdg->update();
}

int PlotWindow::createPlot(QString strName, QColor color){
    int iCnt=0;


    iCnt=plotWdg->graphCount();
    plotWdg->addGraph();
    plotWdg->graph(iCnt)->setLineStyle(QCPGraph::lsLine);
    plotWdg->graph(iCnt)->setPen(QPen(color));
    plotWdg->graph(iCnt)->setBrush(QBrush(QColor(255,160,50,50)));
    plotWdg->graph(iCnt)->setName(strName);

    plotWdg->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
    plotWdg->xAxis->setLabel("x");
    plotWdg->yAxis->setLabel("y");
    plotWdg->xAxis->setRange(0, 12);
    plotWdg->yAxis->setRange(0, 8);
    plotWdg->xAxis->setAutoTickStep(false);



    QVector<QString> Labels;
    Labels << "0" << QString::fromUtf8("π/6") << QString::fromUtf8("π/3")
           << QString::fromUtf8("π/2") << QString::fromUtf8("2π/3")
           << QString::fromUtf8("5π/6") << QString::fromUtf8("π")
           << QString::fromUtf8("7π/6") << QString::fromUtf8("4π/3")
           << QString::fromUtf8("3π/2") << QString::fromUtf8("5π/3")
           << QString::fromUtf8("11π/6") << QString::fromUtf8("2π");





    plotWdg->xAxis->setAutoTickLabels(false);
    plotWdg->xAxis->setTickVectorLabels(Labels);

    plotWdg->xAxis->setTickStep(1);
    plotWdg->axisRect()->setupFullAxesBox();
    plotWdg->legend->setVisible(true);
    return iCnt;
}

void PlotWindow::addDataToGraph(int iGraph, double dblX, double dblY){
    if(plotWdg->graphCount()<iGraph)return;
    plotWdg->graph(iGraph)->addData(dblX,dblY);
    plotWdg->graph(iGraph)->removeDataBefore(dblX-8);
    plotWdg->graph(iGraph)->rescaleValueAxis();
    plotWdg->xAxis->setRange(dblX+0.25,8,Qt::AlignRight);
    plotWdg->replot();
}





void PlotWindow::resizeEvent(QResizeEvent *evnt){
    plotWdg->resize(evnt->size().width()-4,evnt->size().height()-4);
}
