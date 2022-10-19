#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager.h"
#include "manager_mode.h"

class ManagerModeImpl:public ManagerMode
{
public:
	void load(vector<Manager>& mgr);
	void save(const vector<Manager>& mgr);
};

#endif//MANAGER_MODE_IMPL_H
