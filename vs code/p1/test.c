#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char ** p = NULL;

	p      = (char**)malloc(3*sizeof(char*));
	*p     = (char*)malloc(100*sizeof(char));
	*(p+1) = (char*)malloc(100*sizeof(char));
	*(p+2) = (char*)malloc(100*sizeof(char));
	
	for(int i=0; i<3; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}

	free(p);
	p = NULL;
	
	return 0;
}