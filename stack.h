#include<stdio.h>
#include<stdlib.h>
#define Status int //Status��ʾ��ǰ�������е�״̬
#define OK 1
#define OVERFLOW 0
#define ERROR -1
#define INIT_SIZE 20
#define ADD_SIZE 10 //���ջ���˿�������ջ�Ĵ�С

//ʹ�õľ�����������
typedef struct {
	int i;
	int j;
	int section;
}Box;

# define SElemType Box
typedef struct {
	SElemType * top; //ָ��ջ��
	SElemType * base;
	int size;//ջ�Ĵ�С
}SqStack;

//����ջ�Ľӿ�
Status InitStact(SqStack &L)
{
	//������ջ
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
	if (L.top - L.base >= L.size)//ջ���˾���ӿռ�
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
