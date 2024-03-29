#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "service_view.h"
#include "service_ctrl.h"

class ServiceViewImpl:public ServiceView
{
	ServiceCtrl* srcCtrl;
public:
	ServiceViewImpl(void);
	~ServiceViewImpl(void);
	void menuSrc(void);
	void addDept(void);
	void delDept(void);
	void listDept(void);
	void addEmp(void);
	void delEmp(void);
	void modEmp(void);
	void listEmp(void);
	void listAllEmp(void);
};

#endif//SERVICE_VIEW_IMPL_H
