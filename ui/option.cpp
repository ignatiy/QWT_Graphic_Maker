#include "option.h"
#include <QDebug>
#include <QFile>
#include <QDesktopServices>


Option::Option(QWidget *parent) : QMainWindow(parent)
{
setMinimumSize(320,230);
setWindowTitle(tr("QWT Graphic Maker"));
Option::setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint);
Option::setMinimumHeight(230);
Option::setMaximumHeight(230);
Option::setMinimumWidth(320);
Option::setMaximumWidth(320);


lbl = new QLabel(this);
lbl->setGeometry(0,0,320,230);
lbl->setWordWrap(true);
lbl->setStyleSheet("QLabel { background-color : #ffffff }");
lbl->setText(lbl->text() + "<h3>QWT Graphic Maker</h3> <br>Основан на Qt Creator 5.4.1<br><br>Разработчики: <br>Дмитрий Лопаков и Игнатий Шиленин<br>гр. ПКС-21<br>ААСК-2015 <br>© Все права защищены.");



pbtn = new QPushButton("Закрыть" , this );
pbtn->setGeometry(170,200,100,25);
pbtn->setStyleSheet("QPushButton { background-color : #d7dbdb ; color: #ff0000 }");
connect(pbtn, SIGNAL(clicked()), this,SLOT(quit()));



pbt =new QPushButton("Справка" , this );
pbt->setGeometry(50,200,100,25);
pbt->setStyleSheet("QPushButton { background-color : #d7dbdb ; color: #ff0000 }");
connect(pbt, SIGNAL(clicked()), this,SLOT(help()));
}

void Option::quit(){
qDebug()<<"quit";
QWidget::close();
}

void Option::help(){
    QDesktopServices::openUrl(QUrl("D:/helper/help.html"));
    qDebug()<<"help";
}
