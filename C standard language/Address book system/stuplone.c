#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CON 50

typedef	struct Contacts
{
	char name[20];		//姓名
	char sex;		//性别
	char tel[12];		//电话
}Contacts;	
static int count = 0;		//有效联系人的数量

Contacts* con;			//使用堆内存

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
	if(MAX_CON <= count)
	{
		puts("系统正在升级，请等待......\n");
		return;
	}
	int i = 0;
	while(con[i].sex) i++;
	printf("请输入个人信息(姓名，性别（m/w）,电话)\n");
	scanf("%s %c %s",con[i].name,&con[i].sex,con[i].tel);
	count++;
	msg_show("添加成功！！\n",1.5);
}

void del(void)
{
	char key[20] = {};
	printf("请输入要删除的姓名\n");
	scanf("%s",key);
	for(int i=0;i<MAX_CON;i++)
	{
		if(con[i].sex && 0==strcmp(key,con[i].name))
		{
			con[i].sex = 0;
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
	for(int i=0;i<MAX_CON;i++)
	{
		if(con[i].sex && 0==strcmp(key,con[i].name))
		{
			printf("请重新输入信息\n");
			scanf("%s %c %s",con[i].name,&con[i].sex,con[i].tel);
			msg_show("修改成功！！！\n",1.5);
			return;
		}
	}
	msg_show("未找到信息。\n",1.5);
}

void show(void)
{
	for(int i = 0;i<MAX_CON;i++)
	{
		if(con[i].sex)
		{
			printf("%s %s %s\n",con[i].name,'w'==con[i].sex?"女":"男",con[i].tel);
		}
	}
	anykey_continue();
}

void find(void)
{
	char key[20] = {};
	printf("请输入需要查找的信息\n");
	scanf("%s",key);
	for(int i=0;i<MAX_CON;i++)
	{
		if(con[i].sex && (strstr(con[i].name,key)||strstr(con[i].tel,key)))
		{
			printf("%s %s %s\n",con[i].name,'w'==con[i].sex?"女":"男",con[i].tel);
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
	con = calloc(sizeof(Contacts),MAX_CON);

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
