#include<stdio.h>
#include<stdlib.h>

void print_word(char **words, int n)
{
	int i;
	if(!words)
	{
		printf("ERROR!\n");
		return ;
	}
	for(i=0; i<n; i++)
	{
		printf("%s  ", *words);
		words++;
	}
	printf("\n");
}

//Ã°ÅÝÅÅÐò
void sort(char **p, int n)
{
	int i , j;
	char *temp;
	//print_word(p, n);
	for(i=0; i<n; i++)
	{
		//	printf("testing1...\n");
		for(j=0;j<n-i-1;j++)
		{
			//printf("testing2...\n");
			//printf("*p[j]=%s,*p[j+1]=%s\n",p[j], p[j+1] );
			if(strcmp(p[j],p[j+1]) == 1 ) 
			{
				//printf("testing3...\n");
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
}



int main()
{
	char *words[] = {"city", "student", "tree", "bee"};
	int n = sizeof(words)/sizeof(*words);
	
	print_word(words, n);
	sort(words, n);
	print_word(words, n);
	
	
	return 0;
}