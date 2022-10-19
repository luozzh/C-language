#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <unistd.h>
using namespace std;

#define DATA_ID_PATH "./data/id.dat"
#define DATA_MGR_PATH "./data/manager.dat"
#define DATA_SER_PATH "./data/service.dat"

//从键盘获取字符串
char* get_str(char* str,size_t len);
//从键盘输入密码
char* get_pass(char* pass,size_t len,bool is_show = false);
int get_cmd(char start,char end);
void anykey_continue(void);

//初始化id
void init_id(void);
//生成唯一的id
int get_mgrid(void);
int get_deptid(void);
int get_empid(void);


#endif//TOOLS_H
