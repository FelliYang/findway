//8*8迷宫
#include "stack.h"
#define M 8
#define N 8
typedef SqStack mg_path; //将该栈命名为mg_path
int mg[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1.0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1},
}; //设定迷宫，最外围设1方程序运算
int a, b; //用于对应当前位置的下一个相邻的方向
Status findpath(int, int, int, int);

int main(void)
{
	if (!findpath(1, 1, M, N)) printf("该迷宫没有通路");
	getchar();
	return 0;
}

Status findpath(int i, int j, int m, int n)
{
	mg_path L;
	bool find; //用于指示有没有找到下一个格子
	InitStact(L);
	Box first = {i,j,-1};
	Box Path[50];
	Push(L, first);
	mg[i][j] = -1;
	while(!Stackempty(L))
	{
		Gettop(L,first); //将L的栈顶元素放到first里面
		if (first.i == m && first.j == n)
		{
			printf("一条迷宫路径如下：");
			int k = 0;
			while (!Stackempty(L))
			{
				Pop(L, first); //将路径出栈并倒叙放到数组path里面
				Path[k++] = first; 
			}
			while (k >= 1)
			{
				k--;
				printf("\t(%d,%d)", Path[k].i, Path[k].j); //倒叙打印数组元素得到路径
				if ((k + 2) % 5 == 0)
					printf("\n");
			}
			Destroy(L);
			return true;
		}

		find = false;
		while (first.section < 3 && !find)
		{
			first.section++;
			switch (first.section)
			{
				case 0:a = first.i-1, b = first.j ; break;
				case 1:a = first.i , b = first.j + 1; break;
				case 2:a = first.i + 1, b = first.j; break;
				case 3:a = first.i, b = first.j - 1; break;
			}
			if (mg[a][b] == 0)find = true;
		}
		if (find)
		{
			(L.top-1)->section = first.section;//修改当前栈顶方向为有效方向
			first.i = a, first.j = b, first.section = -1;
			Push(L, first);
			mg[a][b] = -1;//不可以回头
		}
		//这时说明这条路是不对的，需要pop出当前栈顶元素
		else {
			Pop(L, first);
			mg[first.i][first.j] = 0;
		}
	}
	Destroy(L);
	return false;

}

