#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

int main()
{

    vector<int> v1;
    for(int i=0; i<10; i++)
    {
        v1.push_back(rand()%100);
    }
    cout<<"size:"<<v1.size()<<endl;
    cout<<"isempty"<<v1.empty()<<endl;
    cout<<"capacity:"<<v1.capacity()<<endl;
    vector<int>::iterator it = v1.begin();
    while(it != v1.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    v1.clear();
    cout<<"size:"<<v1.size()<<endl;
    cout<<"isempty:"<<v1.empty()<<endl;


    return 0;
}

