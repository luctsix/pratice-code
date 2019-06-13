#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTimer;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
private slots:
    void timerUpdate();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QTimer *timer;
};

#endif // WIDGET_H
