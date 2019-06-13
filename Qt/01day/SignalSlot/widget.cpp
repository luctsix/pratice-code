#include "widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(480, 320);
    this->setFixedSize(480, 320);

    QPushButton *btn1 = new QPushButton("老师", this);
    QPushButton *btn2 = new QPushButton("学生", this);
    btn1->move(360, 100);
    btn2->move(360, 150);

    teach = new Teacher(this);
    stu = new Student(this);

//    connect(teach, &Teacher::teachClassBegin, stu, &Student::stuClassBegin);
//    connect(teach, &Teacher::teachChinese, stu, &Student::stuChinese);
//    connect(teach, &Teacher::teachEnglish, stu, &Student::stuEnglish);
//    connect(teach, &Teacher::teachMath, stu, &Student::stuMath);
//    connect(teach, &Teacher::teachClassOver, stu, &Student::stuClassOver);
#if 0
    //一个信号和多个槽相连
    connect(btn1, &QPushButton::clicked, [=](){
        stu->stuClassBegin();
        stu->stuEnglish();
    });
    //多个信号和一个槽相连
    connect(btn1, &QPushButton::clicked, [=](){
        stu->stuClassBegin();
        //stu->stuEnglish();
    });
    connect(btn2, &QPushButton::clicked, [=](){
        stu->stuClassBegin();
        //stu->stuEnglish();
    });
#endif
    //一个信号可以连接到另外的一个信号
    connect(btn1, &QPushButton::clicked, btn2, &QPushButton::clicked);

    connect(btn2, &QPushButton::clicked, [=](){
        stu->stuClassBegin();
        //stu->stuEnglish();
    });
    //信号和槽可以断开连接
    disconnect(btn1, &QPushButton::clicked, btn2, &QPushButton::clicked);
    //TeacherDo();


}

void Widget::TeacherDo(){
    emit teach->teachClassBegin();
    emit teach->teachClassOver();
    emit teach->teachChinese();
    emit teach->teachEnglish();
    emit teach->teachMath();
}

Widget::~Widget()
{

}
