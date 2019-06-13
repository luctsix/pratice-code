#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(480, 320);

    //-------创建菜单栏-------
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = menuBar->addMenu("文件&F");
    fileMenu->addAction("新建");
    fileMenu->addAction("打开");
    fileMenu->addAction("退出");

    QMenu *editMenu = menuBar->addMenu("编辑&E");
    editMenu->addAction("撤销");
    editMenu->addAction("粘贴");
    editMenu->addAction("全选");

    QMenu *helpMenu = menuBar->addMenu("帮助&H");
    helpMenu->addAction("目录");
    helpMenu->addAction("索引");
    helpMenu->addAction("关于");

    //-------创建工具栏---------
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->addAction("对齐");
    toolBar->addSeparator();
    toolBar->addAction("分栏");
    toolBar->addSeparator();
    toolBar->addAction("保存");
    toolBar->setFloatable(true);//设置浮动性
    toolBar->setMovable(true);//可移动

    //-------状态栏-----------------
    QStatusBar *statusBar = this->statusBar();

    QLabel *label = new QLabel("第一个应用程序", this);
    statusBar->addWidget(label);

    QLabel *label1 = new QLabel("版权所有", this);
    statusBar->addPermanentWidget(label1);

    //-----浮动窗口-------------
    QDockWidget *dockWidget = new QDockWidget("标题", this);

    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::LeftDockWidgetArea);
    dockWidget->setFloating(false);

    //------中心部件--------
    QTextEdit *textEdit = new QTextEdit();
    this->setCentralWidget(textEdit);

}

MainWindow::~MainWindow()
{

}
