#include "widget.h"
#include "ui_widget.h"
#include <QDialog>

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

void Widget::on_pushButton_clicked()
{
    QDialog dlg;
    dlg.setWindowTitle("模态对话框");
    dlg.exec();
}

void Widget::on_pushButton_2_clicked()
{
    QDialog *dlg = new QDialog(this);
    dlg->resize(240, 120);
    dlg->setWindowTitle("非模态对话框");
    dlg->setAttribute(Qt::WA_DeleteOnClose);

    dlg->show();

}
