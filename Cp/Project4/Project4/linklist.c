#include "linklist.h"

typedef struct _dynamic_array{
	void **array;//数组首元素的地址
	int capacity;//容量
	int size;//有效元素的个数
}DY_AR;

// 初始化动态数组
int Init_DynamicArray(void **myarray1, int n)
{
	DY_AR *myarray = malloc(sizeof(DY_AR));
	if (myarray == NULL)
		return -1;

	//(*myarray)->array
	(myarray)->array = malloc(sizeof(void *)*n);
	if ((myarray)->array == NULL)
		return -1;
	(myarray)->capacity = n;
	(myarray)->size = 0;
	*myarray1 = (void*)myarray;
	return 0;
}
// 根据位置删除元素
int DelByPos_DynamicArray(void *myarray1, int pos)
{
	DY_AR *myarray = (DY_AR*)myarray1;

	if (myarray == NULL)
		return -1;
	if (pos < 0 || pos >= myarray->size)
		return -1;
	for (int i = pos; i < myarray->size - 1; i++)
	{
		myarray->array[i] = myarray->array[i + 1];
	}
	//更新元素个数
	myarray->size--;
	return 0;

}
//根据data相同删除
int DelByData_DynamicArray(void *myarray1, void *data, int(*MyCompare)(void*d1, void*d2))
{
	DY_AR* myarray = (DY_AR*)myarray1;
	if (myarray == NULL || data == NULL)
		return -1;
	for (int i = 0; i< myarray->size; i++)
	{
		if (MyCompare(myarray->array[i], data))
		{
			DelByPos_DynamicArray(myarray, i);
			return 0;
		}
	}

	return -1;

}
int InsertByPos_DynamicArray(void *myarray1, int pos, void *data)
{
	DY_AR* myarray = (DY_AR*)myarray1;

	if (myarray == NULL || data == NULL)
		return -1;
	//如果插入的位置小于0 或者大于myarray->size,则默认尾插
	if (pos > myarray->size || pos < 0)
		pos = myarray->size;
	//如果容量不够,size的数量和相等 则考虑增加空间 增加一倍
	if (myarray->size >= myarray->capacity)
	{
		//申请新的空间 原来的2倍
		void **tmp = malloc(sizeof(void*) * 2 * myarray->capacity);
		//将原来的空间 拷贝到新的空间
		memcpy(tmp, myarray->array, sizeof(void*)*myarray->capacity);
		//释放旧的空间
		free(myarray->array);
		//新的空间赋值给	myarray->array
		myarray->array = tmp;
		//更新容量
		myarray->capacity = myarray->capacity * 2;
	}
	// 插入 移动元素
	for (int i = myarray->size - 1; i >= pos; i--)
	{
		myarray->array[i + 1] = myarray->array[i];
	}
	//插入
	myarray->array[pos] = data;
	//更新size的值
	myarray->size++;
	return 0;
}
//尾插
int InsertByTail_DynamicArray(void *myarray1, void *data)
{
	DY_AR* myarray = (DY_AR*)myarray1;
	int n = myarray->size;
	return InsertByPos_DynamicArray(myarray1, n, data);
}
//头插
int InsertByHeader_DynamicArray(void *myarray, void *data)
{
	return InsertByPos_DynamicArray(myarray, 0, data);
}
//获取元素的个数
int Getsize_DynamicArray(void *myarray1)
{
	DY_AR* myarray = (DY_AR*)myarray1;
	return myarray->size;
}
//获取容量
int GetCapacity_DynamicArray(void *myarray1)
{
	DY_AR* myarray = (DY_AR*)myarray1;
	return myarray->capacity;
}

void Print_DynamicArray(void *array1, void MyPrint(void *arg))
{
	DY_AR* array = (DY_AR*)array1;
	for (int i = 0; i < array->size; i++)
	{
		MyPrint(array->array[i]);

	}
	printf("___________________________________________\n");
}


void Destroy_DynamicArray(void *array1)
{
	DY_AR* array = (DY_AR*)array1;

	free(array->array);
	free(array);

}
