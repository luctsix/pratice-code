//multimap 案例
//公司今天招聘了 5 个员工，5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

#define SALE_DEPARMENT          1   //销售
#define DEVELOP_DEPARTMENT      2   //研发、开发
#define FINANCILA_DEPARTMENT    3   //财务
// #define HR_DEPARTMENT           4   //人资
// #define ADMINITER_DEPARTMENT    5   //行政
// #define PRODUCT_DEPARTMENT      6   //生产
#define ALL_DEPARTMENT          4   //所有

class person{
    public:
        string      name;
        int         age;
        string      tele;
        int         salary;
};

//1.生成人员信息
void CreatPerson(vector<person> &v, int n){
    string seed = "ABCDE";
    for(int i=0; i<5; i++)
    {
        person p;
        string tmp = "员工";
        tmp += seed[i];
        p.name = tmp;
        p.age = rand()%10+30;
        p.tele = "010-88888888";
        p.salary = rand()%10000+20000;
        v.push_back(p);
    }
}

//2.分配人员
void Distrubute(multimap<int, person> &m, vector<person> &v){
    cout<<"当前人员信息："<<endl;
    int operate = -1;
    for(vector<person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        int flags = 0;
        cout<<"姓名："<<it->name<<" 年龄："<<it->age<<" 电话："<<it->tele<<" 薪资："<<it->salary<<endl;
        cout<<"请输入所要分配的部门（1.销售部门 2.研发部门  3.财务部门  4.所有部门）："<<endl;
        cin>>operate;
        while(true){
            
            switch(operate){
                case SALE_DEPARMENT:
                    m.insert(make_pair(SALE_DEPARMENT, *it));
                    break;
                case DEVELOP_DEPARTMENT:
                    m.insert(make_pair(DEVELOP_DEPARTMENT, *it));
                    break;
                case FINANCILA_DEPARTMENT:
                    m.insert(make_pair(FINANCILA_DEPARTMENT, *it));
                    break;
                case ALL_DEPARTMENT:
                    m.insert(make_pair(ALL_DEPARTMENT, *it));
                    break;
                default:
                    cout<<"输入错误！请重新输入（1.销售部门 2.研发部门  3.财务部门  4.所有部门）"<<endl;
                    cin>>operate;
            }
            break;
        }
    }
}

//3.打印员工信息
void show(multimap<int, person> &m, int operate){
    if(operate == ALL_DEPARTMENT){
        for(multimap<int, person>::iterator it = m.begin(); it!=m.end(); ++it)
        {
            cout<<"姓名："<<it->second.name<<" 年龄："<<it->second.age
                <<" 电话："<<it->second.tele<<" 薪资："<<it->second.salary<<endl;
        }
    }

    int cnt = m.count(operate);
    int num = 0;
    multimap<int, person>::iterator it = m.find(operate);
    if(cnt!=0 && it!=m.end())
    {
        while(num<cnt && it!=m.end())
        {
            cout<<"姓名："<<it->second.name<<" 年龄："<<it->second.age
                <<" 电话："<<it->second.tele<<" 薪资："<<it->second.salary<<endl;
            num++;
            it++;
        }
    }
}
//根据用户操作显示不同部门的人员列表
void showPersonByPart(multimap<int, person> &m, int operate)
{
    
    switch(operate){
        case SALE_DEPARMENT:
            show(m, SALE_DEPARMENT);
            break;
        case DEVELOP_DEPARTMENT:
            show(m, DEVELOP_DEPARTMENT);
            break;
        case FINANCILA_DEPARTMENT:
            show(m, FINANCILA_DEPARTMENT);
            break;
        case ALL_DEPARTMENT:
            show(m, ALL_DEPARTMENT);
            break;
    }
}
//用户操作菜单
void operateMenu(multimap<int, person> &m){
    int operate = -1;
    int isexit = 0;

    while(true){
        cout<<"请输入您的操作（1.销售部门  2.研发部门  3.财务部门  4.所有部门  0.退出）: "<<endl;
        cin>>operate;

        switch(operate){
            case SALE_DEPARMENT:
                showPersonByPart(m, SALE_DEPARMENT);
                break;
            case DEVELOP_DEPARTMENT:
                showPersonByPart(m, DEVELOP_DEPARTMENT);
                break;
            case FINANCILA_DEPARTMENT:
                showPersonByPart(m, FINANCILA_DEPARTMENT);
                break;
            case ALL_DEPARTMENT:
                showPersonByPart(m, ALL_DEPARTMENT);
                break;
            case 0:
                isexit = 1;
                break;
            default:
                cout<<"您的输入有误！请重新输入（1.销售部门  2.研发部门  3.财务部门  4.所有部门  0.退出）";
                cin>>operate;
        }
        if(isexit == 1)
            break;
    }
}
int main(){
    vector<person> v;
    multimap<int, person> m;
    CreatPerson(v, 5);
    Distrubute(m, v);
    show(m, ALL_DEPARTMENT);
    operateMenu(m);
    return 0;
}
