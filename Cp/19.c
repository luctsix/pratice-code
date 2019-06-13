#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int ax[2], ay[2];
	int bx[2], by[2];
	int area = 0;
	
	//先输入左上角坐标，再输入右下角的坐标
	scanf("%d %d %d %d", &ax[0], &ay[0], &ax[1], &ay[1]);
	scanf("%d %d %d %d", &bx[0], &by[0], &by[1], &by[1]);
	
	printf("a1(%d,%d),a2(%d,%d)\n", ax[0], ay[0], ax[1], ay[1]);
	printf("b1(%d,%d),b2(%d,%d)\n", bx[0], by[0], by[0], by[1]);

	/*if(ay[1]>by[0] || ax[0]>bx[1] || bx[0]>ax[1] ||
		by[1]>ay[0])
	{
		printf("这两个矩形没有重叠部分！\n");
	}
	/*if(ax[0]>=bx[0] && ay[0]>=by[0] && ax[1]>= bx[1] &&
			ay[1]>=by[1]){
			area = (ax[1]-ax[0])*(ay[1]-ay[0]);}
	else if(ax[0]<=bx[0] && ay[0]<=by[0] && ax[1]<= bx[1] &&
			ay[1]<=by[1]){
			area = (bx[1]-bx[0])*(by[1]-by[0]);}
	else{
			if(bx[0]>=ax[0] && bx[0]<=ax[1] && by[0]>=ay[1] &&
					by[0]<=ay[0])
				area = (ax[1]-bx[0])*(by[0]-ay[1]);
			else if(bx[0]>=ax[0] && bx[0]<=ax[1] && by[1]>=ay[1] &&
					by[1]<=ay[0])
				area = (ax[1]-bx[0])*(ay[0]-by[1]);
			else if(bx[1]>=ax[0] && bx[1]<=ax[1] && by[1]>=ay[1] &&
					by[1]<=ay[0])
				area = (ay[0]-by[1])*(bx[1]-ax[0]);
			else
				area = (bx[1]-ax[0])*(by[0]-ay[1]);
	}*/
	
	if(ax[0]<= bx[0] && ay[0]<=by[0] && ax[1]<=bx[1] && ay[1]<=by[1])
		area = (ax[1]-bx[0])*(ay[1]-by[0]);
		
		
	printf("重叠面积为：%d", area);
	
	return 0;
}