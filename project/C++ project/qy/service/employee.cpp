#include "employee.h"
Employee::Employee(const char* name,char sex,int age,int de_id)
{
	strcpy(m_strName,name);
	m_cSex = sex;
	m_iAge = age;
	de_iId = de_id;
}
void Employee::setId(int id)
{
	m_iId = id;
}
void Employee::setAge(int age)
{
	m_iAge = age;
}
void Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}
void Employee::setSex(char sex)
{
	m_cSex = sex;
}
int Employee::getId(void)
{
	return m_iId;
}
int Employee::getAge(void)
{
	return m_iAge;
}
char* Employee::getName(void)
{
	return m_strName;
}
char Employee::getSex(void)
{
	return m_iAge;
}
ostream& operator<<(ostream& os,const Employee& em)
{
	os << em.m_iId << " " << em.m_strName << " " << em.m_iAge << " " << em.m_cSex << " " << em.de_iId;
}
istream& operator>>(istream& is,Employee& em)
{
	is >> em.m_iId >> em.m_strName>> em.m_iAge >> em.m_cSex >> em.de_iId;
}
