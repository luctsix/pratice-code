#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("hello");
    ui->label_2->setPixmap(QPixmap(":/Image/Frame.jpg"));

    QMovie *movie = new QMovie(":/Image/mario.gif");
    ui->label_3->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}
