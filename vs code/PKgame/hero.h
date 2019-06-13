#ifndef _HERO_H_
#define _HERO_H_

#include "weapon.hpp"
#include "file.h"
#include "monster.h"


using namespace std;

class Hero
{
public:
	Hero(int heroId){
        string Id = to_string(heroId);
         File f;
        vector<string> v;
        map<string, map<string, string>> m_hero;

        f.file_read("./Hero.csv", v, m_hero);
        map<string, string> m = m_hero[Id];
        cout<<m_hero[Id]["heroName"]<<endl;
        heroHp = atoi(m["heroHp"].c_str());
        heroAtk = atoi(m["heroAtk"].c_str());
        heroDef = atoi(m["heroDef"].c_str());
        heroName = m["heroName"];
        heroInfo = m["heroInfo"];
        pWeapon = NULL;
    }

	void Attack(Monster *monster){
        int crit = 0;
        int addHP = 0;
        int forzen = 0;
        int damage = 0;

        if(this->pWeapon == NULL){
            damage = this->heroAtk;
        }
        else{
            damage = this->heroAtk + this->pWeapon->getBaseDamage();
            addHP = this->pWeapon->getSuckBlood();
            forzen = this->pWeapon->getFrozen();
            crit = this->pWeapon->getCrit();
        }
        if(crit){
            damage = damage+crit;
            cout<<"英雄武器触发暴击，怪物<"<<monster->monsterName<<">受到暴击伤害"<<endl;
        }
        if(forzen){
            cout << "英雄武器触发冰冻效果,怪物<" << monster->monsterName << ">停止攻击一回合!" << endl;
        }
        if (addHP){
		cout << "英雄武器触发吸血效果,英雄血量增加" << addHP << "血!" << endl;
	    }
        monster->isFrozen = forzen;
        int trueDamage = (damage - monster->monsterDef > 0 ? damage - monster->monsterDef : 1);
        monster->monsterHp -= trueDamage;  //真实打到怪物上的伤害
        this->heroHp += addHP;  //吸血

        cout << "英雄<" << this->heroName << ">攻击怪物<" << monster->monsterName << ">,造成" << trueDamage << "点伤害!" << std::endl;
 
    }
	void EquipWeapon(Weapon *weapon){
        if(weapon == NULL)
            return;
        this->pWeapon = weapon;
        cout << "英雄<" << this->heroName << ">装备了武器<" << this->pWeapon->weaponName << ">!" << endl;
    }
public:
	int heroHp;
	int heroAtk;
	int heroDef;
	string heroName;
	string heroInfo;
	Weapon *pWeapon;
};




#endif