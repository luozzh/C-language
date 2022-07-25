#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//qipanshuzu
char arr[15][15] ={};
//juese
char player= '@';
//jieseweizhi
int x=0,y=0;
//chushihuaqipan
void chessboard(void)
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			arr[i][j]='*';
		}
		printf("\n");
	}
}
//jiaohuanjuese
char change_player(void)
{
	if(player=='@')
	{
		return '$';
	}
	else
	{
		return '@';
	}
}
//xiaqi
void play(void)
{
	int cnt=0;
	while(cnt==0)
	{
		scanf("%d %d",&x,&y);
		if(x>=0&&x<15&&y>=0&&y<15)
		{
			if(arr[x][y]=='*')
			{
				arr[x][y]=player;
				cnt--;
			}
			else
			{
				printf("该位置有棋子，请重新输入！！！\n");
			}
		}
		else
		{
			printf("坐标不合法，请重新输入：\n");
		}
	}
}
//panduanshengli
bool win(void)
{
	int cnt=0;
	for(int i=x-1;i>=0;i--)//shangxia
	{
		if(arr[i][y]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	for(int i=x+1;i<15;i++)
	{
		if(arr[i][y]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(cnt>=4)
	{
		return true;
	}
	cnt=0;
	for(int i=y-1;i>=0;i--)//zuoyou
	{
		if(arr[x][i]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	for(int i=y+1;i<15;i++)
	{
		if(arr[x][i]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(cnt>=4)
	{
		return true;
	}
	cnt=0;
	for(int i=y-1,j=x-1;i>=0&&j>=0;i--,j--)//zuoshangyouxia
	{
		if(arr[j][i]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	for(int i=y+1,j=x+1;i<15&&j<15;i++,j++)
	{
		if(arr[j][i]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(cnt>=4)
	{
		return true;
	}
	cnt=0;
	for(int i=y-1,j=x+1;i>=0&&j>=0;i--,j++)//zuoxiayoushang
	{
		if(arr[j][i]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	for(int i=y+1,j=x-1;i<15&&j<15;i++,j--)
	{
		if(arr[j][i]==player)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(cnt>=4)
	{
		return true;
	}
	return false;
}
//dayinqipan
void show(void)
{
	system("clear");
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}

int main(int argc,const char* argv[])
{
	chessboard();
	for(;;)
	{
		show();
		printf("请玩家%c输入:\n",player);
		play();
		if(win())
		{
			show();
			printf("玩家%c胜利！！！\n",player);
			return 0;
		}
		player=change_player();
	}
}
