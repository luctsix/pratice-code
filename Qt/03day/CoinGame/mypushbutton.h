#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

//5.构建自定义的开始按钮
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

public:
    //构造重载
    MyPushButton(QString normalImg, QString pressImg = "");

    //12.重写返回按钮的鼠标事件
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //按钮点击跳越特效
    void zoom1();
    void zoom2();

private: //自定义私有成员
    QString normalImgPath;//默认显示的图片
    QString pressImgPath;//按下后显示的图片

signals:


public slots:
};

#endif // MYPUSHBUTTON_H
