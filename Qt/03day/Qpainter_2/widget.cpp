#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPushButton>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    posX = 10;

    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        posX += 20;
        update();
    });
}

Widget::~Widget()
{
    delete ui;
    posX = 10;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
#if 0
    QPen pen(QColor(255, 0, 0));
    pen.setWidth(6);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(100, 100), 50, 50);

    //kang抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(200, 100), 50, 50);
#endif

    painter.drawPixmap(posX, 100, QPixmap(":/down.png"));

}
