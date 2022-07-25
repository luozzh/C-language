#include <stdio.h>
#include <assert.h>

size_t strlen1(const char *s)
{
	assert(NULL != s);
	const char* str = s;
	while(*str)str++;
	return str - s;
}

 char *strcpy1(char *dest, const char *src)
 {
	assert(NULL != dest && NULL != src);
	char* str = dest;
	while(*str++ = *src++); 
	return dest;
 }

char *strcat1(char *dest, const char *src)
{
	assert(NULL != dest && NULL != src);
	char* str = dest;
	while(*str) str++;
	while(*str++ = *src++);
	return dest;
}

int strcmp1(const char *s1, const char *s2)
{
	assert(NULL != s1 && NULL != s2);
	while(*s1 == *s2 && *s1) s1++,s2++;
	return *s1 - *s2;
	/*
	if(*s1 > *s2)	return 1;
	else if(*s1 < *s2)	return -1;
	else return 0;
	*/
}

int main(int argc,const char* argv[])
{
	char str[256] = {};
	printf("请输入str：\n");
	scanf("%s",str);
	printf("str:%s\n",str);
	printf("strlen:%d\n",strlen1(str));
	char str1[256] = "222";
	printf("strcpy:%s\n",strcpy1(str1,str));
	char str2[256] = "aaaa";
	printf("strcat:%s\n",strcat1(str2,str));
	char str3[256] = {};
	printf("请输入要比较的str：\n");
	scanf("%s",str3);
	printf("%hhd\n",strcmp1(str,str3));
}
