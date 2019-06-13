#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                "/home",
//                                                tr("Images (*.png *.xpm *.jpg)"));

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("OpenFile"),
                                                    "E:/",
                                                    tr("Txt File(*.txt, *.doc);;Image(*.jpg, *.png)"));
    qDebug()<<"打开的文件名是："<<filename.toUtf8().data();
}
