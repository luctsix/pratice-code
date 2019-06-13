#include "work.h"

void show_person(person &p){
    cout<<"  姓名："     <<p.name;
    cout<<"  性别："     <<p.sex;
    cout<<"  出生日期：" <<p.born;
    cout<<"  年龄："     <<p.age<<endl;
    cout<<"  工作ID："   <<p.workID;
    cout<<"  身份证："   <<p.perID;
    cout<<"  住址："     <<p.addr;
    cout<<"  电话："     <<p.tele;
    cout<<"  薪水： "    <<p.salary<<endl;
    cout<<"----------------------------------------"<<endl;
}

//打印操作列表
void showMenu(){
        system("cls");
        cout<<"请输入你想要进行的操作"<<endl;
        cout<<"1.员工入职"<<endl;
        cout<<"2.员工离职"<<endl;
        cout<<"3.查看信息"<<endl;
        cout<<"4.退出"<<endl;
}
//查看某个员工的所有信息
void showSomeOne(multimap<int, person> &m){
    cout<<"请输入离职员工的姓名:";
    string name;
    cin>>name;
    multimap<int, person>::iterator it = m.begin();
    for(; it!=m.end(); ++it)
    {
        if(name == it->second.name)     break;
    }
    if(it == m.end())
    {
        cout<<"公司里没有这个人";
        return;
    }
    cout<<it->first<<endl;
    show_person(it->second);
}
//打印员工信息
//1.销售 2.研发 3.财务 4.人资 5.行政 6.生产 7.所有 8.查看某员工信息
void print_person(multimap<int, person> &m, int operate){
    if(operate == 8){
        showSomeOne(m);
    }
    if(operate == 7){
        for(multimap<int, person>::iterator it=m.begin(); it!=m.end(); it++){
            show_person(it->second);
        }
    }

    int cnt = m.count(operate);
    int num = 0;
    multimap<int, person>::iterator it = m.find(operate);
    if(it!=m.end()){
        while(num<cnt && it!=m.end())
        {
            show_person(it->second);
            num++;
            it++;
        }
    }


}

void Push(multimap<int, person> &m, int n, person &p){
    switch(n){
        case 1:
            m.insert(make_pair(SALE_DEPARMENT, p));
            break;
        case 2:
            m.insert(make_pair(DEVELOP_DEPARTMENT, p));
            break;
        case 3:
            m.insert(make_pair(FINANCILA_DEPARTMENT, p));
            break;
        case 4:
            m.insert(make_pair(HR_DEPARTMENT, p));
            break;
        case 5:
            m.insert(make_pair(ADMINITER_DEPARTMENT, p));
            break;
        case 6:
            m.insert(make_pair(PRODUCT_DEPARTMENT, p));
            break;
    }
}
//入职
void inWork(multimap<int, person> &m){
    int flag = 1;
    while(true){
        system("cls");
        cin>>flag;
        if(flag<0)   return;
        //个人信息：姓名、性别、年龄、电话、薪水、工作ID、住址、身份证ID
        cout<<"请输入你的信息："<<endl;
        cout<<"姓名：";
        string name;
        cin>>name;
        cout<<"性别";
        string sex;
        cin>>sex;
        cout<<"年龄：";
        int age;    cin>>age;
        person p(name, sex, age);
        cout<<"出生日期：";
        string tmp;
        cin>>tmp;
        p.born = tmp;
        cout<<"电话：";
        cin>>tmp;
        p.tele = tmp;
        cout<<"住址：";
        cin>>tmp;
        p.addr = tmp;
        cout<<"身份证：";
        cin>>tmp;
        p.perID = tmp;
        p.salary = rand()%8000+6000;
        p.workID = "190405";
        p.workID += (flag%26+'A');
        cout<<"所在部门(1.销售 2.研发 3.财务 4.人资 5.行政 6.生产)";
        int operate;
        cin>>operate;
        Push(m, operate, p);
    }
}
//离职
void offWork(multimap<int, person> &m){
    cout<<"请输入离职员工的姓名:";
    string name;
    cin>>name;
    multimap<int, person>::iterator it = m.begin();
    for(; it!=m.end(); ++it)
    {
        if(name == it->second.name)     break;
    }
    if(it == m.end())
    {
        cout<<"公司里没有这个人";
        
        return;
    }
    m.erase(it);
}


//操作列表
void operateMenu(multimap<int, person> &m){
    int flags;
    while(true){
        showMenu();
        cin>>flags;
        switch(flags){
            case 1:
                inWork(m);
                system("pause");
                break;
            case 2:
                offWork(m);
                system("pause");
                break;
            case 3:
            {
                cout<<"请选择你要查看的部门(1.销售 2.研发 3.财务 4.人资 5.行政 6.生产 7.所有 8.查看某员工信息)：";
                int n;
                cin>>n;
                print_person(m, n);
                system("pause");
                break;
            }
            case 4:
                return;
            default:
                cout<<"您的输入有误，按任意键返回..."<<endl;
                system("pause");
                showMenu();
        }
    }
}