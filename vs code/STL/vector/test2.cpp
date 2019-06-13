#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;
//multimap 案例
//公司今天招聘了 5 个员工，5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息

#define SALE_DEPATMENT      1 //销售
#define DEVELOP_DEPATMENT   2 //研发
#define FINANCIAL_DEPATMENT 3 //财务
#define ALL_DEPARTMENT      4 //所有

class Person{
    public:
        string  name;
        int     age;
        string  tele;
        double  salary;
};
//创建5个员工
void CreatePerson(vector<Person*> &v){
    string seed = "ABCDE";
    for(int i=0; i<5; i++)
    {
        Person* p = new Person;
        p->name = "员工";
        p->name+= seed[i];
        p->age  = rand()%30+20;
        p->tele = "010-88888888";
        p->salary = rand()%20000+10000;
        v.push_back(p); 
    }
}
//5个员工分配到不同的部门
void PersonByGroup(vector<Person*> &v, multimap<int, Person*> &plist){
    int operate = -1; //用户的操作
    vector<Person*>::iterator it = v.begin();
    for( ; it!=v.end(); it++)
    {
        cout<<"当前员工信息："<<endl;
        cout<<"姓名："<<(*it)->name<<" 年龄："<<(*it)->age<<" 工资： "<<(*it)->salary
            <<" 电话："<<(*it)->tele<<endl;
        cout<<"请对该员工进行部门分配（1.销售部门  2.研发部门  3.财务部门）："<<endl;
        scanf("%d", &operate);
        while(1)
        {
            switch(operate){
                case SALE_DEPATMENT:
                    plist.insert(make_pair(SALE_DEPATMENT, *it));
                    cout<<"testing..."<<endl;
                    break;
                case DEVELOP_DEPATMENT:
                    plist.insert(make_pair(DEVELOP_DEPATMENT, *it));
                    break;
                case FINANCIAL_DEPATMENT:
                    plist.insert(make_pair(FINANCIAL_DEPATMENT, *it));
                    break;
                case ALL_DEPARTMENT:
                    plist.insert(make_pair(ALL_DEPARTMENT, *it));
                    break;
                default:
                    cout<<"您的输入有误，请重新输入（1.销售部门  2.研发部门  3.财务部门）"<<endl;
                    scanf("%d", &operate);
            }
            break;
        }
        cout<<"员工分配完毕！"<<endl;
        cout<<"*******************************************************************"<<endl;
    }
}
//打印员工信息
void printList(multimap<int, Person*>&plist, int myoprate){
    if(myoprate == ALL_DEPARTMENT){
        for(multimap<int, Person*>::iterator it = plist.begin(); it!=plist.end(); it++)
        {
            cout<<"姓名："<<it->second->name<<" 年龄："<<it->second->age<<" 工资： "<<it->second->salary
                <<" 电话："<<it->second->tele<<endl;
        }
        return;
    }

    multimap<int, Person*>::iterator it = plist.find(myoprate);
    int depatCount = plist.count(myoprate);
    int num = 0;
    if(it != plist.end()){
        while(it != plist.end() && num < depatCount){
             cout<<"姓名："<<it->second->name<<" 年龄："<<it->second->age<<" 工资： "<<it->second->salary
                 <<" 电话："<<it->second->tele<<endl;
                 it++;
                 num++;
        }
    }
}
//根据用户操作显示不同部门的人员列表
void ShowPersonList(multimap<int, Person*>& plist, int myoperate){
    switch(myoperate){
        case SALE_DEPATMENT:
            printList(plist, SALE_DEPATMENT);
            break;
        case DEVELOP_DEPATMENT:
            printList(plist, DEVELOP_DEPATMENT);
            break;
        case FINANCIAL_DEPATMENT:
            printList(plist, FINANCIAL_DEPATMENT);
            break;
        case ALL_DEPARTMENT:
            printList(plist, ALL_DEPARTMENT);
            break;
    }
}
//用户操作菜单
void PersonMenu(multimap<int, Person*> &plist){
    int flag = -1;
    int isexit = 0;
    while(true){
        cout<<"请输入您的操作（1.销售部门  2.研发部门  3.财务部门  4.所有部门  0.退出）: "<<endl;
        cin>>flag;

        switch(flag){
            case SALE_DEPATMENT:
                ShowPersonList(plist, SALE_DEPATMENT);
                break;
            case DEVELOP_DEPATMENT:
                ShowPersonList(plist, DEVELOP_DEPATMENT);
                break;
            case FINANCIAL_DEPATMENT:
                ShowPersonList(plist, FINANCIAL_DEPATMENT);
                break;
            case ALL_DEPARTMENT:
                ShowPersonList(plist, ALL_DEPARTMENT);
                break;
            case 0:
                isexit = 1;
                break;
        }
        if(isexit == 1)
            break;
    }
}

int main(){
    vector<Person*> vlist;
    multimap<int, Person*> plist;
    CreatePerson(vlist);
    PersonByGroup(vlist, plist);
    PersonMenu(plist);

    return 0;
}