#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char name[50][20] = {};
char sex[50][2] = {};
char tel[50][12] = {};
int cnt = 0;

void add(void)
{
	printf("请输入个人信息(姓名，性别（m/w）,电话)\n");
//	scanf("%s %s %s",name[cnt],sex[cnt],tel[cnt]);
	while(1)
	{
		scanf("%s",name[cnt]);
		scanf("%s",sex[cnt]);
		scanf("%s",tel[cnt]);
		if(0==strcmp("w",sex[cnt])||0==strcmp("m",sex[cnt]))
		{
			printf("添加成功！！\n");
			cnt++;
			break;
		}
		else
		{
			printf("请重新输入！！\n");
		}
	}
}

void del(void)
{
	int n = 0;
	char str[20] ={};
	printf("请输入要删除的姓名\n");
	scanf("%s",str);
	for(int i = 0 ;i < cnt; i++)
	{
		if(0==strcmp(str,name[i]))
		{
			char str[20] = {};
			strcpy(str,name[i]);
			strcpy(name[i],name[cnt-1]);
			strcpy(str,sex[i]);
			strcpy(sex[i],sex[cnt-1]);
			strcpy(str,tel[i]);
			strcpy(tel[i],tel[cnt-1]);
			n++;
			cnt--;
			printf("删除成功！！\n");
		}
	}
	if(n==0)
	{
		printf("未找到%s信息\n",str);
	}
}

void updata(void)
{
	int n = 0;
	char str[20] ={};
	printf("请输入要修改的姓名\n");
	scanf("%s",str);
	for(int i = 0 ;i < cnt; i++)
	{
		if(0==strcmp(str,name[i]))
		{
			printf("请输入要修改的信息\n");
			scanf("%s",name[i]);
			scanf("%s",sex[i]);
			scanf("%s",tel[i]);
			n++;
			printf("修改成功！！\n");
		}
	}
	if(n==0)
	{
		printf("未找到%s信息\n",str);
	}
}

void show(void)
{
	for(int i = 0;i<cnt;i++)
	{
		printf("%s ",name[i]);
		if(0==strcmp("w",sex[i]))
		{
			printf("女 ");
		}
		else
		{
			printf("男 ");
		}
		printf("%s\n",tel[i]);
	}
}

void find(void)
{
	int n=0;
	char s[256] = {};
	printf("请输入需要查找的信息\n");
	scanf("%s",s);
	for(int i = 0 ;i<cnt;i++)
	{
		if(NULL != strstr(name[i],s) || NULL != strstr(tel[i],s))
		{
			printf("%s ",name[i]);
			if(0==strcmp("w",sex[i]))
			{
				printf("女 ");
			}
			else
			{
				printf("男 ");
			}
			printf("%s\n",tel[i]);
			n++;
		}
	}
	if(n==0)
	{
		printf("未找到%s信息\n",s);
	}
}

int main(int argc,const char* argv[])
{
	for(;;)
	{
//		system("clear");
		int n = 0;
		printf("请选择服务\n");
		printf("1.添加联系人\n");
		printf("2.删除联系人\n");
		printf("3.查找联系人\n");
		printf("4.修改联系人\n");
		printf("5.显示联系人\n");
		printf("0.退出程序\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:add();
			break;
			case 2:del();
			break;
			case 3:find();
			break;
			case 4:updata();
			break;
			case 5:show();
			break;
			case 0:return 0;
			break;
			default:printf("输入有误，请重新输入！！！");
			break;
		}
	}
}
