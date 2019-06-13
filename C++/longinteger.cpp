#include <iostream>
#include <string>

class BigInteger{
public:
	BigInteger(string s){this->s = s;}
	BigInteger(){}
	
	BigInteger operator+(const BigInteger &r);
	BigInteger operator-(const BigInteger &r);
	BigInteger operator*(const BigInteger &r);
	
	void Print(string s);
	
	
private:
	string s;
}
BigInteger BigInteger::operator+(const BigInteger &r){
	BigInteger tmp = ma
	if(*this == '-')
	{
		string *right = this;
		
	}
	else if(*r == '-')
	{
		
	}
	else if(*this=='-' && *r=='-')
	{}
	else
	{}
	string *str = &r;
	int i;
	BigInteger ans;
	int len1 = strlen(this);
	int len2 = strlen(&r);
	while(len1 && len2)
	{
		i = 0;
	}
	
}
BigInteger BigInteger::operator-(const BigInteger &r);
BigInteger BigInteger::operator*(const BigInteger &r);

void BigInteger::Print(string s){
	cout<<s<<endl;
}

void test()
{
	BigInteger a("-1234567890");
	BigInteger b("234567891");
	BigInteger ans1, ans2, ans3, ans4;
	BigInteger c(a), d;
	ans1 = a + b;
	ans2 = a - b;
	ans3 = c - b;
	ans2 = a * b;
	cout<<"a=";		a.Print();
	cout<<"b=";		b.Print();
	cout<<"c=";		c.Print();
	cout<<"d=";		d.Print();
	cout<<"a+b=";	ans1.Print();
	cout<<"a-b=";	ans2.Print();
	cout<<"c-b=";	ans3.Print();
	cout<<"a*b=";	ans4.Print();
}

int main()
{
	test();
	return 0;
}