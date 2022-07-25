#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,const char* argv[])
{
	//走迷宫
	//迷宫
	char arr[10][10]={
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#',' ','#','#','#','#','#',' ',' ','#'},
		{'#','@','#','#','#','#','#','#',' ',' '},
		{'#',' ','#','#','#','#','#','#',' ','#'},
		{'#',' ','#','#','#','#','#','#',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
		{'#',' ','#','#','#','#','#',' ','#','#'},
		{'#',' ','#','#','#','#','#',' ','#','#'},
		{'#',' ',' ',' ',' ','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		};
	//记录角色位置
	char man_x = 2,man_y = 1;
	//开始时间
	time_t start_t=time(NULL);
	for(;;)
	{
		//清理屏幕
		system("clear");
		//显示地图
 		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				printf("%c ",arr[i][j]);
			}
		printf("\n");
		}

		//结束
		if(man_x==2&&man_y==9)
		{

			printf("通关！！时间为%lus。\n",time(NULL)-start_t);
			return 0;
		}
		//获取方向键
		switch(getch())
		{
			case 183://shang
			if(' '==arr[man_x-1][man_y])
			{
				arr[man_x][man_y]=' ';
				arr[--man_x][man_y]='@';
			}
			break;
			case 184://xia
			if(' '==arr[man_x+1][man_y])
			{
				arr[man_x][man_y]=' ';
				arr[++man_x][man_y]='@';
			}
			break;
			case 186://zuo
			if(' '==arr[man_x][man_y-1])
			{
				arr[man_x][man_y]=' ';
				arr[man_x][--man_y]='@';
			}
			break;
			case 185://you
			if(' '==arr[man_x][man_y+1])
			{
				arr[man_x][man_y]=' ';
				arr[man_x][++man_y]='@';
			}
			break;
		}
	}

}
