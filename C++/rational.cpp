#include <iostream>
#include <string>

using namespace std;

class Rational{
public:
	Rational(){
		this->num = 0;
		this->den = 0;
	}
	Rational(int num, int den){
		this->num = num;
		this->den = den;
	}
	Rational operator+ (const Rational &r);
	Rational operator- (const Rational &r);
	Rational operator* (const Rational &r);
	Rational operator/ (const Rational &r);
	void Print(string s);
	int get_num(){return this->num;}
	int get_den(){return this->den;}
private:
	int num;	//·Ö×Ó
	int den;	//·ÖÄ¸
	int gcd(int x, int y);
};
int Rational::gcd(int x, int y){
	int max = x>y?x:y;
	int min = x<y?x:y;
	while(max != min)
	{
		int m = max - min;
		max = m>min?m:min;
		min = m<min?m:min;
	}
	return max;
}
Rational Rational::operator+(const Rational &r){
	Rational *c = (Rational*)malloc(sizeof(Rational));
	int g = gcd(this->den, r.den);
	c->num = this->num*r.den/g + r.num*this->den/g;
	c->den = this->den*r.den/g;
	g = gcd(c->num, c->den);
	c->num = c->num/g;
	c->den = c->den/g;
	return *c;
}
Rational Rational::operator-(const Rational &r){
	Rational *c = (Rational*)malloc(sizeof(Rational));
	int g = gcd(this->den, r.den);
	//cout<<" a- :"<<this->num<<"/"<<this->den<<endl;
	c->num = this->num*r.den/g - r.num*this->den/g;
	c->den = this->den*r.den/g;
	//cout<<" a- :"<<this->num<<"/"<<this->den<<endl;
	g = gcd(abs(c->num), abs(c->den));
	c->num = c->num/g;
	c->den = c->den/g;
	return *c;
}
Rational Rational::operator*(const Rational &r){
	Rational *c = (Rational*)malloc(sizeof(Rational));
	c->num = this->num * r.num;
	c->den = this->den * r.den;
	int g = gcd(abs(c->num), abs(c->den));
	c->num = c->num/g;
	c->den = c->den/g;
	return *c;
}
Rational Rational::operator/(const Rational &r){
	Rational *c = (Rational*)malloc(sizeof(Rational));
	c->num = this->num * r.den;
	c->den = this->den * r.num;
	//cout<<" / :"<<this->num<<"/"<<this->den<<endl;
	int g = gcd(abs( c->num), abs(c->den));
	c->num = c->num/g;
	c->den = c->den/g;
	return *c;
}
void Rational::Print(string s){
	cout<<s<<": "<<this->num<<"/"<<this->den<<endl;
}

int main()
{
	Rational a(1, 2);
	Rational b(3, 4);
	Rational c, d, e, f;
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;
	a.Print("a");
	
	b.Print("b");
	c.Print("a+b");
	d.Print("a-b");
	e.Print("a*b");
	//cout<<a.get_num()<<"  "<<a.get_den()<<endl;
	//cout<<b.get_num()<<"  "<<b.get_den()<<endl;
	f.Print("a/b");
	
	
	
	return 0;
}