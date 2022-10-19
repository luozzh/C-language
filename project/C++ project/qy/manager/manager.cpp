#include "manager.h"

Manager::Manager(const char* name,const char* pwd)
{
	strcpy(m_strName,name);
	strcpy(m_strPwd,pwd);
}
int Manager::getId(void)const
{
	return m_ild;
}
const char* Manager::getName(void)const
{
	return m_strName;
}
const char* Manager::getPwd(void)const
{
	return m_strPwd;
}
void Manager::setId(int id)
{
	m_ild = id;
}
void Manager::setName(const char* name)
{
	strcpy(m_strName,name);
}
void Manager::setPwd(const char* pwd)
{
	strcpy(m_strPwd,pwd);
}
ostream& operator<<(ostream& os,const Manager& em)
{
	return os << em.m_ild << " " << em.m_strName << " " << em.m_strPwd;
} 
istream& operator>>(istream& is,Manager& em)
{
	return is >> em.m_ild >> em.m_strName >> em.m_strPwd;
}

