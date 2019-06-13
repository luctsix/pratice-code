#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "file.h"

using namespace std;

//武器基类
class Weapon
{
public:
	//获取基础伤害
	virtual int getBaseDamage() = 0;
	//暴击效果 返回值大于0 触发暴击
	virtual int getCrit() = 0;
	//获取吸血 返回值大于0 触发吸血
	virtual int getSuckBlood() = 0;
	//冰冻效果 返回true 代表冰冻
	virtual int getFrozen() = 0;
	//触发概率
	virtual bool isTrigger(int rate) = 0;
public:
	int baseDamage; //基础攻击
	string weaponName; //武器名称
	int critPlus;  //暴击系数
	int critRate;  //暴击率
	int suckPlus;  //吸血系数
	int suckRate;  //吸血率
	int frozenRate;  //冰冻率
};
/**
weaponId,weaponName,weaponAtk,weaponCritPlus,weaponCritRate,weaponSuckPlus,weaponSuckRate,weaponFrozenRate
1,          小刀,       5,      0,              0 ,             0,              0,              0
2,大砍刀,10,2,30,0,0,0
3,屠龙刀,20,2,50,1,30,50 
*/
class Knife:public Weapon{
	public:
		//获取基础伤害
		Knife(){
			File f;
			vector<string> v;
			map<string, map<string, string>> m_weapon;
			f.file_read("./Weapons.csv", v, m_weapon);
			map<string, string> m = m_weapon["1"];

			//cout<<m_weapon["1"]["weaponName"]<<endl;
			baseDamage = atoi(m["weaponAtk"].c_str());//基础攻击
			weaponName =      m["weaponName"]; //武器名称
			critPlus   = atoi(m["weaponCritPlus"].c_str());  //暴击系数
			critRate   = atoi(m["weaponCritRate"].c_str());  //暴击率
			suckPlus   = atoi(m["weaponSuckPlus"].c_str());  //吸血系数
			suckRate   = atoi(m["weaponSuckRate"].c_str());  //吸血率
			frozenRate = atoi(m["weaponFrozenRate"].c_str());  //冰冻率
		}
		int getBaseDamage(){
			return baseDamage;
		}
		//暴击效果 返回值大于0 触发暴击
		int getCrit(){
			if(isTrigger(critRate))
				return critPlus*baseDamage;
			else
				return 0;
		}
		//获取吸血 返回值大于0 触发吸血
		int getSuckBlood(){
			if(isTrigger(suckRate))
				return suckPlus*baseDamage;
			else
				return 0;
		}
		//冰冻效果 返回true 代表冰冻
		int getFrozen(){
			if(isTrigger(frozenRate))
				return true;
			else
				return false;
		}
		//触发概率
		bool isTrigger(int rate){
			int val = rand()%100;
			if(val<rate)
				return true;
			else
				return false;
		}
};

class BigKnife:public Weapon{
	public:
		//获取基础伤害
		BigKnife(){
			File f;
			vector<string> v;
			map<string, map<string, string>> m_weapon;
			f.file_read("./Weapons.csv", v, m_weapon);
			map<string, string> m = m_weapon["2"];

			//cout<<m_weapon["1"]["weaponName"]<<endl;
			baseDamage = atoi(m["weaponAtk"].c_str());//基础攻击
			weaponName =      m["weaponName"]; //武器名称
			critPlus   = atoi(m["weaponCritPlus"].c_str());  //暴击系数
			critRate   = atoi(m["weaponCritRate"].c_str());  //暴击率
			suckPlus   = atoi(m["weaponSuckPlus"].c_str());  //吸血系数
			suckRate   = atoi(m["weaponSuckRate"].c_str());  //吸血率
			frozenRate = atoi(m["weaponFrozenRate"].c_str());  //冰冻率
		}
		int getBaseDamage(){
			return baseDamage;
		}
		//暴击效果 返回值大于0 触发暴击
		int getCrit(){
			if(isTrigger(critRate))
				return critPlus*baseDamage;
			else
				return 0;
		}
		//获取吸血 返回值大于0 触发吸血
		int getSuckBlood(){
			if(isTrigger(suckRate))
				return suckPlus*baseDamage;
			else
				return 0;
		}
		//冰冻效果 返回true 代表冰冻
		int getFrozen(){
			if(isTrigger(frozenRate))
				return true;
			else
				return false;
		}
		//触发概率
		bool isTrigger(int rate){
			int val = rand()%100;
			if(val<rate)
				return true;
			else
				return false;
		}
};

class DragonKnife:public Weapon{
	public:
		//获取基础伤害
		DragonKnife(){
			File f;
			vector<string> v;
			map<string, map<string, string>> m_weapon;
			f.file_read("./Weapons.csv", v, m_weapon);
			map<string, string> m = m_weapon["3"];

			//cout<<m_weapon["1"]["weaponName"]<<endl;
			baseDamage = atoi(m["weaponAtk"].c_str());//基础攻击
			weaponName =      m["weaponName"]; //武器名称
			critPlus   = atoi(m["weaponCritPlus"].c_str());  //暴击系数
			critRate   = atoi(m["weaponCritRate"].c_str());  //暴击率
			suckPlus   = atoi(m["weaponSuckPlus"].c_str());  //吸血系数
			suckRate   = atoi(m["weaponSuckRate"].c_str());  //吸血率
			frozenRate = atoi(m["weaponFrozenRate"].c_str());  //冰冻率
		}
		int getBaseDamage(){
			return baseDamage;
		}
		//暴击效果 返回值大于0 触发暴击
		int getCrit(){
			if(isTrigger(critRate))
				return critPlus*baseDamage;
			else
				return 0;
		}
		//获取吸血 返回值大于0 触发吸血
		int getSuckBlood(){
			if(isTrigger(suckRate))
				return suckPlus*baseDamage;
			else
				return 0;
		}
		//冰冻效果 返回true 代表冰冻
		int getFrozen(){
			if(isTrigger(frozenRate))
				return true;
			else
				return false;
		}
		//触发概率
		bool isTrigger(int rate){
			int val = rand()%100;
			if(val<rate)
				return true;
			else
				return false;
		}
};




#endif