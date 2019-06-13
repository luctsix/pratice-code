#include "speech.h"
//1.生成选手和选手编号
void createPlayer(vector<Speaker> &v_speaker, vector<int> &v_id, int n){
    for(int i=0; i<n; i++)
    {
        Speaker p;
        string tmp = "选手";
        tmp += ('A'+i);
        p.name = tmp;
        v_speaker.push_back(p); //选手容器
        int n = 1001+i;
        v_id.push_back(n);      //选手编号容器
    }
}
//将所有选手根据编号放入map
void setCompetitor(multimap<int, Speaker> &m, vector<Speaker> &v_speaker){
    int i=0;
    for(vector<Speaker>::iterator it = v_speaker.begin(); it!=v_speaker.end(); ++it)
    {
        int tmp = 1001+i;
        i++;
        m.insert(make_pair(tmp, *it));
    }
}
//显示所有选手
void show_all(multimap<int, Speaker> &m){
    multimap<int, Speaker>::iterator it = m.begin();
    {
        for( ; it!=m.end(); ++it){
            cout<<it->first<<"  "<<it->second.name<<endl;
        }
    }
}
//评委给选手打分
void setScore(Speaker &sp){
    for(int i=0; i<10; i++)
    {
        int n = rand()%30+70;
        sp.score.push_back(n);
    }
}

//n:比赛轮数； m：每轮场数
void speech_contest(multimap<int, Speaker> &m_all, vector<int> &v_id_all, vector<int> &v_id_upgrade, int n, int m){
    vector<int>::iterator            it1 = v_id_all.begin();
    multimap<int, Speaker>::iterator it2;
    
    for(int i=0; i<n; i++)
    {
        multimap<int, int, mycompare>  m_tmp;
        for(int j=0; j<m; j++)
        {
            it2 = m_all.find(*it1);
            it2->second.score.clear();
            setScore(it2->second);

            sort(it2->second.score.begin(), it2->second.score.end());
            it2->second.score.pop_back();
            it2->second.score.pop_front();

            int sum;
            sum = accumulate(it2->second.score.begin(), it2->second.score.end(), 0);
            sum /= it2->second.score.size();
            m_tmp.insert(make_pair(sum, *it1));

            ++it1;
        }

        cout<<"第 "<<i+1<<" 组进级名单为："<<endl;
        multimap<int, int, mycompare>::iterator it_tmp = m_tmp.begin();

        for(int i=0; i<3; i++)
        {
            v_id_upgrade.push_back(it_tmp->second);
            it2 = m_all.find(it_tmp->second);
            cout<<it_tmp->second<<"  "<<it2->second.name<<"  "<<it_tmp->first<<endl;
            ++it_tmp;
        }
    }
}


