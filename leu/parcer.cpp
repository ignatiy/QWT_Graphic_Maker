#include "parcer.h"
#include <QDebug>
#include <QString>

parcer::parcer(QObject *parent) : QObject(parent)
{
    vctX=new QVector<int>();
    vctY=new QVector<int>();

//    std::vector< std::vector<double> > vctX;
//    std::vector< std::vector<double> > vctY;

}

QVector<int> *parcer::getAllX()
{
    return vctX;
}

QVector<int> *parcer::getAllY()
{
    return vctY;
}

void parcer::clearAll()
{
    vctX->clear();
    vctY->clear();
}


bool parcer::isDataOk(QString strX, QString strY)
{
    bool ok;
    int val;

float flval=QString(strX).toFloat(&ok);
float flval1=QString(strY).toFloat(&ok);
qDebug()<<flval;
qDebug()<<flval1;
qDebug()<<"toFloat";

    val=strX.toInt(&ok);
    if(!ok){return false;}
    vctX->append(val);
    val=strY.toInt(&ok);
    if(!ok){return false;}
    vctY->append(val);
    return ok;

}


