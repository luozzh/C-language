#ifndef EMIS_H
#define EMIS_H

#include "./manager/manager_view.h"

class Emis
{
	ManagerView* mgrView;
	static Emis emis;
	Emis(void);
	Emis(const Emis& that){}
public:
	static Emis& getEmis(void);
	~Emis(void);
	void start(void);
};

#endif//EMIS_H
