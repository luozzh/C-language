#include <stdio.h>
#include <string.h>
#include "assist.h"
#include "add.h"

static char name[50][20];	//姓名
static char sex[50];		//性别
static char tel[50][12];	//电话
static int count = 0;		//有效联系人的数量


void add(void)
{
	if(50 <= count)
	{
		puts("系统正在升级，请等待......\n");
		return;
	}
	int i = 0;
	while(sex[i]) i++;
	printf("请输入个人信息(姓名，性别（m/w）,电话)\n");
	scanf("%s %c %s",name[i],&sex[i],tel[i]);
	count++;
	msg_show("添加成功！！\n",1.5);
}

void del(void)
{
	char key[20] = {};
	printf("请输入要删除的姓名\n");
	scanf("%s",key);
	for(int i=0;i<50;i++)
	{
		if(sex[i] && 0==strcmp(key,name[i]))
		{
			sex[i] = 0;
			count--;
			msg_show("删除成功！！！\n",1.5);
			return;
		}
	}
	msg_show("未找到信息。\n",1.5);
}


void updata(void)
{
	char key[20] = {};
	printf("请输入要修改的姓名\n");
	scanf("%s",key);
	for(int i=0;i<50;i++)
	{
		if(sex[i] && 0==strcmp(key,name[i]))
		{
			printf("请重新输入信息\n");
			scanf("%s %c %s",name[i],&sex[i],tel[i]);
			msg_show("修改成功！！！\n",1.5);
			return;
		}
	}
	msg_show("未找到信息。\n",1.5);
}

void show(void)
{
	for(int i = 0;i<50;i++)
	{
		if(sex[i])
		{
			printf("%s %s %s\n",name[i],'w'==sex[i]?"女":"男",tel[i]);
		}
	}
	anykey_continue();
}

void find(void)
{
	char key[20] = {};
	printf("请输入需要查找的信息\n");
	scanf("%s",key);
	for(int i=0;i<50;i++)
	{
		if(sex[i] && (strstr(name[i],key)||strstr(tel[i],key)))
		{
			printf("%s %s %s\n",name[i],'w'==sex[i]?"女":"男",tel[i]);
		}
	}
	anykey_continue();
}
