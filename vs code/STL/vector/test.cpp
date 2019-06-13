
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去
除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分
打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最
低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

class Person{
    public:
        Person(string name){this->name = name;}
        void setName(string name){this->name = name;}
        void setScore(){
            cout<<"please input "<<this->name<<"'s score: "<<endl;
            for(int i=0; i<10; i++)
            {
                int score;
                cin>>score;
                this->score.push_back(score);
            }
        }
        string getName(){return this->name;}
        void mySort(){
            //deque<int>::iterator it = this->score.begin();
            sort(score.begin(), score.end());
            score.pop_back();
            score.pop_front();
        }

        int getAverscore(){
            mySort();
            deque<int>::iterator it = score.begin();
            int sum = 0;
            for( ; it!=score.end(); it++)
            {
                sum += *it;
            }
            return sum/score.size();
        }

    private:
        string name;
        deque<int> score;
};
int main(){
    vector<Person*> v;
    Person p1("A");
    Person p2("B");
    Person p3("C");
    Person p4("D");
    Person p5("E");

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //输入分数
    vector<Person*>::iterator it = v.begin();
    for( ; it!=v.end(); it++)
    {
        (*it)->setScore();
    }
    //输出分数
    for(auto &r : v)
    {
        cout<<r->getName()<<"'s average score is: "<<r->getAverscore()<<endl;
    }

    return 0;
}