
#include <QApplication>
#include "smallwidget.h"
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    SmallWidget w;
    w.show();



    return a.exec();
}
