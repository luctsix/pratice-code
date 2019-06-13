#include "MyArray.h"
#include "MyArray.cpp"

int main(){
    MyArray *myarray = new MyArray;
    myarray->Insert(0, 1);
    myarray->Insert(0, 2);
    myarray->Insert(0, 3);
    myarray->Insert(0, 4);
    myarray->Insert(0, 5);

    myarray->Print();
    //myarray->Pushback(0);
    myarray->sort();
    myarray->Print();
    cout<<myarray->getData(3)<<endl;

    myarray->deleteData_pos(1);
    myarray->deleteData_val(4);
    myarray->Print();
    myarray->deleteData_val(10);

    cout<<"size:"<<myarray->getSize()<<endl;
    cout<<"capacity:"<<myarray->getCapacity()<<endl;

    delete myarray;
    return 0;
}
/*
  MyArray();
    explicit MyArray(int capacity);

    void setData(int pos, int val);//按位置插入
    int getData(int pos);//获取pos位置的数据
    void Pushback(int val);//尾插
    int getCapacity();
    int getSize();
    void deleteData_pos(int pos);
    void deleteData_val(int val);
*/