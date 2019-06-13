#ifndef _SPEECH_H
#define _SPEECH_H

#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
#include<numeric>

using namespace std;

class Speaker{
    public:
        string      name;
        deque<int>  score;
};
class mycompare{
    public:
        bool operator()(int a, int b){
            return a>b;}
};

void createPlayer(vector<Speaker> &v_speaker, vector<int> &v_id, int n);

void setCompetitor(multimap<int, Speaker> &m, vector<Speaker> &v_speaker);

void show_all(multimap<int, Speaker> &m);

void setScore(); 
void speech_contest(multimap<int, Speaker> &m_all, vector<int> &v_id_all, vector<int> &v_id_upgrade, int n, int m);


#endif