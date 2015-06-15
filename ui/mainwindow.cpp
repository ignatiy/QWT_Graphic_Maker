#include "mainwindow.h"
#include <math.h>
#include "leu/parcer.h"
#include <QToolBar>
#include <QTextEdit>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QByteArray>


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent){


    m_tmr=new QTimer();
       m_tmr->stop();
       m_plot=new PlotWindow();
       m_idPlot=0;
       m_idPlot=m_plot->createPlot(QString("Функция"),Qt::blue);

       //connect(pens,SIGNAL(),this,SLOT(updatePlotVal()));
setMinimumSize(1024,640);

tbar = new QToolBar;
tbar->setStyleSheet("QToolBar { background-color : #d7dbdb }");
tbar->addAction(tr("Открыть"),this,SLOT(open()));
tbar->addSeparator();
tbar->addAction(tr("Рисовать график"),this,SLOT(pens()));
tbar->addSeparator();
tbar->addAction(tr("Сохранить"),this,SLOT(save()));
tbar->addSeparator();
//tbar->addAction(tr("Лог"),this,SLOT(log()));
//tbar->addSeparator();
tbar->addAction(tr("Y=SinX"),this,SLOT(sins()));
tbar->addSeparator();
tbar->addAction(tr("Y=CosX"),this,SLOT(coss()));
tbar->addSeparator();
tbar->addAction(tr("Y=tgX"),this,SLOT(tgs()));
tbar->addSeparator();
tbar->addAction(tr("Y=ctgX"),this,SLOT(ctgs()));
tbar->addSeparator();
tbar->addAction(tr("Парабола"),this,SLOT(fun()));
tbar->addSeparator();
tbar->addAction(tr("Очистить всё"),this,SLOT(erase()));
tbar->addSeparator();
tbar->addAction(tr("О программе"),this,SLOT(help()));
this->addToolBar(tbar);


text1= new QTextEdit();
text1->setGeometry(110,30,200,420);
text1->setReadOnly(true);


text2= new QTextEdit();
text2->setGeometry(330,30,200,420);


lblMain = new QLabel();
setCentralWidget(lblMain);
lay = new QHBoxLayout();
lay->addWidget(text1);
lay->addStretch();
lay->addWidget(text2);
lay->addStretch();
lay->addWidget(m_plot);
m_plot->show();
lblMain->setLayout(lay);
pxy=new parcer();
setWindowTitle(tr("QWT Graphic Maker"));

}



void MainWindow::open(){
    qDebug()<<"open";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "",
        tr("Text Files (*.txt)"));

   if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {

            QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно открыть файл"));
            return;
        }

        else{
     QString strText2;
                    while(!file.atEnd()){

                        QString str=file.readLine();


                        QStringList lst=str.split(";");


                       for(int i=0;i<lst.count();i++){
                           if (i==0){strText2.append("x="+ lst.at(i));qDebug()<<"x";}
                           qDebug()<<lst.at(i);
                           if (i==1){strText2.append("y="+ lst.at(i));qDebug()<<"y";}
                       }
                       if (lst.count()>=1){
                        qDebug()<<pxy->isDataOk(lst.at(0),lst.at(1));
                       }
                    }

text2->setText(strText2);

pxy->getAllX();
pxy->getAllY();
                }
        }




   QDir mDir;
   text1->clear();
  // QString strPath = text1->text();
  // foreach (QFileInfo mIte, mDir.drives() )
 foreach (QFileInfo mIte, mDir.entryInfoList() )

   {
   text1->append(mIte.absoluteFilePath());
   }



 }
void MainWindow::save(){
    qDebug()<<"save";


    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "",
    tr("Text Files (*.txt)"));

    if (fileName != "") {
       QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {

       } else {
            QTextStream stream(&file);
           stream << text2->toPlainText();
           stream.flush();
           file.close();
       }
    }


}





//void MainWindow::log(){

//    QtMsgType type;
//    char msg;

//    QFile file("D:/log.txt");
//     if(!file.open(QIODevice::WriteOnly)){
//     return;
//     }
//     QString sCurrDateTime = "[" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";
//     QTextStream str(&file);
//     switch(type){
//     case QtDebugMsg:
//     str << QString("Debug%1: %2\n").arg(sCurrDateTime).arg(msg);
//     break;
//     case QtWarningMsg:
//     str << QString("Warning%1: %2\n").arg(sCurrDateTime).arg(msg);
//     break;
//     case QtCriticalMsg:
//     str << QString("Critical%1: %2\n").arg(sCurrDateTime).arg(msg);
//     break;
//     case QtFatalMsg:
//     str << QString("Fatal%1: %2\n").arg(sCurrDateTime).arg(msg);
//     abort();
//     }
//     str.flush();
//     file.flush();
//     file.close();
//     qDebug() << "Project started";



//    QFile file("D:/test.txt");
//    QString str = "Отладка успешно завершена";
//    if (file.open(QIODevice::WriteOnly))
//    {
//        QTextStream stream(&file);
//        stream <<  str.toUpper();
//        file.close();
//        if (stream.status() != QTextStream::Ok)
//        {
//            qDebug() << "Ошибка записи файла";
//        }
//    }
//    qDebug()<<"log";
//}


void MainWindow::erase(){


//          if{      m_plot->deleteLater() }else{
//                m_plot=new PlotWindow();
//                m_idPlot=0;
//                        m_idPlot=m_plot->createPlot(QString("Вектор"),Qt::blue);}//ahaha,tupoi kod-potomu-chto tupoi ya


    pxy->clearAll();
    text2->clear();

    qDebug()<<"deleteAll";
}




void MainWindow::help(){
    qDebug()<<"help";


formOption = new Option(this);
formOption->setAttribute(Qt::WA_ShowModal,true);
formOption->setWindowModality(Qt::ApplicationModal);
formOption->show();

}

void MainWindow::updatePlotVal(){

QVector<int> *x,*y;


x=pxy->getAllX();
y=pxy->getAllY();

      qDebug()<<"x->at(i)";
      qDebug()<<"y->at(i)";

  for(int i=0;i<x->count();i++){
          m_plot->addDataToGraph(m_idPlot,x->at(i),y->at(i));
  }


}
void MainWindow::sins(){
    qDebug()<<"sin";

    QVector<double> x(360), y(360);

    for (int i=0; i<360; ++i)
    {
        x[i] = ( i/50.0 - 1 ) * M_PI;
        y[i] = sin( x[i] );
m_plot->addDataToGraph(m_idPlot,x.at(i),y.at(i));
    }

}


void MainWindow::coss(){
    qDebug()<<"cos";

    QVector<double> x(360), y(360);

    for (int i=0; i<360; ++i)
    {

        x[i] = ( i/50.0 - 1 ) * M_PI;
        y[i] = cos( x[i] );
m_plot->addDataToGraph(m_idPlot,x.at(i),y.at(i));
    }

}

void MainWindow::tgs(){
    qDebug()<<"tg";

    QVector<double> x(360), y(360);

    for (int i=0; i<360; ++i)
    {

x[i]=i;
y[i]=tan(x[i]*M_PI/180);


m_plot->addDataToGraph(m_idPlot,x.at(i),y.at(i));
    }

}

void MainWindow::fun(){
    qDebug()<<"fun";

    QVector<double> x(101), y(101);
        for (int i=0; i<101; ++i)
        {
            x[i] = i/50.0 - 1;
            y[i] = x[i]*x[i];
            m_plot->addDataToGraph(m_idPlot,x.at(i),y.at(i));
        }



}

void MainWindow::ctgs(){
    qDebug()<<"ctg";

    QVector<double> x(360), y(360);

    for (int i=0; i<360; ++i)
    {
        x[i] = i;
        y[i] = 1/(tan(x[i]*M_PI/180));
m_plot->addDataToGraph(m_idPlot,x.at(i),y.at(i));
    }

}

void MainWindow::showEvent(QShowEvent *){
    m_tmr->start(0);
}

void MainWindow::pens(){
    qDebug()<<"Pens";
    updatePlotVal();
}
