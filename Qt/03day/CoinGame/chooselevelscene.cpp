#include "chooselevelscene.h"
#include "mypushbutton.h"
#include "mainscene.h"

#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QRect>
#include <QVariant>
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置窗口固定大小、图标、和标题
    this->setFixedSize(320, 588);
    this->setWindowTitle("选择关卡");
    this->setWindowIcon(QIcon(":/image/Coin0001.png"));

    //设置菜单栏
    QMenuBar *menuBar = this->menuBar();
    QMenu    *menuMenu = new QMenu("菜单&M", this);
    QMenu    *helpMenu = new QMenu("帮助&H", this);
    menuBar->addMenu(menuMenu);
    menuBar->addMenu(helpMenu);
    //添加菜单选项的子菜单退出
    QAction *quitAction = new QAction("退出", this);
    menuMenu->addAction(quitAction);
    //关联退出的信号和槽
    connect(quitAction, &QAction::triggered, [=](){this->close();});

    //11.创建返回按键
    MyPushButton *backBtn = new MyPushButton(":/image/BackButton.png", ":/image/BackButtonSelected.png");
    backBtn->setParent(this);
    //移动按钮
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());

    //关联返回按钮的信号和槽
    connect(backBtn, &MyPushButton::clicked,[=](){
        QTimer::singleShot(500, this, [=](){
            QSound *chooseSound = new QSound(":/image/BackButtonSound.wav");
            chooseSound->play();
            this->hide();
            emit this->chooseSceneBack();
        });
    });

    //13.创建选择关卡按钮
    for(int i=0; i<20; ++i)
    {
        MyPushButton *menuBtn = new MyPushButton(":/image/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + (i%4)*70 , 130+ (i/4)*70);
        //按钮上显示文字
        QLabel *label = new QLabel(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        //设置居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //标签移动到关卡按钮的位置
        label->move(25 + (i%4)*70 , 130+ (i/4)*70);
        //鼠标穿透事件
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true);

        //14.监听选择关卡按钮的信号槽
        connect(menuBtn, &MyPushButton::clicked, [=](){
            if(pScene ==NULL)  //游戏场景最好不复用，直接移除创建新的场景
            {
                QSound *chooseSound = new QSound(":/image/TapButtonSound.wav");
                chooseSound->play();
                this->hide();
                pScene = new PlayScene(i+1); //将选择的关卡号，传给PlayScene
                pScene->setGeometry(this->geometry());        //优化--3
                pScene->show();
                //监听玩游戏界面的返回信号
                connect(pScene, &PlayScene::backChooseScene, [=](){
                    QSound *chooseSound = new QSound(":/image/BackButtonSound.wav");
                    chooseSound->play();
                    this->setGeometry(pScene->geometry());      //优化----4
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });

            }
        });
    }






}


//9.重写选择关卡界面的绘图事件
void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    //10.加载背景
    //10.1创建画家
    QPainter painter(this);
    //10.2构建pix对象
    QPixmap pix;
    //加载背景图片
    pix.load(":/image/OtherSceneBg.png");
    //画背景图片
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/image/Title.png");
    painter.drawPixmap(0, 30, pix.width(), pix.height(), pix);

}
