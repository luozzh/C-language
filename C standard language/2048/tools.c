#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "tools.h"
#include "game2048.h"

static bool is_full(void)
{
	int* num = (int*)cp;
	for(int i= 0; i < 16;i++)
	{
		if(0==num[i])
		{
			return false;
		}
	}
	return true;
}

//随机找一个位置生成一个“2”
void rand_two(void)
{
	if(is_full())
	{
		debug("没有位置了！！！\n");
		return;
	}
	for(;move;)
	{
		srand(time(NULL));
		int x = rand()%4;
		int y = rand()%4;
		if(0==cp[x][y])
		{
			cp[x][y]=2;
			return;
		}
		
	}
}

//显示界面
void show_view(void)
{
	system("clear");
	for(int  i = 0; i < 4 ; i++)
	{
		printf("---------------------\n");
		for(int j = 0 ;j < 4; j++)
		{	
			if(cp[i][j])
			{
				printf("|%4d",cp[i][j]);
			}
			else
			{
				printf("|    ");
			}

		}
		printf("|\n");	
		
	}
	printf("---------------------\n");
}
//是否结束
bool is_fin(void)
{	
	if(!is_full()) return false;
	for(int  i = 0; i < 4 ; i++)
	{
		for(int j = 0 ;j < 3; j++)
		{
			cp[i][j] = cp[i+1][j];
			return false;
		}
	}

	for(int  i = 0; i < 4 ; i++)
	{
		for(int j = 0 ;j < 3; j++)
		{
			cp[i][j] = cp[i][j+1];
			return true;
		}
	}

	return false;
}









