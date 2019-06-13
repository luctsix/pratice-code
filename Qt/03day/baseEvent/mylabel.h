#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

signals:

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev) ;
    void mouseReleaseEvent(QMouseEvent *ev) ;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

public slots:
};

#endif // MYLABEL_H
