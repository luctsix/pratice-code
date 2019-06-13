#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QWidget>
#include "playscene.h"


//8.构建选择关卡界面
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //9.重写选择关卡界面的绘图事件
    void paintEvent(QPaintEvent *event);
signals:
    void chooseSceneBack();

public slots:

private:
    //声明
    PlayScene *pScene = NULL;
};

#endif // CHOOSELEVELSCENE_H
