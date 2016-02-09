#pragma once
#ifndef MATRIX
#define MATRIX
#include"fraction.h"
class matrix 
{
public:
	//����
	matrix();
	matrix(int width, int height);
	matrix(int width, int height, char * way);
	//����
	~matrix();
	//���ƹ���
	matrix(const matrix & a);
	//��ֵ����
	matrix operator =(const matrix& a);
	//������
	friend matrix operator +(const matrix& a, const matrix& b);
	friend matrix operator *(const matrix& a, const matrix& b);
	//���
	int PrintMatrix()const;
	friend std::ostream & operator<< (std::ostream &os, const matrix &st);
	//��ֵ
	//���þ���
	int SetEle(int width, int height, fraction num);
	// �������
	matrix input();
private:
	fraction ** pmatrix;
	int w;
	int h;

};

#endif

