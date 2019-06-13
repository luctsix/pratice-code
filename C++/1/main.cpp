#include "func.cpp"
#include "Rational.h"


int main()
{
    Rational a(1,2);
    Rational b(3,4);
    Rational c, d, e, f;

    c = a + b;
    d = a - b;
    e = a * b;
    f = a / b;

    a.print("a");
    b.print("b");
    c.print("a+b");
    d.print("a-b");
    e.print("a*b");
    f.print("a/b");

    return 0;
}