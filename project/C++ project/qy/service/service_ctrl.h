#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include "department.h"

class ServiceCtrl
{
public:
	virtual ~ServiceCtrl(void) {}
	virtual bool addDept(Department& Dept) = 0;
	virtual int delDept(int em_id) = 0;
	virtual vector<Department>& listDept(void) = 0;
	virtual	bool addEmp(int e_id,Employee& emp) = 0;
	virtual	bool delEmp(int e_id) = 0;
	virtual bool modEmp(int e_id,Employee& emp) = 0;
	virtual	Department* listEmp(int id) = 0;
	virtual vector<Department>& listAllEmp(void) = 0;
};

#endif//SERVICE_CTRL_H
