#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char name[50][20];	//姓名
static char sex[50];		//性别
static char tel[50][12];	//电话
static int count = 0;		//有效联系人的数量

void msg_show(const char* msg,float sec)
{
//提示信息
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

void anykey_continue(void)
{
	puts("请输入任意键继续....");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

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

int menu(void)
{
	system("clear");
	puts("*****欢迎使用大佬通讯录*****");
	puts("	1.添加联系人");
	puts("	2.删除联系人");
	puts("	3.查找联系人");
	puts("	4.修改联系人");
	puts("	5.显示联系人");
	puts("	6.退出程序");
	puts("****************************");
	printf("*****请选择服务*********** ");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;
}

int main(int argc,const char* argv[])
{
	for(;;)
	{
		//	显示主界面
		switch(menu())
		{
			case '1':add();
			break;
			case '2':del();
			break;
			case '3':find();
			break;
			case '4':updata();
			break;
			case '5':show();
			break;
			case '6':return 0;
//			default:printf("输入有误，请重新输入！！！");
//			break;
		}
	}
}
