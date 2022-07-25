
#include "direction.h"
#include "game2048.h"

void up(void)
{
	for(int j=0;j<4;j++)
	{	
		int end = 0;
		for(int i=1 ;i<4;i++)
		{
			for(int k=i;k>end;k--)
			{
				if(cp[k][j]&&cp[k-1][j]==0)
				{
					
					cp[k-1][j] = cp[k][j];
					cp[k][j] = 0;
					move = true;
					
				}
				else if(cp[k][j]&&cp[k-1][j]==cp[k][j])
				{
					cp[k-1][j]*=2;
					cp[k][j]=0;
					end=k;
					move = true;
				}
			}
		}

	}
}
void down(void)
{
	for(int j=0;j<4;j++)
	{	
		int end = 3;
		for(int i=2 ;i>=0;i--)
		{
			for(int k=i;k<end;k++)
			{
				if(cp[k][j]&&cp[k+1][j]==0)
				{
					
					cp[k+1][j] = cp[k][j];
					cp[k][j] = 0;
					move = true;
					
				}
				else if(cp[k][j]&&cp[k+1][j]==cp[k][j])
				{
					cp[k+1][j]*=2;
					cp[k][j]=0;
					end=k;
					move = true;
				}
			}
		}

	}
}
void left(void)
{
	for(int i=0;i<4;i++)
	{	
		int end = 0;
		for(int j=1 ;j<4;j++)
		{
			for(int k=j;k>end;k--)
			{
				if(cp[i][k]&&cp[i][k-1]==0)
				{
					
					cp[i][k-1] = cp[i][k];
					cp[i][k] = 0;
					move = true;
					
				}
				else if(cp[i][k]&&cp[i][k-1]==cp[i][k])
				{
					cp[i][k-1]*=2;
					cp[i][k]=0;
					end=k;
					move = true;
				}
			}
		}

	}
}
void right(void)
{
	for(int i=0;i<4;i++)
	{	
		int end = 3;
		for(int j=2 ;j>=0;j--)
		{
			for(int k=j;k<end;k++)
			{
				if(cp[i][k]&&cp[i][k+1]==0)
				{
					
					cp[i][k+1] = cp[i][k];
					cp[i][k] = 0;
					move = true;
					
				}
				else if(cp[i][k]&&cp[i][k+1]==cp[i][k])
				{
					cp[i][k+1]*=2;
					cp[i][k]=0;
					end=k;
					move = true;
				}
			}
		}

	}
}
