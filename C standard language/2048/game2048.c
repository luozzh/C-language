#include <stdio.h>
#include <stdbool.h>
#include <getch.h>
#include <stdlib.h>
#include "game2048.h"
#include "tools.h"
#include "direction.h"


int (*cp)[4] = NULL;
int score = 0;

bool move = true;

//初始化数据，加载数据
void init_game(void)
{
	debug("%s\n",__func__);
	//申请堆内存
	cp = malloc(sizeof(cp[0][0])*4*4);
	//初始化数据
	for(int  i = 0; i < 4 ; i++)
	{
		for(int j = 0 ;j < 4; j++)
		{	
			cp[i][j]=0;
		}
	}
	//读取文件，加载数据
	
}

//运行游戏
void start_game(void)
{
	debug("%s\n",__func__);
	for(;;)
	{
		//随机找一个位置生成一个“2”
		rand_two();

		move = false;
		//检查是否还能玩
		if(is_fin())
		{
			printf("finish!! score = %d.\n",score);
			return;
		}
		//显示界面
		show_view();
		//获取方向键并处理
		switch(getch())
		{
			case 183: up(); break;
			case 184: down(); break;
			case 186: left(); break;
			case 185: right(); break;
		}
		
	}

}

//保存数据,释放资源
void end_game(void)
{
	debug("%s\n",__func__);
	free(cp);
	cp = NULL;

}
