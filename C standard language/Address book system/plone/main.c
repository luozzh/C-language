#include "add.h"
#include "assist.h"

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
