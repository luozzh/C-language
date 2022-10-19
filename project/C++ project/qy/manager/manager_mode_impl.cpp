#include "manager_mode_impl.h"

void ManagerModeImpl::load(vector<Manager>& mgr)
{
	ifstream ifs(DATA_MGR_PATH,ios::in|ios::binary);
	if(!ifs)
	{
		return;
	}
	while(true)
	{
		Manager man;
		ifs.read((char*)&man,sizeof(man));
		if(!ifs.good())	break;
		mgr.push_back(man);
	}
	ifs.close();
}
void ManagerModeImpl::save(const vector<Manager>& mgr)
{
	ofstream ofs(DATA_MGR_PATH,ios::out|ios::binary);
	if(!ofs)
	{
		return;
	}
	for(unsigned int i=0;i<mgr.size();i++)
	{
		ofs.write((const char*)&mgr[i],sizeof(mgr[i]));
	}
	ofs.close();
}
