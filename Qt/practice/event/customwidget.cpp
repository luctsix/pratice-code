#include "customwidget.h"

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>



bool CustomWidget::event(QEvent *e)
{
    if(e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if(keyEvent->key() == Qt::Key_Tab)
        {
            qDebug()<<"You press tab...";
            return true;
        }
    }
    return QWidget::event(e);
}
