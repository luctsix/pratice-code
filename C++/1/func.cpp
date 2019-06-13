#include "Rational.h"

Rational::Rational(int a, int b){
    _num = a;
    _den = b;
}
int Rational::gcd(int x, int y){            //最大公约数
    int max = x>y?x:y;
    int min = x<y?x:y;

    while(max != min)
    {
        int i = max - min;
        max = min>i?min:i;
        min = min<i?min:i;
    }

    return max;
}

Rational Rational::operator + (const Rational & r)
{
    auto i = gcd(_den, r._den);
    _num = _num*r._den/i + r._num*_den/i;
    _den = _den * r._den / i;
    auto j = gcd(_num, _den);
    _num /= j;
    _den /= j;
    return (_num, _den);
}
Rational Rational::operator - (const Rational & r){
    auto i = gcd(_den, r._den);
    _num = _num*r._den/i - r._num*_den/i;
    _den = _den * r._den / i;
    auto j = gcd(fabs(_num), fabs(_den));
    _num /= j;
    _den /= j;
    return (_num, _den);
}
Rational Rational::operator * (const Rational & r){
    _num *= r._num;
    _den *= r._den;
    auto j = gcd(_num, _den);
    _num /= j;
    _den /= j;
    return (_num, _den);
}
Rational Rational::operator / (const Rational & r){
    _num *= r._den;
    _den *= r._num;
    auto j = gcd(_num, _den);
    _num /= j;
    _den /= j;
    return (_num, _den);
}

void Rational::print(string s){
    cout<<s<<":"<<_num<<"/"<<_den<<endl;
}