#include <stdio.h>
#include <stdlib.h>
#include <getch.h>

int main(int argc,const char* argv[])
{
	int a[8][8]={
		{0,0,2,2,2,2,0,0},
		{0,0,2,4,4,2,0,0},
		{0,2,2,0,4,2,2,0},
		{0,2,0,0,3,4,2,0},
		{2,2,0,3,0,0,2,2},
		{2,0,0,2,3,3,0,2},
		{2,0,0,1,0,0,0,2},
		{2,2,2,2,2,2,2,2},
		};
	//记录角色位置
	char man_x = 6,man_y = 3;
	int cont=0,count=0;
	for(;;)
	{
		cont=0;
		//清理屏幕
		system("clear");
		//显示地图
 		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				switch(a[i][j])
				{
					case 0:
					printf("  ");
					break;
					case 1:
					case 5:
					printf("@ ");
					break;
					case 2:
					printf("# ");
					break;
					case 3:
					printf("* ");
					break;
					case 4:
					printf("! ");
					break;
					case 7:
					printf("* ");
					cont++;
					break;
				}

			}
		printf("\n");
		}

		//结束
		if(4==cont)
		{

			printf("通关！！步数为%d。\n",count);
			return 0;
		}
		//获取方向键
		switch(getch())
		{
			case 183://shang
			if(0==a[man_x-1][man_y]||4==a[man_x-1][man_y])
			{
				a[man_x][man_y]-=1;
				a[--man_x][man_y]+=1;
			}
			else if(3==a[man_x-1][man_y]||7==a[man_x-1][man_y])
			{	
				if(0==a[man_x-2][man_y]||4==a[man_x-2][man_y])
				{
				a[man_x][man_y]-=1;
				a[man_x-2][man_y]+=3;
				a[--man_x][man_y]-=2;
				}
			}
			count++;
			break;
			case 184://xia
			if(0==a[man_x+1][man_y]||4==a[man_x+1][man_y])
			{
				a[man_x][man_y]-=1;
				a[++man_x][man_y]+=1;
			}
			else if(3==a[man_x+1][man_y]||(7==a[man_x+1][man_y]&&2!=a[man_x+2][man_y]))
			{
				if(0==a[man_x+2][man_y]||4==a[man_x+2][man_y])
				{
					a[man_x][man_y]-=1;
					a[man_x+2][man_y]+=3;
					a[++man_x][man_y]-=2;
				}
			}
			count++;
			break;
			case 186://zuo
			if(0==a[man_x][man_y-1]||4==a[man_x][man_y-1])
			{
				a[man_x][man_y]-=1;
				a[man_x][--man_y]+=1;
			}
			else if(3==a[man_x][man_y-1]||(7==a[man_x][man_y-1]&&2!=a[man_x][man_y-2]))
			{
				if(0==a[man_x][man_y-2]||4==a[man_x][man_y-2])
				{
					a[man_x][man_y]-=1;
					a[man_x][man_y-2]+=3;
					a[man_x][--man_y]-=2;
				}		
			}
			count++;
			break;
			case 185://you
			if(0==a[man_x][man_y+1]||4==a[man_x][man_y+1])
			{
				a[man_x][man_y]-=1;
				a[man_x][++man_y]+=1;
			}
			else if(3==a[man_x][man_y+1]||(7==a[man_x][man_y+1]&&2!=a[man_x][man_y+2]))
			{
				if(0==a[man_x][man_y+2]||4==a[man_x][man_y+2])
				{
					a[man_x][man_y]-=1;
					a[man_x][man_y+2]+=3;
					a[man_x][++man_y]-=2;
				}
			}
			count++;
			break;
		}
	}
}
