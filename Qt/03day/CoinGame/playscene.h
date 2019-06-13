#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);

    //构造函数重载
    PlayScene(int index);
    MyCoin *coinBtnArray[4][4]; //保存一副图中的所有金币


protected:
    void paintEvent(QPaintEvent *event);



private:
    int levelIndex; //记录关卡索引
    int gameArray[4][4];
    bool isWin = true; // 判断是否胜利

signals:
    void backChooseScene();

public slots:
};

#endif // PLAYSCENE_H
