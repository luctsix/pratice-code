#include "mainscene.h"
#include <QApplication>
#include <QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;

    //设置音效 ---1
    QSound *backSound = new QSound(":/image/ConFlipsSound.wav");
    backSound->play();
    w.show();

    return a.exec();
}
