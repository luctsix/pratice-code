#pragma once 

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Rational{
public:
    Rational(int num = 0,int den = 1);    //constructor
    ~Rational(){};          //descontructor

    Rational operator + (const Rational & r);
    Rational operator - (const Rational & r);
    Rational operator * (const Rational & r);
    Rational operator / (const Rational & r);
    void print(string s);
private:
    int _num;
    int _den;
    int gcd(int x, int y);
};