#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int i = 0;
    FILE *file = fopen("test.txt", "r+");
    char str[20];
    char src[20];
    fseek(file, 0, SEEK_SET);
    while(i<1)
    {
        
        scanf("%s", str);
        if(strcmp(str, "exit")==0)
        {
            break;
        }
        sprintf(src, "%s\t\t\t\n", str);
        printf("src = %s\n",src);
       
        fputs(src,  file);  
        i++;
    }
    fclose(file);
    //getchar();

    return 0;
}