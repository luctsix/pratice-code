#include "mainscene.h"
#include "ui_mainscene.h"

#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "mypushbutton.h"
#include <QTimer>
#include "chooselevelscene.h"
#include <QSound>


MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //1.退出菜单信号和槽的关联
    connect(ui->actionQUit, &QAction::triggered, this, [=](){
        this->close();
    });

    //2.固定窗口大小
    this->setFixedSize(320, 588);

    //3.设置应用图标和标题
    this->setWindowIcon(QIcon(":/image/Coin0001.png"));
    this->setWindowTitle("CoinGame");

    //6.主界面加载开始按钮
    //6.1创建自定义按钮
    MyPushButton *startBtn = new MyPushButton(":/image/MenuSceneStartButton.png");
    //6.2设置按钮的父控件
    startBtn->setParent(this);
    //6.3移动按钮到适当的位置
    startBtn->move(this->width()*0.5-startBtn->width()*0.5, this->height()*0.7);


    //7.开始按钮的条约特效实现
    connect(startBtn, &MyPushButton::clicked, [=](){
        QSound *chooseSound = new QSound(":/image/TapButtonSound.wav");
        chooseSound->play();
        startBtn->zoom1();//向上跳跃
        startBtn->zoom2();//向下跳跃

        //8.延迟500ms后，进入构建选择关卡界面
        //选择关卡场景
        ChooseLevelScene *chooseScene = new ChooseLevelScene;
        QTimer::singleShot(500, this, [=](){
            this->hide();
            chooseScene->setGeometry(this->geometry()); //优化 --1 绑定设置场景的位置
            chooseScene->show();
            connect(chooseScene, &ChooseLevelScene::chooseSceneBack,[=](){
                //chooseScene->hide();
                this->setGeometry(chooseScene->geometry());//优化 --2 绑定设置场景的位置
                this->show();
            });
        });
    });
}

MainScene::~MainScene()
{
    delete ui;
}


//重写绘画事件
void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;

    //4.1加载应用程序背景
    pix.load(":/image/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //4.2加载标题
    pix.load(":/image/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
