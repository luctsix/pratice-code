#include "widget.h"
#include <QApplication>

//信号的参数个数必须大于槽函数的参数个数
//信号函数的参数类型和槽函数的参数类型必须一一对应

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
