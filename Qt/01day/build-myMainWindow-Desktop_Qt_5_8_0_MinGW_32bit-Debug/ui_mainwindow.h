/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open;
    QAction *new_2;
    QAction *reback;
    QAction *quit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QMenu *menu_M;
    QMenu *menu_E;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        open = new QAction(MainWindow);
        open->setObjectName(QStringLiteral("open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        open->setIcon(icon);
        new_2 = new QAction(MainWindow);
        new_2->setObjectName(QStringLiteral("new_2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        new_2->setIcon(icon1);
        reback = new QAction(MainWindow);
        reback->setObjectName(QStringLiteral("reback"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        reback->setIcon(icon2);
        quit = new QAction(MainWindow);
        quit->setObjectName(QStringLiteral("quit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        quit->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 10, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 40, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 80, 91, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(190, 110, 75, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(190, 170, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu_M = new QMenu(menuBar);
        menu_M->setObjectName(QStringLiteral("menu_M"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_M->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menu_M->addAction(open);
        menu_M->addAction(new_2);
        menu_M->addAction(quit);
        menu_E->addAction(reback);

        retranslateUi(MainWindow);
        QObject::connect(quit, SIGNAL(changed()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200&O", Q_NULLPTR));
        open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        new_2->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        new_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        reback->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        reback->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
        quit->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", Q_NULLPTR));
        quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Critical", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Information", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Question", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Warning", Q_NULLPTR));
        menu_M->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225&M", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221&E", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
