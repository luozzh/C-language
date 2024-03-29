#ifndef SERVICE_VIEW_H
#define SERVICE_VIEW_H

class ServiceView
{
public:
	virtual ~ServiceView(void) {}
	virtual void menuSrc(void) = 0;
	virtual void addDept(void) = 0;
	virtual void delDept(void) = 0;
	virtual void listDept(void) = 0;
	virtual void addEmp(void) = 0;
	virtual void delEmp(void) = 0;
	virtual void modEmp(void) = 0;
	virtual void listEmp(void) = 0;
	virtual void listAllEmp(void) = 0;
};

#endif//SERVICE_VIEW_H
