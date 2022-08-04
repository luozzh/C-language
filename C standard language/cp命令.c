#include <stdio.h>

int main(int argc,const char* argv[])
{
	if(3!=argc)
    {
		printf("User: ./CP src dest\n");
		return 0;
	}

    FILE* src = fopen(argv[1],"r");
    if(NULL == src)
    {
		printf("原文件不存在\n");
	    return 0;
    }

    FILE* dest = fopen(argv[2],"r");
    if(dest)
    {
		printf("目标文件已存在，是否继续(Y\\N)\n");
		char cmd = getchar();
		if('y' != cmd && 'Y' != cmd)
		{
			printf("已停止\n");
	    	return 0;
		}
		fclose(dest);

    }
	dest = fopen(argv[2],"w");
	if(NULL ==dest)
	{
		printf("文件路径权限不足\n");
		return 0;
	}

	char buf[256] = {};
	int ret = 0;
	while(ret = fread(buf,1,256,src))
	{
		fwrite(buf,1,ret,dest);
	}
	fclose(src);
	fclose(dest);
	dest = NULL;
	src = NULL;
}

