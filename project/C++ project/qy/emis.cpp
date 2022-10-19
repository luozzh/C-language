#include "emis.h"
#include "./manager/manager_view_impl.h"

Emis Emis::emis;

Emis::Emis(void)
{
	mgrView = new ManagerViewImpl;
}
Emis& Emis::getEmis(void)
{
	 return emis;
}
Emis::~Emis(void)
{
	delete mgrView;
}
void Emis::start(void)
{
	for(;;)
	{
		system("clear");
		cout << "*****“不腻”烘焙员工信息管理系统*****" << endl;
		cout << "\t1.登录超级管理子系统"<< endl;
		cout << "\t2.登录业务管理子系统"<< endl;
		cout << "\t3.退出"<< endl;
		switch(get_cmd('1','3'))
		{
			case '1': mgrView->loginManager();break;
			case '2': mgrView->loginService();break;
			case '3': return;
		}
	}
}
