#include "linklist.h"

typedef struct _dynamic_array{
	void **array;//������Ԫ�صĵ�ַ
	int capacity;//����
	int size;//��ЧԪ�صĸ���
}DY_AR;

// ��ʼ����̬����
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
// ����λ��ɾ��Ԫ��
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
	//����Ԫ�ظ���
	myarray->size--;
	return 0;

}
//����data��ͬɾ��
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
	//��������λ��С��0 ���ߴ���myarray->size,��Ĭ��β��
	if (pos > myarray->size || pos < 0)
		pos = myarray->size;
	//�����������,size����������� �������ӿռ� ����һ��
	if (myarray->size >= myarray->capacity)
	{
		//�����µĿռ� ԭ����2��
		void **tmp = malloc(sizeof(void*) * 2 * myarray->capacity);
		//��ԭ���Ŀռ� �������µĿռ�
		memcpy(tmp, myarray->array, sizeof(void*)*myarray->capacity);
		//�ͷžɵĿռ�
		free(myarray->array);
		//�µĿռ丳ֵ��	myarray->array
		myarray->array = tmp;
		//��������
		myarray->capacity = myarray->capacity * 2;
	}
	// ���� �ƶ�Ԫ��
	for (int i = myarray->size - 1; i >= pos; i--)
	{
		myarray->array[i + 1] = myarray->array[i];
	}
	//����
	myarray->array[pos] = data;
	//����size��ֵ
	myarray->size++;
	return 0;
}
//β��
int InsertByTail_DynamicArray(void *myarray1, void *data)
{
	DY_AR* myarray = (DY_AR*)myarray1;
	int n = myarray->size;
	return InsertByPos_DynamicArray(myarray1, n, data);
}
//ͷ��
int InsertByHeader_DynamicArray(void *myarray, void *data)
{
	return InsertByPos_DynamicArray(myarray, 0, data);
}
//��ȡԪ�صĸ���
int Getsize_DynamicArray(void *myarray1)
{
	DY_AR* myarray = (DY_AR*)myarray1;
	return myarray->size;
}
//��ȡ����
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
