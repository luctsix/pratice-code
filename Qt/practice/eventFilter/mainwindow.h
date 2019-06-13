#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
