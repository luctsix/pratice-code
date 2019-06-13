#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QTimer>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>

PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}


//构造函数重载
PlayScene::PlayScene(int index)
{
    this->levelIndex = index;

    //15.设置应用窗口的属性
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/image/Title.png"));
    this->setWindowTitle(QString("翻金币: 第 %1 关").arg(levelIndex));

    //16.设置菜单栏
    QMenuBar *menuBar = this->menuBar();
    QMenu *menuMenu = new QMenu("菜单&M");
    QMenu *helpMenu = new QMenu("帮助&H");
    menuBar->addMenu(menuMenu);
    menuBar->addMenu(helpMenu);
    QAction *quitAction = new QAction("退出");
    menuMenu->addAction(quitAction);
    connect(quitAction, &QAction::triggered, [=](){this->close();});

    //18.显示当前关卡数
    QLabel *label = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    label->setText(QString("LEVEL: %1").arg(levelIndex));
    label->setGeometry(QRect(30, this->height()-50, 120, 50));

    //19.构建返回按钮
    MyPushButton *backBtn = new MyPushButton(":/image/BackButton.png", ":/image/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());
    //关联返回按钮的信号和槽
    connect(backBtn, &MyPushButton::clicked, [=](){
        //返回音效
        QSound *backSound = new QSound(":/image/BackButtonSound.wav");
        backSound->play();

        this->hide();
        emit this->backChooseScene();
    });

    //构建胜利标签
    QLabel *winLabel = new QLabel(this);
    QPixmap tmpPix;
    tmpPix.load(":/image/LevelCompletedDialogBg.png");
    winLabel->setPixmap(tmpPix);
    winLabel->hide();


    //20.创建金币背景图片
    dataConfig *data = new dataConfig(this);
    //QMap<int, QVector< QVector<int> > >::iterator it = data->mData.begin();    //mData;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            //生成存放金币的标签
            QLabel *label = new QLabel(this);
            label->setGeometry(0, 0, 50, 50);
            label->setPixmap(QPixmap(":/image/BoardNode.png"));
            label->move(57+i*50, 200+j*50);

            //读取配置文件，并设置金币的正反状态和记录金币信息
            this->gameArray[i][j] = data->mData[this->levelIndex][i][j];
            QString img;
            //判断该位置的金币的颜色
            if(this->gameArray[i][j] == 1)
            {
                img = ":/image/Coin0001.png";
            }
            else
            {
                img = ":/image/Coin0008.png";
            }

            //创建金币类对象
            MyCoin *coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59+i*50, 204+j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];

            //保存所创建的金币
            coinBtnArray[i][j] = coin;
            //监听金币的点击事件，关联信号和槽
            connect(coin, &MyCoin::clicked, this, [=](){
                //点击音效
                QSound *tapSound = new QSound(":/image/TapButtonSound.wav");
                tapSound->play();
                //点击后，所有金币设置成不可点击状态
                for(int i=0; i<4; i++)//设置金币处于胜利状态，禁止金币继续点击翻转
                {
                    for(int j=0; j<4; j++)
                    {
                        coinBtnArray[i][j]->isWin = true;
                    }
                }
                //金币翻转
                coin->changeFlag();
                gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0; //数组内部的标志同步修改

                QTimer::singleShot(300, this, [=](){
                    if(coin->posX+1<=3)
                    {
                        coinBtnArray[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] =
                                gameArray[coin->posX+1][coin->posY]==0 ? 1 : 0;
                    }
                    if(coin->posX-1>=0)
                    {
                        coinBtnArray[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] =
                                gameArray[coin->posX-1][coin->posY]==0 ? 1 : 0;
                    }
                    if(coin->posY+1<=3)
                    {
                        coinBtnArray[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] =
                                gameArray[coin->posX][coin->posY+1]==0 ? 1 : 0;
                    }
                    if(coin->posY-1>=0)
                    {
                        coinBtnArray[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] =
                                gameArray[coin->posX][coin->posY-1]==0 ? 1 : 0;
                    }
                    //翻转结束后，重新激活金币的可点击性
                    for(int i=0; i<4; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            coinBtnArray[i][j]->isWin = false;
                        }
                    }
                    //判断游戏是否胜利
                    this->isWin = true;
                    for(int i=0; i<4; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            if(coinBtnArray[i][j]->flag == false)
                                this->isWin = false;
                        }
                    }
                    if(this->isWin == true)
                    {
                        //胜利音效
                        QSound *winSound = new QSound(":/image/LevelWinSound.wav");
                        winSound->play();
                        for(int i=0; i<4; i++)//设置金币处于胜利状态，禁止金币继续点击翻转
                        {
                            for(int j=0; j<4; j++)
                            {
                                coinBtnArray[i][j]->isWin = true;
                            }
                        }

                        qDebug()<<"胜利";
                        winLabel->show();
                        winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
                        winLabel->move((this->width()-tmpPix.width())*0.5, tmpPix.height());

                        //构建胜利标签的动画
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(), winLabel->y(),winLabel->width(), winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(), winLabel->y()+114, winLabel->width(), winLabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });
            });
        }
    }
}


//17.重写玩游戏场景的绘图事件
void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/image/PlayLevelSceneBg.png");

    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/image/Title.png");

    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);

}
