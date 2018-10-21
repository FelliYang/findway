#include<stdio.h>
#include<stdlib.h>
#define Status int //Status表示当前函数进行的状态
#define OK 1
#define OVERFLOW 0
#define ERROR -1
#define INIT_SIZE 20
#define ADD_SIZE 10 //如果栈满了可以扩大栈的大小

//使用的具体数据类型
typedef struct {
	int i;
	int j;
	int section;
}Box;

# define SElemType Box
typedef struct {
	SElemType * top; //指向栈顶
	SElemType * base;
	int size;//栈的大小
}SqStack;

//定义栈的接口
Status InitStact(SqStack &L)
{
	//构建空栈
	L.base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
	if (!L.base) exit(OVERFLOW);
	L.top = L.base;
	L.size = INIT_SIZE;
	return OK;
}

Status Gettop(SqStack L, Box &e)
{
	if (L.top == L.base) return ERROR;
	e = *(L.top - 1);
	return OK;
}

Status Push(SqStack&L, Box e)
{
	if (L.top - L.base >= L.size)//栈满了就添加空间
	{
		L.base = (Box *)realloc(L.base, (L.size + ADD_SIZE) * sizeof(Box));
		if (!L.base) exit(OVERFLOW);
		L.top = L.base + L.size;
		L.size = L.size + ADD_SIZE;
	}
	*L.top++ = e;
	return OK;

}
Status Pop(SqStack &L, Box &e)
{
	if (L.top == L.base) return ERROR;
	e = *--L.top;
	return OK;
}
Status Destroy(SqStack &L)
{
	free(L.base);
	L.base = L.top = NULL;
	return OK;
}
Status Stackempty(SqStack L)
{
	if (L.top > L.base) return 0;
	else return 1;
}
