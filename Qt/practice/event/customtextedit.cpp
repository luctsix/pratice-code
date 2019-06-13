#include "customtextedit.h"

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>


CustomTextEdit::CustomTextEdit(QWidget *parent)
{
    this->setParent(parent);
}

bool CustomTextEdit::event(QEvent *e)
{
    if(e->type() == QKeyEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(e);
        if(keyEvent->key() == Qt::Key_Tab)
        {
            qDebug()<<"You press tab...";
            return true;
        }
    }
    return false;
}
