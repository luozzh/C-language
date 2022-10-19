#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

#include "department.h"

class ServiceMode
{
public:
	virtual void load(vector<Department>& dept) = 0;
	virtual void save(vector<Department>& dept) = 0;
};

#endif//SERVICE_MODE_H
