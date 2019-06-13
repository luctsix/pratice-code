#include "mylabel.h"

#include <QDebug>
#include <QMouseEvent>
#include <QString>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

}

void myLabel::mouseMoveEvent(QMouseEvent *ev){
    //if(ev->buttons()&Qt::LeftButton)
    //{

        QString str = QString("鼠标移动事件(%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug()<< str;
    //}
}
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {

        QString str = QString("鼠标按下事件(%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug()<< str;
    }
}
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {

        QString str = QString("鼠标释放事件(%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug()<< str;
    }
}

void myLabel::enterEvent(QEvent *ev)
{
    qDebug()<<"鼠标进入事件";
}
void myLabel::leaveEvent(QEvent *ev)
{
    qDebug()<<"鼠标离开事件";
}
