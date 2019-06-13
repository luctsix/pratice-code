 #include<stdio.h>
 #include<conio.h>
 int main()
 {
	 char name;
	 int id;
	 int a[3];
	 
	 int sum , ave;
	 
	 printf("Input\n");
	 scanf("%c", &name);
	 scanf("%d", &id);
	 
	 scanf("%d", &a[0]);
	 //getch();
	 scanf("%d", &a[1]);
	 //getch();
	 scanf("%d", &a[2]);
	 
	 sum = a[0] + a[1] +a[2];
	 ave = sum/3;
	 
	 printf("Output\n\n");
	 printf("Name:%c\n", name);
	 printf("Id:%d\n", id);
	 printf("Total:%d\n",sum);
	 printf("Average:%d\n", ave);
	 
	 
	 return 0;
 }