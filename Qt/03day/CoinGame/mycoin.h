#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);

    //重写构造函数
    MyCoin(QString butlmg);
    //改变标志，执行翻转效果
    void changeFlag();
    void isVitory();
    QTimer *timer1;//定时器
    QTimer *timer2;//定时器
    int min = 1;
    int max = 8;

    int     posX;//x坐标
    int     posY;//y坐标
    bool    flag;//正反标志

    bool isWin = false;//判断是否胜利



    bool isAnimation = false;//代表金币是否正在翻转

protected:
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // MYCOIN_H
