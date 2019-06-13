#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建新的对象
    QAction  *openAction = new QAction(tr("&打开"), this);
    //添加图标
    QIcon icon(":/myImages/3.png");
    openAction->setIcon((icon));
    //设置快捷键
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    //在文件菜单中设置新的打开动作
    ui->menu_N->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
