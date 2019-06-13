#include "mainwindow.h"
#include <QString>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(480, 320);
    this->setFixedSize(480, 320);
    this->setWindowTitle("第一个Qt程序");

    QPushButton *btn1 = new QPushButton;
    btn1->setParent(this);
    btn1->setText("按钮二");
    btn1->resize(100, 30);
    btn1->move(100, 100);

    QPushButton *btn2 = new QPushButton("按钮一", this);
    btn2->setText("关闭");

    connect(btn2, &QPushButton::clicked, this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{

}
