/*
a)	构造函数私有化
b)	提供一个全局的静态方法（全局访问点）
c)	在类中定义一个静态指针，指向本类的变量的静态变量指针 
*/
#include<iostream>
using namespace std;

class Singleton{
    private:
        Singleton(){
            m_singer = NULL;
            m_count  = 0;
            cout<<"构造函数 Singleton...do"<<endl;
        }
    public:
        static Singleton *getInstance(){
            if(m_singer == NULL)    //懒汉式：1.每次获取实例都会判断，多线程会有问题
            {
                m_singer = new Singleton;
            }
            return m_singer;
        }
        static void printT(){
            cout<<"m_count: "<<m_count<<endl;
        }
    private:
        static Singleton *m_singer;
        static int        m_count;    
    };
Singleton *Singleton::m_singer = NULL;
int Singleton::m_count         = 0;
void test01(){ 
    cout<<"演示  懒汉式"<<endl;
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    if(p1 != p2)
    {
        cout<<"不是同一个对象"<<endl;
    }
    else
    {
        cout<<"是同一个对象"<<endl;
    }
    p1->printT();
    p2->printT();
}

class Singleton2{   //饿汉式
    private:
        Singleton2(){
            m_single = NULL;
            m_count  = 0;
            cout<<"构造函数 Singleton...do"<<endl;
        }
    public:
        static Singleton2* getInstance(){
            if(m_single == NULL)
            {
                m_single = new Singleton2;
            }
            return m_single;
        }
        static void FreeInstance(){
            if(m_single != NULL)
            {
                delete m_single;
                m_single = NULL;
                m_count  = 0;
            }
        }   
        static void printT(){
            cout<<"m_count: "<<m_count<<endl;
        }
    private:
        static Singleton2 *m_single;
        static int         m_count;
};
Singleton2* Singleton2::m_single = new Singleton2;
int         Singleton2::m_count  = 0;
void test02(){
    cout<<"演示 饿汉式"<<endl;
    Singleton2 *p1 = Singleton2::getInstance();
    Singleton2 *p2 = Singleton2::getInstance();
    if(p1 != p2)
    {
        cout<<"不是同一个对象"<<endl;
    }
    else{
        cout<<"是同一个对象"<<endl;
    }
    p1->printT();
    p2->printT();

    Singleton2::FreeInstance();
    Singleton2::FreeInstance();
}

int main(){
    //test01();
    test02();
    return 0;
}