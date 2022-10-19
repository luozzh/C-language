#include "service_mode_impl.h"

void ServiceModeImpl::load(vector<Department>& dept)
{
	ifstream ifs(DATA_SER_PATH,ios::in|ios::binary);
	if(!ifs)
	{
		return;
	}
	int index = -1;
	while(true)
	{
		int num = 0;
		Department dem;
		ifs >> dem >> num;
		if(!ifs.good())	break;
		dept.push_back(dem);
		index++;
		for(unsigned int i=0;i < num;i++)
		{	
			Employee ee;
			ifs >> ee;
			dept[index].empArr.push_back(ee);
		}
	}
	ifs.close();
}
void ServiceModeImpl::save(vector<Department>& dept)
{
	ofstream ofs(DATA_SER_PATH);
	if(!ofs)
	{
		return;
	}
	for(unsigned int i=0;i<dept.size();i++)
	{
		ofs << dept[i] << endl;
		for(unsigned int j=0;j<dept[i].empArr.size();j++)
		{
			ofs << dept[i].empArr[j] << endl;
		}
	}
	ofs.close();
}

