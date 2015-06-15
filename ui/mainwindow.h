#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QToolBar>
#include "ui/option.h"
#include "leu/plotwindow.h"
#include "leu/qcustomplot.h"
#include "leu/parcer.h"
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
        QLabel * lblMain;
        QTextEdit * text1;
        QTextEdit * text2;
        QHBoxLayout * lay;
        QToolBar * tbar;
        parcer * pxy;

explicit MainWindow(QWidget *parent = 0);
signals:
public slots:
    void open();
    void save();
//    void log();
    void sins();
    void coss();
    void tgs();
    void ctgs();
    void fun();
    void erase();
    void pens();
    void help();
    void updatePlotVal();


private:



    Option *formOption;

    QTimer              *m_tmr;
    PlotWindow       *m_plot;
    int                         m_idPlot;
protected:
    void showEvent(QShowEvent *);

};
#endif // MAINWINDOW_H
