#include "service_view_impl.h"
#include "service_ctrl_impl.h"

ServiceViewImpl::ServiceViewImpl(void)
{
	srcCtrl = new ServiceCtrlImpl;
}
ServiceViewImpl::~ServiceViewImpl(void)
{
	delete srcCtrl;
}
void ServiceViewImpl::menuSrc(void)
{
	while(true)
	{
		system("clear");
		cout << "*****业务子系统*******" << endl;
		cout << "\t1.添加部门" << endl;
		cout << "\t2.删除部门" << endl;
		cout << "\t3.展示部门" << endl;
		cout << "\t4.添加员工" << endl;
		cout << "\t5.删除员工" << endl;
		cout << "\t6.修改员工" << endl;
		cout << "\t7.展示员工" << endl;
		cout << "\t8.展示全部员工" << endl;
		cout << "\t9.退出子系统" << endl;
		
		switch(get_cmd('1','9'))
		{
			case '1': addDept();	break;
			case '2': delDept();	break;
			case '3': listDept(); 	break;
			case '4': addEmp();		break;
			case '5': delEmp();		break;
			case '6': modEmp();		break;
			case '7': listEmp(); 	break;
			case '8': listAllEmp();	break;
			case '9': return;
		}
	}
}
void ServiceViewImpl::addDept(void)
{
	char name[20] = {};
	cout << "请输入要添加的部门：" ;
	get_str(name,sizeof(name));
	Department dept(name);
	if(srcCtrl->addDept(dept))
	{
		cout << "添加部门成功" << endl;
		sleep(1);
		return;
	}
	cout << "用户名重复，添加部门失败" << endl;
	sleep(1);
}
void ServiceViewImpl::delDept(void)
{
	int id = 0;
	cout << "请输入要删除的部门ID：" ;
	cin >> id;
	if(srcCtrl->delDept(id))
	{
		cout << "删除部门成功" << endl;
		sleep(1);
		return;
	}
	cout << "ID有误，删除部门失败" << endl;
	sleep(1);
}
void ServiceViewImpl::listDept(void)
{
	vector<Department>& deptArr = srcCtrl->listDept();
	for(unsigned int i=0;i<deptArr.size();i++)
	{
		cout << deptArr[i] << endl;
	}
	anykey_continue();
}
void ServiceViewImpl::addEmp(void)
{
	char name[20] = {};
	char sex;
	int id,age;
	cout << "请输入新员工姓名：";
	get_str(name,sizeof(name));
	cout << "请输入性别:";
	cin >> sex;
	cout << "请输入年龄:";
	cin >> age;
	cout << "请输入部门:";
	cin >> id;
	Employee emp(name,sex,age,id);
	if(srcCtrl->addEmp(id,emp))
	{
		cout << "添加员工成功" << endl;
		sleep(1);
		return;
	}
	cout << "部门不存在或者用户名重复，添加员工失败" << endl;
	sleep(1);
}
void ServiceViewImpl::delEmp(void)
{
	int id = 0;
	cout << "请输入要删除的员工ID：" ;
	cin >> id;
	if(srcCtrl->delEmp(id))
	{
		cout << "删除员工成功" << endl;
		sleep(1);
		return;
	}
	cout << "ID有误，删除员工失败" << endl;
	sleep(1);
}
void ServiceViewImpl::modEmp(void)
{
	char name[20] = {};
	char sex;
	int d_id,e_id,age;
	cout << "请输入员工ID:";
	cin >> e_id;
	cout << "请输入员工姓名:";
	get_str(name,sizeof(name));
	cout << "请输入性别:";
	cin >> sex;
	cout << "请输入年龄:";
	cin >> age;
	cout << "请输入部门:";
	cin >> d_id;
	
	Employee emp(name,sex,age,d_id);
	if(srcCtrl->modEmp(e_id,emp))
	{
		cout << "修改员工成功!" << endl;
		sleep(1);
		return;
	}
	cout << "ID有误，删除员工失败" << endl;
	sleep(1);
}
void ServiceViewImpl::listEmp(void)
{
	int id= 0;
	cout << "请输入部门的ID号:";
	cin >> id;
	Department* deptArr = srcCtrl->listEmp(id);
	for(unsigned int i=0;i < deptArr->empArr.size();i++)
	{
		cout << deptArr->empArr[i] << endl;
	}
	anykey_continue();
}
void ServiceViewImpl::listAllEmp(void)
{
	vector<Department>& deptArr = srcCtrl->listDept();
	for(unsigned int i=0;i<deptArr.size();i++)
	{
		cout << deptArr[i] << endl;
		Department* dept = srcCtrl->listEmp(deptArr[i].getId());
		for(unsigned int j=0;j<dept->empArr.size();j++)
		{
			cout << dept->empArr[j] << endl;
		}
	}
	anykey_continue();
}
