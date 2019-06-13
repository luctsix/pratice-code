#ifndef __MYARRAY_H_
#define __MYARRAY_H_

class MyArray{
public:
    MyArray();
    explicit MyArray(int capacity);
    MyArray(const MyArray &r);

    void Insert(int pos, int val);//按位置插入
    int getData(int pos);//获取pos位置的数据
    int setData(int pos, int val);
    void Pushback(int val);//尾插
    int getCapacity();
    int getSize();
    void Print();
    void deleteData_pos(int pos);
    void deleteData_val(int val);
    void sort();

    ~MyArray();
private:
    int capacity;
    int size;
    int *data;
};


#endif