/*******************
gcc工作流程
预处理	gcc -E homework1.c -o homework1.i
编译	gcc -S homework1.i -o homework1.s
汇编	gcc -c homework1.s -o homework1.o
链接	gcc homework1.o -o homework
********************************/
 #include<stdio.h>
 #include<stdlib.h>
 
 int main()
 {
	 printf("my name is: 练俊祥\n");
	 
	 system("pause");
	 system("Notepad");
	 
	 return 0;
 }