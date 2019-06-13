#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget();

    bool event(QEvent *e);

signals:

public slots:
};

#endif // CUSTOMWIDGET_H
