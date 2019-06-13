#include "file.h"
#include "weapon.hpp"
#include "hero.h"
#include "monster.h"


void test01(){
    File f;
    vector<string> v;
    map<string, map<string, string>> m_hero;
    map<string, map<string, string>> m_monstor;
    map<string, map<string, string>> m_weapon;

    f.file_read("./Hero.csv", v, m_hero);

    cout<<m_hero["1"]["heroName"]<<endl;
    v.clear();

    f.file_read("./Monsters.csv", v, m_monstor);

    cout<<m_monstor["1"]["monsterName"]<<endl;
    v.clear();

    f.file_read("./Weapons.csv", v, m_weapon);

    cout<<m_weapon["1"]["weaponName"]<<endl;
}

void Fighting()
{
	File fm;
	map<string, map<string, string>> heroData;  //英雄表容器
	fm.file_read("./Hero.csv", heroData);
	

	cout << "欢迎来到天下第一武道大会！" << endl;
	cout << "请选择您的英雄：" << endl;
	char buf[1024];
	sprintf(buf, "1、%s <%s>", heroData["1"]["heroName"].c_str(), heroData["1"]["heroInfo"].c_str());
	cout << buf << endl;

	sprintf(buf, "2、%s <%s>", heroData["2"]["heroName"].c_str(), heroData["2"]["heroInfo"].c_str());
	cout << buf << endl;

	sprintf(buf, "3、%s <%s>", heroData["3"]["heroName"].c_str(), heroData["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;
	cin >> select;
	getchar();

	Hero hero(select);
	cout << "您选择的英雄是:" << hero.heroName << endl;
	cout << "请为该英雄选择武器:" << endl;

	map<string, map<string, string>> WeaponData;  //英雄表容器
	fm.file_read("./Weapons.csv", WeaponData);

	cout << "1、赤手空拳" << endl;
	sprintf(buf, "2、%s ", WeaponData["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3、%s ", WeaponData["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4、%s ", WeaponData["3"]["weaponName"].c_str());
	cout << buf << endl;

	cin >> select;
	getchar();
	Weapon * weapon = NULL;

	switch (select)
	{
	case 1:
		cout << "no zuo no die why you try！";
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new BigKnife;
		break;
	case 4:
		weapon = new DragonKnife;
		break;
	}


	hero.EquipWeapon(weapon); //装备武器


	int id = rand() % 5 + 1; //1~5
	//随机创建一个怪物
	Monster monster(id);

	int round = 1;
	while (true)
	{
		getchar();
		system("cls");

		cout << "----- 当前第 " << round << " 回合开始 ------" << endl;

		if (hero.heroHp <= 0)
		{
			cout << "英雄" << hero.heroName<< "已挂 ，游戏结束" << endl;
			break;
		}
		
		hero.Attack(&monster);

		if (monster.monsterHp <= 0)
		{
			cout << "怪物" << monster.monsterName << "已挂，顺利通关" << endl;
			break;
		}
		monster.Attack(&hero);

		cout << "英雄" << hero.heroName << "剩余血量：" << hero.heroHp<< endl;
		cout << "怪物" <<monster.monsterName << "剩余血量：" << monster.monsterHp << endl;

		if (hero.heroHp <= 0)
		{
			cout << "英雄" << hero.heroName << "已挂 ，游戏结束" << endl;
			break;
		}

		round++;
	}
}


int main(){

    //cout<<n<<endl;
    //test01();
    Fighting();

    return 0;
}