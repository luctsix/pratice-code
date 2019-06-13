#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);

    QStringList lists;
    lists<<"姓名"<<"性别"<<"年龄";
    ui->tableWidget->setHorizontalHeaderLabels(lists);
    QStringList name;
    name<<"张三"<<"李四"<<"小明"<<"小红"<<"侯五";
    QStringList sex;
    sex<<"男"<<"男"<<"男"<<"女"<<"男";

    for(int row=0; row<5; row++)
    {
        int col = 0;
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(name.at(row)));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(sex.at(row)));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(QString::number(30+row)));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
