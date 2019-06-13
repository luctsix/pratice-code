#include "widget.h"
#include <QApplication>

#include "eventlabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();


    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->show();

    label->setMouseTracking(true);
    return a.exec();
}
