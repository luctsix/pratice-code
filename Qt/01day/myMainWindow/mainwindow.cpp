#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QMessageBos 属性设置的API
    QMessageBox msgBox;
    msgBox.setText("The documents have been modified");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setDetailedText("Differences here...");
    msgBox.setStandardButtons(QMessageBox::Save
                              |QMessageBox::Discard
                              |QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch(ret){
    case QMessageBox::Save:
        qDebug()<<"Save documents!";
        break;
    case QMessageBox::Discard:
        qDebug()<<"Discard changes!";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"close documents!";
        break;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //void about(QWidget * parent, const QString & title, const QString & text)
    QMessageBox::about(this, "关于", "can i help you?");
}

void MainWindow::on_pushButton_2_clicked()
{
    //QMessageBox::critical(this, "错误信息", "you are wrong", "OK");
    QMessageBox::critical(this, "错误信息", "you are wrong", "YES", "NO");
}
//StandardButton critical(QWidget * parent,
//const QString & title,
//const QString & text,
//StandardButtons buttons = Ok,
//StandardButton defaultButton = NoButton);

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "信息", "i am zhuzhu", "OK");
}
//StandardButton information(QWidget * parent,
//const QString & title,
//const QString & text,
//StandardButtons buttons = Ok,
//StandardButton defaultButton = NoButton)

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::question(this, "Question", "do you love me", "yes", "no");
}
//StandardButton question(QWidget * parent,
//const QString & title,
//const QString & text,
//StandardButtons buttons = StandardButtons( Yes | No ),
//StandardButton defaultButton = NoButton)

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::warning(this, "警告", "you are going to make mistakes", "OK", "NO");
}

//StandardButton warning(QWidget * parent,
//const QString & title,
//const QString & text,
//StandardButtons buttons = Ok,
//StandardButton defaultButton = NoButton)
