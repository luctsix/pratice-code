/********************************
輸入說明 ：
輸入為一行長度在512個字母內的字串，用中序表示法表達的算式。
中間有一個空白。
--------------------------------
輸出說明 ：
輸出後序表示的運算式。
中間有一個空白。
--------------------------------
Sample Input
9 + 8 * 7 - 6
Sample Output:
9 8 7 * + 6 -
***************************************************/
#include<stdio.h>
#include<string.h>

int main()
{
	char num[20] = {0};
	char op[20] = {0};
	char str[20] = {0};
	int i = 0, j = 0, k = 0;;
	
	gets(str);
	printf("%s\n", str);
	
	//while(str[i]!='\0')
	{
		if(str[i] >'0' && str[i]<='9')
		{
			printf("%d ", str[i]);
		}
		
		
		
		
		
	}
	
	
	
	return 0;
}