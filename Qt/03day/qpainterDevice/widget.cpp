#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
#if 0
    //第一种绘图设备  Qpixmap
    QPixmap pix(300, 300);
    QPainter painter(&pix);
    pix.fill(Qt::black);
    painter.setPen(Qt::white);

    painter.drawEllipse(QPoint(150, 150), 50, 50);
    pix.save("F:\\Qt\\03day\\pix.png");
#endif
#if 0
    //第二种画图设备  QImage
    QImage img(300, 300, QImage::Format_RGB32);
    QPainter painter(&img);
    img.fill(Qt::black);
    painter.setPen(Qt::white);

    painter.drawEllipse(QPoint(150, 150), 100, 50);

    img.save("F:\\Qt\\03day\\img.png");
#endif

    //第三种绘图设备  QPicture
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.drawEllipse(100, 100, 100, 100);
    painter.end();
    pic.save("F:\\Qt\\03day\\pic.dj");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPicture picture;
    picture.load("F:\\Qt\\03day\\pic.dj");
    QPainter painter(this);
    painter.begin(&picture);
    painter.drawPicture(0, 0, picture);
    painter.end();
}
