#ifndef GAME2048_H
#define GAME2048_H


#include <stdbool.h>

extern int(*cp)[4];
extern int score;
extern bool move;
//初始化数据，加载数据
void init_game(void);

//运行游戏
void start_game(void);

//释放资源,保存数据
void end_game(void);

#endif//GAME2048_H
