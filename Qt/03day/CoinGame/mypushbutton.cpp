#include "mypushbutton.h"

#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QRect>
#include <QVariant>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}
//构造函数重载
MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;//保存正常图片显示路径
    this->pressImgPath = pressImg;  //保存按下后显示的图片

    QPixmap pix;//创建pixmap对象

    bool ret = pix.load(normalImgPath);// 载入图片
    if(!ret)
    {
        qDebug()<<normalImg<<"图片加载失败";
    }
    //固定按钮大小
    this->setFixedSize(pix.width(), pix.height());

    //设置按钮为不规则形状
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置按钮图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
}

//按钮点击跳越特效
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    //设置时间间隔
    animation->setDuration(200);

    //创建起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //创建停止位置
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //创建缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //开始动画
    animation->start();

}

//点击开始按钮后后恢复动画
void MyPushButton::zoom2()
{
    //创建对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置间隔时间
    animation->setDuration(200);
    //设置起始位置
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //设置结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //开始动画
    animation->start();
}

//12.重写返回按钮的鼠标事件
void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    if(pressImgPath != "")
    {
        QPixmap pix;
        if(!pix.load(pressImgPath))
        {
            qDebug()<<pressImgPath<<" 图片载入失败";
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mousePressEvent(event);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(normalImgPath != "")
    {
        QPixmap pix;
        if(!pix.load(normalImgPath))
        {
            qDebug()<<normalImgPath<<"图片加载失败";
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mouseReleaseEvent(event);

}


