//8*8�Թ�
#include "stack.h"
#define M 8
#define N 8
typedef SqStack mg_path; //����ջ����Ϊmg_path
int mg[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1.0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1},
}; //�趨�Թ�������Χ��1����������
int a, b; //���ڶ�Ӧ��ǰλ�õ���һ�����ڵķ���
Status findpath(int, int, int, int);

int main(void)
{
	if (!findpath(1, 1, M, N)) printf("���Թ�û��ͨ·");
	getchar();
	return 0;
}

Status findpath(int i, int j, int m, int n)
{
	mg_path L;
	bool find; //����ָʾ��û���ҵ���һ������
	InitStact(L);
	Box first = {i,j,-1};
	Box Path[50];
	Push(L, first);
	mg[i][j] = -1;
	while(!Stackempty(L))
	{
		Gettop(L,first); //��L��ջ��Ԫ�طŵ�first����
		if (first.i == m && first.j == n)
		{
			printf("һ���Թ�·�����£�");
			int k = 0;
			while (!Stackempty(L))
			{
				Pop(L, first); //��·����ջ������ŵ�����path����
				Path[k++] = first; 
			}
			while (k >= 1)
			{
				k--;
				printf("\t(%d,%d)", Path[k].i, Path[k].j); //�����ӡ����Ԫ�صõ�·��
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
			(L.top-1)->section = first.section;//�޸ĵ�ǰջ������Ϊ��Ч����
			first.i = a, first.j = b, first.section = -1;
			Push(L, first);
			mg[a][b] = -1;//�����Ի�ͷ
		}
		//��ʱ˵������·�ǲ��Եģ���Ҫpop����ǰջ��Ԫ��
		else {
			Pop(L, first);
			mg[first.i][first.j] = 0;
		}
	}
	Destroy(L);
	return false;

}

