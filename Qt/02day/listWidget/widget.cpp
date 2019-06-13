#include "widget.h"
#include "ui_widget.h"
#include <QStringList>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList lists;
    lists<<"北京"<<"上海"<<"广州"<<"深圳";
    ui->listWidget->addItems(lists);
    ui->listWidget->addItem("南京");

    ui->listWidget->insertItem(0, "柳州");
}

Widget::~Widget()
{
    delete ui;
}
