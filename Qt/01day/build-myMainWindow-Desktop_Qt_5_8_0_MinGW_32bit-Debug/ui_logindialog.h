/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QPushButton *exitButton;
    QPushButton *loginButton;
    QLineEdit *usrLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(400, 300);
        exitButton = new QPushButton(loginDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(220, 210, 81, 23));
        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(70, 210, 81, 23));
        usrLineEdit = new QLineEdit(loginDialog);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));
        usrLineEdit->setGeometry(QRect(120, 80, 241, 20));
        label = new QLabel(loginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 81, 21));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(loginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 101, 21));
        label_2->setFont(font);
        pwdLineEdit = new QLineEdit(loginDialog);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(121, 129, 241, 20));
        pwdLineEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(loginDialog);
        QObject::connect(exitButton, SIGNAL(clicked()), loginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", Q_NULLPTR));
        exitButton->setText(QApplication::translate("loginDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        loginButton->setText(QApplication::translate("loginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        usrLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        usrLineEdit->setText(QString());
        usrLineEdit->setPlaceholderText(QApplication::translate("loginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label->setText(QApplication::translate("loginDialog", "ACCOUNT", Q_NULLPTR));
        label_2->setText(QApplication::translate("loginDialog", "PASSWORD", Q_NULLPTR));
        pwdLineEdit->setText(QString());
        pwdLineEdit->setPlaceholderText(QApplication::translate("loginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
