#ifndef _FILE_H_
#define _FILE_H_


#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

void mystrock(string buf, vector<string> &v){
    int start = 0;
    int count = 0;

    while(1)
    {
        int count = buf.find(",", start);
        string tmp;
        if(count == -1)
        {
            tmp = buf.substr(start, count-start);
            v.push_back(tmp);
            break;
        }
        tmp = buf.substr(start, count-start);
        v.push_back(tmp);
        start = count+1;
    }
}

class File{
    public:
        void file_read(string path, vector<string> &v, map<string, map<string, string>> &m){
            ifstream ifs;
            ifs.open(path, ios::in);

            if(!ifs)
            {
                perror("");
                return;
            }
            string buf;
            ifs>>buf;

            int start = 0;
            int count = 0;
            mystrock(buf, v);
            string tmp;
            vector<string> v1;
            map<string, string> m_tmp;
            while(ifs>>tmp)
            {
                v1.clear();
                m_tmp.clear();
                mystrock(tmp, v1);

                vector<string>::iterator it1 = v.begin();
                vector<string>::iterator it2 = v1.begin();
                for(; it1!=v.end(); ++it1, ++it2)
                {
                    m_tmp.insert(make_pair(*it1, *it2));
                }
                //cout<<m_tmp["monsterId"]<<endl;
                m.insert(make_pair(m_tmp[*(v.begin())], m_tmp));
                }
                map<string, map<string, string>>::iterator it = m.begin();
                // /cout<<m["5"]["heroName"]<<endl;

                ifs.close();
            
            }
};



#endif