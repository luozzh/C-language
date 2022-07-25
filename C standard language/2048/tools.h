#ifndef TOOL_H
#define TOOL_H

#include <stdio.h>
#include <stdbool.h>

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...)
 #endif

//随机找一个位置生成一个“2”
void rand_two(void);
//显示界面
void show_view(void);
//是否结束
bool is_fin(void);

#endif//TOOL_H
