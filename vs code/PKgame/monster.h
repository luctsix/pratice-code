#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "file.h"
#include "hero.h"

class Monster{
    public:
        Monster(int monsterId){
            string Id = to_string(monsterId);
            File f;
            vector<string> v;       
            map<string, map<string, string>> m_monstor;        
            f.file_read("./Monsters.csv", v, m_monstor);

            map<string, string> m = m_monstor[Id];

            string monsterName = m["monsterName"];
            int monsterHp = atoi(m["monsterHp"].c_str());
            int monsterAtk = atoi(m["monsterAtk"].c_str());
            int monsterDef = atoi(m["monsterDef"].c_str());
            bool isFrozen = false;
        }
        void Attack(Hero *hero){
            if (this->isFrozen){
            std::cout << "怪物<" << this->monsterName << ">被冰冻,本回合无法攻击!" << std::endl;
            return;
            }

            //计算对英雄的伤害
            int damage = this->monsterAtk - hero->heroDef > 0 ? this->monsterAtk - hero->heroDef : 1;

            hero->heroHp -= damage;
            cout << "怪物<" << this->monsterName << ">攻击英雄<" << hero->heroName << ">,造成" << damage << "点伤害!" << endl;

        }
    public:
        string monsterName;
        int monsterHp;
        int monsterAtk;
        int monsterDef;
        bool isFrozen;
};

#endif