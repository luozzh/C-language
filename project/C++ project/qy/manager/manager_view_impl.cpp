#include "manager_view_impl.h"
#include "manager_ctrl_impl.h"
#include "../service/service_view_impl.h"

ManagerViewImpl::ManagerViewImpl(void)
{
	init_id();
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}
ManagerViewImpl::~ManagerViewImpl(void)
{
	delete mgrCtrl;
	delete srcView;
}

void ManagerViewImpl::loginManager(void)
{
	char id[20] = {},pwd[20] = {};
	cout << "请输入超级用户ID:";
	get_str(id,sizeof(id));
	cout << "请输入超级用户密码:";
	get_pass(pwd,sizeof(pwd));
	
	if(!strcmp(id,"admin") && !strcmp(pwd,"123456"))
	{
		menuMgr();
		return;
	}
	cout << "用户名或者密码错误，请重新输入！" << endl;
	sleep(1);
}
void ManagerViewImpl::loginService(void)
{
	char id[10] = {};
	char pwd[20] = {};
	cout << "请输入业务管理员ID:";
	get_str(id,10);
	cout << "请输入业务管理员密码:";
	get_pass(pwd,sizeof(pwd));
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(unsigned int i=0;i<mgrArr.size();i++)
	{
		if(atoi(id) == mgrArr[i].getId() && 0 == strcmp(pwd,mgrArr[i].getPwd()))
		{
			srcView->menuSrc();
			return;
		}
	}
	cout << "用户名或者密码错误，请重新输入！" << endl;
	sleep(1);
}
void ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		system("clear");
		cout << "*****超级管理员界面*****" << endl;
		cout << "\t1.添加管理员" << endl;
		cout << "\t2.删除管理员" << endl;
		cout << "\t3.展示管理员" << endl;
		cout << "\t4.退出子系统" << endl;
		
		switch(get_cmd('1','4'))
		{
			case '1': addMgr();	break;
			case '2': delMgr();	break;
			case '3': listMgr(); break;
			case '4': return;
		}
	}
}
void ManagerViewImpl::addMgr(void)
{
	char name[20] = {},pwd[20] = {},pwd2[20] = {};
	cout << "请输入新管理员姓名：";
	get_str(name,sizeof(name));
	cout << "请输入新管理员密码：";
	get_pass(pwd,sizeof(pwd));
	cout << "请再次输入密码：";
	get_pass(pwd2,sizeof(pwd2));
	if(strcmp(pwd,pwd2))
	{
		cout << "两次密码不同" << endl;
		sleep(1);
		return;
	}
	
	Manager mgr(name,pwd);
	if(mgrCtrl->addMgr(mgr))
	{
		cout << "添加管理员成功" << endl;
		sleep(1);
		return;
	}
	cout << "用户名重复，添加管理员失败" << endl;
	sleep(1);
}
void ManagerViewImpl::delMgr(void)
{
	int id = 0;
	cout << "请输入要删除的ID：" ;
	cin >> id;
	if(mgrCtrl->delMgr(id))
	{
		cout << "删除管理员成功" << endl;
		sleep(1);
		return;
	}
	cout << "ID有误，删除管理员失败" << endl;
	sleep(1);
}
void ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(unsigned int i=0;i<mgrArr.size();i++)
	{
		cout << mgrArr[i] << endl;
	}
	anykey_continue();
}
