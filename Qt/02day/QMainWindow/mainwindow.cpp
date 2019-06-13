#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QKeySequence>
#include <QToolBar>
#include <QLabel>
#include <QPushButton>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(480, 320);
    this->setWindowTitle("MainWindow 设计");

    //---------菜单栏------------
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = new QMenu("文件&F", this);
    QMenu *editMenu = new QMenu("编辑&E", this);
    QMenu *helpMenu = new QMenu("帮助&H", this);
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    menuBar->addMenu(helpMenu);

    QAction *open = new QAction("打开", this);
    QAction *New  = new QAction("新建", this);
    QAction *quit = new QAction("退出", this);
    connect(quit, &QAction::triggered, this, &QMainWindow::close);
    fileMenu->addAction(open);
    fileMenu->addAction(New);
    fileMenu->addAction(quit);

    editMenu->addAction("撤销");
    editMenu->addAction("全选");
    editMenu->addAction("粘贴");

    helpMenu->addAction("关于");
    helpMenu->addAction("索引");
    helpMenu->addAction("目录");

    //---------工具栏-----------
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);
    toolBar->setMovable(true);
    toolBar->setFloatable(true);

    toolBar->addAction("open");
    toolBar->addSeparator();
    QLabel *label = new QLabel("A");
    toolBar->addWidget(label);
    toolBar->addSeparator();
    toolBar->addWidget(new QPushButton("B", this));

    //----------状态栏-----------------
    QStatusBar *statusBar = this->statusBar();
    QPushButton *btnMenu = new QPushButton("菜单", this);
    statusBar->addWidget(btnMenu);
//    QAction *tmp = new QAction("world",this);
//    statusBar->addAction(tmp);

    QLabel *label1 = new QLabel("版权所有");
    statusBar->addPermanentWidget(label1);

    //-------浮动窗口----------------
    QDockWidget *dockWidget = new QDockWidget("提示", this);
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
    dockWidget->setFloating(false);
    //--------中心部件-------------
    QTextEdit *text = new QTextEdit;
    this->setCentralWidget(text);

}

MainWindow::~MainWindow()
{

}
