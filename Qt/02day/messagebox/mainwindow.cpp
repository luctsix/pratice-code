#include "mainwindow.h"
#include <QMessageBox>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMessageBox msg;
    msg.setWindowTitle("提示");
    msg.setText(tr("The document has been modified"));
    msg.setInformativeText(tr("Do you want to save your changes>"));
    msg.setDetailedText(tr("Differences here..."));
    msg.setStandardButtons(QMessageBox::Save |
                           QMessageBox::Discard |
                           QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Save);
    int ret = msg.exec();

    switch(ret){
    case QMessageBox::Save:
        qDebug()<<"Save document...";
        break;
    case QMessageBox::Discard:
        qDebug()<<"Discard changes...";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"Close documents...";
        break;
    }
}

MainWindow::~MainWindow()
{

}
