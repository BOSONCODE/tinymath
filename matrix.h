#pragma once
#ifndef MATRIX
#define MATRIX
#include"fraction.h"
class matrix 
{
public:
	//构造
	matrix();
	matrix(int width, int height);
	matrix(int width, int height, char * way);
	//析构
	~matrix();
	//复制构造
	matrix(const matrix & a);
	//赋值构造
	matrix operator =(const matrix& a);
	//操作符
	friend matrix operator +(const matrix& a, const matrix& b);
	friend matrix operator *(const matrix& a, const matrix& b);
	//输出
	int PrintMatrix()const;
	friend std::ostream & operator<< (std::ostream &os, const matrix &st);
	//赋值
	//设置矩阵
	int SetEle(int width, int height, fraction num);
	// 输入矩阵
	matrix input();
private:
	fraction ** pmatrix;
	int w;
	int h;

};

#endif

