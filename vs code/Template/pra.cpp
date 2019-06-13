#include <iostream>
#include <vector>
#include <string>

using namespace std;

//template<class T>
//template<typename T>

#if 0
    template<typename T>//用class和typename一样
    void Myswap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }
    void test01(){
        int a = 10, b = 20;
        Myswap(a, b);   //函数模板可以自动推导参数的类型
        cout<<"a = "<<a<<" b = "<<b<<endl;
        char c = 'a';
        char d = 'b';
        Myswap<char>(c, d); //也可以显示的指定类型
        cout<<"c = "<<c<<" d = "<<d<<endl;
    }
#endif
#if 0
    template<typename T>
    void PrintArr(T arr[], int len){
        for(int i=0; i<len;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    template<typename T>
    void Mysort(T arr[], int len){
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    T tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
    }
    void test02(){
        int arr_int[] = {2,5,4,1,3};
        char arr_char[] = {'c', 'a', 'r', 'f', 'b'};
        Mysort(arr_int, sizeof(arr_int)/sizeof(*arr_int));
        cout<<"arr_int: ";
        PrintArr(arr_int, sizeof(arr_int)/sizeof(*arr_int));
        cout<<endl<<"arr_char: ";
        Mysort(arr_char, sizeof(arr_char)/sizeof(*arr_char));
        PrintArr(arr_char, sizeof(arr_char)/sizeof(*arr_char));
        
        cout<<endl;
    }
#endif
#if 0
    template<class T>
    T Myadd(T a, T b){
        cout<<"T myadd(T T)"<<endl;
        return a+b;
    }
    template<class T>
    T Myadd(T a, T b, T c){     //函数模板重载
        cout<<"T myadd(T T T)"<<endl;
        return a+b+c;
    }
    int Myadd(int a, int b){
        cout<<"int myadd(int, int)"<<endl;
        return a+b;
    }
    void test03(){
        int a = 10, b = 20;
        char c = 'a', d = 'b';
        cout<<Myadd(a, b)<<endl;    //优先匹配普通函数
        cout<<Myadd<>(a, b)<<endl;  //
        cout<<Myadd(c, d)<<endl;
    }
#endif
#if 0
    template<class NameType, class AgeType>
    class Person{
        public:
            Person(NameType name, AgeType age){
                this->name = name;
                this->age = age;
            }
            NameType getName(){return this->name;}
            void Print(){
                cout<<"name: "<<this->name<<endl;
                cout<<"age: "<<this->age<<endl;
            }
        private:
            NameType name;
            AgeType  age;
    };
    void DoThing(Person<string,int>&p){
        cout<<p.getName()<<"去扫地"<<endl;
    }
    void test04(){
        //Person p1("李四"， 20);//err,类模板不能进行自动类型推导
        Person<string, int>p1("李四", 20);
        p1.Print();
        DoThing(p1);
        Person<char, char>p2('a', 'b');
        p2.Print();
    }
#endif

template<class T>
class Myclass{
    T count;
public:
    Myclass(T a){this->count = a;}
};
class Subclass:public Myclass<int>{
public:
    Subclass(int a):Myclass(a){}
};



int main()
{
    //test01();
    //test02();
    //test03();
    //test04();

    return 0;
}
