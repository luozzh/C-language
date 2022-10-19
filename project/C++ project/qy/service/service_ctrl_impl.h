#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include "service_mode.h"

class ServiceCtrlImpl:public ServiceCtrl
{
	ServiceMode* srcMode;
	vector<Department> deptArr;
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	bool addDept(Department& Dept);
	int delDept(int em_id);
	vector<Department>& listDept(void);
	bool addEmp(int id,Employee& emp);
	bool delEmp(int e_id);
	bool modEmp(int e_id,Employee& emp);
	Department* listEmp(int id);
	vector<Department>& listAllEmp(void);
};

#endif//SERVICE_CTRL_IMPL_H
