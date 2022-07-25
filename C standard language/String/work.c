#include <stdio.h>

size_t strlen1(const char *s)
{
	size_t len = 0;
	while(s[len])len++;
	return len;
}

 char *strcpy1(char *dest, const char *src)
 {
	 size_t len=0;
	 while(src[len])
	{
		dest[len]=src[len];
		len++;
	}
	return dest;
 }

char *strcat1(char *dest, const char *src)
{
	size_t len = 0;
	int i = strlen1(dest);
	while(src[len])
	{
		dest[i]=src[len];
		i++;
		len++;
	}
	return dest;
}

int strcmp1(const char *s1, const char *s2)
{
	int max = strlen1(s1);
	if(max < strlen1(s2))
	{
		max = strlen1(s2);
	}
	for(int i = 0 ;i<max; i++)
	{
		if(s1[i]>s2[i])
		{
			return 1;
		}
		else if(s1[i]==s2[i])
		{
//			printf("s1=%d ",s1[i]);
//			printf("s2=%d ",s2[i]);
			if(i+1==max)
			{
				return 0;
			}
		}
		else
		{
			return -1;
		}
	}
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
