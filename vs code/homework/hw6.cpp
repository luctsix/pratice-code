#include<iostream>
#include<string>

using namespace std;

#define pi 3.14
class Point{
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
private:
    int x;
    int y;
};

class Circle:public Point{
public:
    Circle(Point p, int r):Point(p){
        this->r = r;
    }
    Circle(int x, int y, int r):Point(x, y){
        this->r = r;
    }
    double getArea(){
        return pi*r*r;
    }
    double getPerimeter(){
        return 2*pi*r;
    }
    void Print(){
        cout<<"the circle's area: "<<getArea()<<" Perimeter: "<<getPerimeter()<<endl;
    }
private:
    int r;
};
class Cylinder:public Circle{
public:
    Cylinder(Circle c, int h):Circle(c){
        this->h = h;
    }
    double getArea_c(){
        return (h*getPerimeter()+2*getArea());
    }
    double getVolume(){
        return h*getArea();
    }
    void Print(){
        cout<<"cylinder: "<<"Perimeter: "<<getVolume()<<" Area: "<<getArea_c()<<endl;
    }
private:
    int h;
};
int main(){
    Point p(0, 0);

    Circle c(p, 10);
    Circle c2(1, 0, 2);
    c2.Print();
    //c.Print();

    Cylinder cy(c, 2);
    cy.Print();


    return 0;
}