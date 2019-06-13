//multimap 案例
//公司今天招聘了 5 个员工，5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<conio.h>

using namespace std;

#define SALE_DEPARMENT          1   //销售
#define DEVELOP_DEPARTMENT      2   //研发、开发
#define FINANCILA_DEPARTMENT    3   //财务
#define HR_DEPARTMENT           4   //人资
#define ADMINITER_DEPARTMENT    5   //行政
#define PRODUCT_DEPARTMENT      6   //生产
#define ALL_DEPARTMENT          7   //所有

//个人信息：姓名、性别、年龄、电话、薪水、工作ID、住址、身份证ID\出生年月日
class person{
    public:
        person(string n, string s, int a):name(n),sex(s), age(a){}
        string      name;
        string      sex;
        int         age;
        string      tele;
        int         salary;
        string      workID;
        string      addr;
        string      perID;
        string      born;
};
//打印操作列表
void showMenu();
//操作列表
void operateMenu(multimap<int, person> &m);
//打印员工信息
void print_person(multimap<int, person> &m);
//入职
void inWork(multimap<int, person> &m);
void Push(multimap<int, person> &m, int n, person &p);
//离职
void offWork(multimap<int, person> &m);
//查看某个员工的所有信息
void showSomeOne(multimap<int, person> &m, string name);