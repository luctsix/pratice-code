#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // 画家

    QPen pen(QColor(255, 0, 0)); //画笔
//    pen.setWidth(5);
//    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);

    //画直线
    painter.drawLine(0, 0, 100, 100);
    //画圆
    //painter.drawEllipse(QPoint(100, 100), 50, 50);
    //画椭圆
    //painter.drawEllipse(QPoint(100, 100), 100, 50);
    //画矩形
    //painter.drawRect(100, 100, 50, 20);
#if 0 //画家状态保存和恢复
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.translate(100, 0);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.save();
    painter.translate(100, 0);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.restore();
    painter.setPen(Qt::blue);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
#endif

    //画圆角矩形
//    QRect rectangle(10.0, 20.0, 80.0, 60.0);
//    painter.drawRoundedRect(rectangle, 40.0, 30.0);

    //画文字
    painter.drawText(QPointF(100, 100), "好好学习天天向上");
}
