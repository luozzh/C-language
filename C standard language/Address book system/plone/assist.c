#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getch.h>
#include "assist.h"

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
