#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdafx.h"
#include <stdarg.h>
#if 0
int add(int a, int b)
{
	return a + b;
}
#endif

int add(int a, ...)
{
	int sum = a;
	va_list ap; // ���Կ�����һ��ָ��
	va_start(ap, a); // �õ��׵�ַ

	while (1)
	{
		int arg = va_arg(ap, int); // ��ap�ĵ�ǰλ�õõ�����������apָ�������ƶ�
		if (arg == 0)
			break;
		sum += arg;
	}

	va_end(ap); // �ͷ�

	return sum;
}

void __xLog(const char* filename, int line, const char* fmt, ...)
{
	char buf[4096];
	va_list ap;
	va_start(ap, fmt);
	sprintf(buf, fmt, ap);
	va_end(ap);

	printf("[%s, %d] %s", filename, line, buf);
}

#define xLog(fmt, ...) __xLog(__FILE__, __LINE__, fmt, ##__VA_ARGS__)

int main()
{
	// ��0����������ǣ���������ڼ�����н��ڱ�
	int ret = add(10, 20, 30, 40, 50, 0);
	printf("%d\n", ret);

	xLog("%d\n", ret);
	xLog("hello world\n");
}


