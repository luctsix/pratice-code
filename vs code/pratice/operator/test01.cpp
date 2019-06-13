#include <iostream>
 using namespace std;

class person{
    friend person operator+(const person &p1, const person &p2);
    friend person operator-(const person &p1, const person &p2);
    friend person operator*(const person &p1, const person &p2);
    friend person operator/(const person &p1, const person &p2);
    friend ostream& operator<<( ostream &cout, person &p);
    friend istream& operator>>(istream &cin, person &p);
    public:
        person(){}
        person(int a){
            this->a = a;
            //this->b = b;
        }

        person operator+(const person &p){
            person tmp;
            tmp.a = this->a + p.a;
            //tmp.b = this->b + p.b;
            return tmp;
        }
        person operator-(const person &p){
            person tmp;
            tmp.a = this->a - p.a;
            //tmp.b = this->b + p.b;
            return tmp;
        }
        person operator*(const person &p){
            person tmp;
            tmp.a = this->a * p.a;
            //tmp.b = this->b + p.b;
            return tmp;
        }
        person operator/(const person &p){
            person tmp;
            tmp.a = this->a / p.a;
            //tmp.b = this->b + p.b;
            return tmp;
        }
        person operator%(const person &p){
            person tmp;
            tmp.a = this->a % p.a;
            //tmp.b = this->b + p.b;
            return tmp;
        }
        person& operator++(){
            this->a = this->a+1;
            return *this;
        }
        person& operator++(int){
            person *tmp = new person(*this);
            this->a = this->a + 1;
            return *tmp;
        }   
        bool operator==(const person &p){
            if(this->a == p.a){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator!=(const person &p){
            if(this->a != p.a){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator>=(const person &p){
            if(this->a >= p.a){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator<=(const person &p){
            if(this->a <= p.a){
                return true;
            }
            else{
                return false;
            }
        }
        
        void Print(){
            //cout<<"a = "<<a<<"  b = "<<b<<endl;
            cout<<"a = "<<a<<endl;
        }
    private:
        int a;
        //int b;
};
ostream& operator<<( ostream &cout,  person &p){
    cout<<p.a;
    return cout;
}
istream& operator>>(istream &cin, person &p){
    cin>>p.a;
    return cin;
}
class Smartpointer{         //智能指针
public:
    Smartpointer(person *p){
        sp = p;
    }

    person* operator->(){
        return sp;
    }
    person& operator*(){
        return *sp;
    }
    ~Smartpointer(){
        delete sp;
    }
    person *sp;
};

#if 0
    person operator+(const person &p1, const person &p2){
        person tmp;
        tmp.a = p1.a + p2.a;
        //tmp.b = p1.b + p2.b;
        return tmp;
    }
    person operator-(const person &p1, const person &p2){
        person tmp;
        tmp.a = p1.a - p2.a;
        //tmp.b = p1.b + p2.b;
        return tmp;
    }
    person operator*(const person &p1, const person &p2){
        person tmp;
        tmp.a = p1.a * p2.a;
        //tmp.b = p1.b + p2.b;
        return tmp;
    }
    person operator/(const person &p1, const person &p2){
        person tmp;
        tmp.a = p1.a / p2.a;
        //tmp.b = p1.b + p2.b;
        return tmp;
    }
#endif
 

void test01(){
    person a(20);
    //a++;
    cout << a++ << endl;
    person b(5);
    cout<<++b<<endl;
    person c = a + b;
    person d = a - b;
    person e = a * b;
    person f = a / b;

    c.Print();
    d.Print();
    e.Print();
    f.Print();
}
void test02(){
    person *p = new person(10);
    Smartpointer sp(p);

    sp->Print();
    (*sp).Print();
}
 int main(){

     test02();

     return 0;
 }