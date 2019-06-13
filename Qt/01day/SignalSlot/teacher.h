#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals:
    void teachClassBegin();
    void teachClassOver();
    void teachMath();
    void teachChinese();
    void teachEnglish();

public slots:
};

#endif // TEACHER_H
