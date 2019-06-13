#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:

public slots:
    void stuClassBegin();
    void stuClassOver();
    void stuMath();
    void stuChinese();
    void stuEnglish();
};

#endif // STUDENT_H
