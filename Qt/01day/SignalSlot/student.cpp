#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::stuClassBegin(){
    qDebug()<<"上课， 全体起立...";
}

void Student::stuClassOver(){
    qDebug()<<"下课了， 该去吃放了...";
}

void Student::stuMath(){
    qDebug()<<"这节课是数学课...";
}

void Student::stuChinese(){
    qDebug()<<"这节课是语文课...";
}

void Student::stuEnglish(){
    qDebug()<<"这节课是英语课...";
}
