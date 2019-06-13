//#include<stdio.h>
#ifndef STDIO_H
#define _STDIO_H
	#include<stdio.h>
#endif

//#pragma once
	//#include<stdio.h>

#include<time.h>
#include<stdlib.h>

int main(){
	
	time_t tm = time(NULL);
	
	srand((unsigned int)tm);
	
	int r = rand();
	printf("%d\n",r);
	
	
	
	return 0;
}