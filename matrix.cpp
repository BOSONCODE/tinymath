#include "matrix.h"
#include<stdlib.h>
#include<iostream>

matrix::matrix()
{
	pmatrix = (fraction**)malloc(sizeof(fraction*));
	*pmatrix= (fraction*)malloc(sizeof(fraction));
	pmatrix[0][0] = 1;
	w = 1;
	h = 1;
}


matrix::matrix(int width, int height)
{
	pmatrix = (fraction**)malloc(sizeof(fraction*)*height);
	for (int i = 0; i < height; i++)
	{
		pmatrix[i] = (fraction*)malloc(sizeof(fraction)*width);
	}
	w = width;
	h = height;
	//全部设为0
	for (int i = 0; i < h;i++)
	{
		for (int j = 0; j < w;j++)
		{
			pmatrix[i][j] = 0;
		}
	}
	//主对角线设为1
}


matrix::matrix(int width, int height, char * way)
{
	pmatrix = (fraction**)malloc(sizeof(fraction*)*height);
	for (int i = 0; i < height; i++)
	{
		pmatrix[i] = (fraction*)malloc(sizeof(fraction)*width);
	}
	w = width;
	h = height;
	//全部设为0
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			pmatrix[i][j] = 0;
		}
	}
	//主对角线设为1
}

matrix::matrix(const matrix&a)
{
	w = a.w;
	h = a.h;
	pmatrix = (fraction**)malloc(sizeof(fraction*)*h);
	for (int i = 0; i < h; i++)
	{
		pmatrix[i] = (fraction*)malloc(sizeof(fraction)*w);
	}
	//全部复制
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			pmatrix[i][j] = a.pmatrix[i][j];
		}
	}
}

// 赋值构造
matrix matrix::operator =(const matrix& a)
{
	w = a.w;
	h = a.h;
	pmatrix = (fraction**)malloc(sizeof(fraction*)*h);
	for (int i = 0; i < h; i++)
	{
		pmatrix[i] = (fraction*)malloc(sizeof(fraction)*w);
	}
	//全部复制
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			pmatrix[i][j] = a.pmatrix[i][j];
		}
	}
	return *this;
}
matrix::~matrix()
{
	for (int i = 0; i < h; i++)
	{
		free(pmatrix[i]);
	}
	free(pmatrix);
}

//操作符
matrix operator +(const matrix& a, const matrix& b)
{
	matrix temp(a.w,a.h);
	try
	{
		if (a.w == b.w&&a.h == b.h)
		{
			for (int i = 0; i < a.h; i++)
			{
				for (int j = 0; j < a.w; j++)
				{
					temp.pmatrix[i][j] = a.pmatrix[i][j] + b.pmatrix[i][j];
				}
			}
			return temp;
		}
		else
		{
			throw 1;
		}
	}
	catch(int er)
	{
		if (er == 1)
		{
			printf("%s", "相加矩阵不同形\n");
			getchar();
			printf("%s", "按任意键继续\n");
			exit(1);
		}
	
	}
}

matrix operator*(const matrix & a, const matrix & b)
{
	matrix result(a.w, b.h);
	fraction temp ;
	try
	{
		if (a.w == b.w&&a.h == b.h)
		{
			for (int i = 0; i < a.h; i++)
			{
				for (int j = 0; j < a.w; j++)
				{
					for (int k = 0; k < a.h; k++)
					{
						result.pmatrix[i][j] = result.pmatrix[i][j] + a.pmatrix[i][k] + b.pmatrix[k][j];
					}//k
				}//j
			}//i
			return result;
		}
		else
		{
			throw 1;
		}
	}
	catch (int er)
	{
		if (er = 1)
		{
			printf("%s", "相加矩阵不同形\n");
			getchar();
			printf("%s", "按任意键继续\n");
			exit(1);
		}

	}
	return matrix();
}



int matrix::PrintMatrix()const
{
	for (int i = 0; i < h;i++)
	{
		for (int j = 0; j < w;j++)
		{
			std::cout << pmatrix[i][j]<<' ';
		}
		printf("\n");
	}
	return 0;
}

std::ostream & operator<< (std::ostream &os, const matrix &st)
{
	st.PrintMatrix();
	return os;
}

//设置矩阵
int matrix::SetEle(int width, int height, fraction num)
{
	if (width > w || height > h)return 1;
	pmatrix[height][width] = num;
	return 0;
}


// 输入矩阵
matrix matrix::input()
{
	int i, j;
	double temp;
	int num1, num2;
	printf("请输入一个矩阵(以0为一行结束)：\n");

	return matrix();
}
