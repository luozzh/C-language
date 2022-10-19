#include "service_ctrl_impl.h"
#include "service_mode_impl.h"
#include "department.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpl;
	srcMode->load(deptArr);
}
ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
}
bool ServiceCtrlImpl::addDept(Department& Dept)
{
	for(unsigned int i=0;i<deptArr.size();i++)
	{
		if(!strcmp(deptArr[i].getName(),Dept.getName()))
		{
			return false;
		}
	}
	Dept.setId(get_deptid());
	deptArr.push_back(Dept);
	return true;
}
int ServiceCtrlImpl::delDept(int em_id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(em_id == it->getId())
		{
			deptArr.erase(it);
			return true;
		}
	}
	return false;
}
vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}
bool ServiceCtrlImpl::addEmp(int id,Employee& emp)
{
	for(unsigned int i=0;i<deptArr.size();i++)
	{
		if(deptArr[i].getId() == id)
		{
			emp.setId(get_empid());
			deptArr[i].empArr.push_back(emp);
		}
	}
	
	return true;
}
bool ServiceCtrlImpl::delEmp(int e_id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		vector<Employee>::iterator eit;
		for(eit=it->empArr.begin();eit!=it->empArr.end();eit++)
		{
			if(e_id == eit->getId())
			{
				it->empArr.erase(eit);
				return true;
			}
		}
	}
	return false;
}
bool ServiceCtrlImpl::modEmp(int e_id,Employee& emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		vector<Employee>::iterator eit;
		for(eit=it->empArr.begin();eit!=it->empArr.end();eit++)
		{
			if(e_id == eit->getId())
			{
				it->empArr.erase(eit);
				emp.setId(e_id);
				it->empArr.push_back(emp);
				return true;
			}
		}
	}
	return false;
}
Department* ServiceCtrlImpl::listEmp(int id)
{
	for(unsigned int i=0;i<deptArr.size();i++)
	{
		if(id == deptArr[i].getId())
		{
			return &deptArr[i];
		}
	}
	return NULL;
}
vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	return deptArr;
}
