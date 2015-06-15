#ifndef OPTION_H
#define OPTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "ui/option.h"

class Option : public QMainWindow
{
    Q_OBJECT
public:
    QTextEdit * txtMain;
    QPushButton * pbtn;
    QPushButton * pbt;
    QLabel * lbl;





    explicit Option(QWidget *parent = 0);


signals:

public slots:
    void quit();
    void help();

private:

private slots:
};

#endif // OPTION_H
