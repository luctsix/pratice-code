#include "mycoin.h"

#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QTimer>

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString butlmg)
{
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    QPixmap pix;
    if(!pix.load(butlmg))
    {
        qDebug()<<butlmg<<" 图片加载失败";
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    //监听正反翻转的信号和槽
    connect(timer1, &QTimer::timeout, this, [=](){
        QPixmap pix;
        pix.load(QString(":/image/Coin000%1").arg(this->min++));
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if(min>max)
        {
            this->min = 1;
            this->isAnimation = false;
            timer1->stop();
        }
    });
    connect(timer2, &QTimer::timeout, this, [=](){
        QPixmap pix;
        pix.load(QString(":/image/Coin000%1").arg(this->max--));
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if(min>max)
        {
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });

}

void MyCoin::changeFlag()
{
    if(flag == true)
    {
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else
    {
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *event)
{
    if(this->isAnimation || this->isWin==true)
    {
        return;
    }
    else {
        return QPushButton::mousePressEvent(event);
    }
}
