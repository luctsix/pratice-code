#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct QQ{
    int number;
    string name;
    string addr;
    int level;
}qq, *QQ;

class Info{
    public:
        virtual void setName(){
            string na;
            cout<<"请输入姓名:";
            cin>>na;
            name = na;
        }
        virtual void setSex(){
            string s;
            cout<<"请输入性别";
            cin>>s;
            sex = s;
        }
        virtual void setId(){
            int i;
            cout<<"请输入id:";
            cin>>i;
            id = i;
        }

        string getName(){return name;}
        string getSex(){return sex;}
        int getId(){return id;}

    private:
        string name;
        string sex;
        int id;
};

class Student:public Info{
    public:
        Student(int ag){age = ag;}
        Student(){};
        ~Student(){}; //cout<<"discontruct a student"<<endl;}

        void setAge(int ag){age = ag;}

        int getAge(){return age;}
    
    private:
        int age;
};

enum LeafType{ROUNG};
class Tree{
    public:
        void setType(enum LeafType t){this->type = t;}
        void setLeaveNums(int num){this->leavenums = num;}

        enum LeafType getType(return this->type;)
        int getNums(return this->leavenums;)

    private:
        enum LeafType type;
        int leavenums;
};

int main()
{
/*
   Student s1;

   s1.setName();
   s1.setId();
   s1.setSex();
   s1.setAge(24);

   cout<<"name:"<<s1.getName()<<endl;
   cout<<"sex:"<<s1.getSex()<<endl;
   cout<<"ID:"<<s1.getId()<<endl;
   cout<<"age:"<<s1.getAge()<<endl;
*/

vector<int> ivec (10);
for(int i =0; i<10; i++)
{
    ivec[i] = i;
    cout<<ivec[i];
}
auto b = ivec.begin(), e = ivec.end();
for(b; b!=e;b++)
     b = b+65;

vector<string> arr ;
    arr.push_back("sixn");
    arr.push_back("zhuzhu");

for(auto i : arr)
    cout<<i<<endl;






    // string s1("sisi");
    // cin>>s1;


    // for(int i=0; i != 3; i++)
    //  {
    //      s1[i] = toupper(s1[i]);
    //  }
    // cout<<s1<<endl;

    // cout<<s1<<endl;
    // getchar();
    // getline(cin, s1);
    // cout<<s1<<endl;
    // auto len  = s1.size();
    // cout<<len<<endl;
    



    // string s2 = "xixnixn";
    // cout<<s2<<endl;
    // cout<<"i="<<s1.empty();
    // cout<<s1+s2<<endl;
    // s2 = s1;
    // cout<<endl<<s2<<endl;



    // string s3 = s1;
    // string s4(s2);
    // cout<<s3<<s4;
    // string s5(10, 's');
    // cout<<s5;

    


    return 0;
}
