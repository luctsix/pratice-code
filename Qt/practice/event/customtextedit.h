#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

class CustomTextEdit:public QTextEdit
{
public:
    CustomTextEdit(QWidget *parent = 0);
    bool event(QEvent *e);
};

#endif // CUSTOMTEXTEDIT_H
