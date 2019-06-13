#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
	virtual void voice() = 0;
	virtual ~Animal() = 0;
};

class Cat:public Animal
{
public:
	Cat(){
		cout<<"construct a cat..."<<endl;
	}
	void voice(){
		cout<<"小猫开始哭了，666"<<endl;
	}
	~Animal();
};
Cat::~Animal(){
		cout<<"cat desconstruct..."<<endl;
	}
class Dog:public Animal
{
public:
	Dog(){
		cout<<"construct a dog..."<<endl;
	}
	void voice(){
		cout<<"小狗开始哭了，555"<<endl;
	}
	~Animal();
};
Dog::~Animal(){
		cout<<"dog descontruct..."<<endl;
	}

void LetAnimalCry(Animal &animal)
{
	animal.voice();
}

int main()
{
	Animal *dog = new Dog();
	dog->voice();
	
	Animal *cat = new Cat();
	cat->voice();
	
	delete dog;
	delete cat;
	
	return 0;
}
