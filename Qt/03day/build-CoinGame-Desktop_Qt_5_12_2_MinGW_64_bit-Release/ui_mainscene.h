/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionQUit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_M;
    QMenu *menu_H;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QString::fromUtf8("MainScene"));
        MainScene->resize(400, 300);
        actionQUit = new QAction(MainScene);
        actionQUit->setObjectName(QString::fromUtf8("actionQUit"));
        centralWidget = new QWidget(MainScene);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScene);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu_M = new QMenu(menuBar);
        menu_M->setObjectName(QString::fromUtf8("menu_M"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainScene->setMenuBar(menuBar);

        menuBar->addAction(menu_M->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_M->addAction(actionQUit);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QApplication::translate("MainScene", "MainScene", nullptr));
        actionQUit->setText(QApplication::translate("MainScene", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQUit->setShortcut(QApplication::translate("MainScene", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        menu_M->setTitle(QApplication::translate("MainScene", "\350\217\234\345\215\225&M", nullptr));
        menu_H->setTitle(QApplication::translate("MainScene", "\345\270\256\345\212\251&H", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
