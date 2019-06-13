#include "speech.cpp"


int main(){
    vector<Speaker>         v_speaker;
    vector<int>             v_id_all;
    multimap<int, Speaker>  m_all;
    vector<int>             v_id_upgrade; //晋级选手编号名单

    createPlayer(v_speaker, v_id_all, 24);
    setCompetitor(m_all, v_speaker);
    cout<<"所有参赛选手："<<endl;
    show_all(m_all);

    cout<<"-------------------------"<<endl;
    random_shuffle(v_id_all.begin(), v_id_all.end());
    cout<<"第一轮比赛："<<endl;
    speech_contest(m_all, v_id_all, v_id_upgrade, 4, 6);

    cout<<"-------------------------"<<endl;
    cout<<"第二轮比赛："<<endl;
    random_shuffle(v_id_all.begin(), v_id_all.end());
    v_id_all.swap(v_id_upgrade);
    v_id_upgrade.clear();
    speech_contest(m_all, v_id_all, v_id_upgrade, 2, 6);

    cout<<"-------------------------"<<endl;
    cout<<"第三轮比赛："<<endl;
    random_shuffle(v_id_all.begin(), v_id_all.end());
    v_id_all.swap(v_id_upgrade);
    v_id_upgrade.clear();
    speech_contest(m_all, v_id_all, v_id_upgrade, 1, 6);

    cout<<"-------------------------"<<endl;
    return 0;
}

