#include "department.h"

Department::Department(const char* name)
{
	strcpy(m_strName,name);
}
Department::~Department(void)
{
	
}
void Department::setId(int id)
{
	m_iId = id;
}
void Department::setName(char* name)
{
	strcpy(m_strName,name);
}
int Department::getId(void)
{
	return m_iId;
}
char* Department::getName(void)
{
	return m_strName;
}
ostream& operator<<(ostream& os,const Department& de)
{
	return os << de.m_iId <<" " << de.m_strName << " " << de.empArr.size();
}
istream& operator>>(istream& is,Department& de)
{
	return is >> de.m_iId >> de.m_strName ;
}
