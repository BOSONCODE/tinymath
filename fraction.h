#pragma once
#ifndef FRACTION
#define FRACTION
//#include "calculator.h"
#include<iostream>
#include"integer.h"
class fraction
{
public:
	//���캯��
	fraction();
	fraction(int num);
	fraction(long num);
	fraction(long long num);
	fraction(integer num1, integer num2);
	fraction(float num);
	fraction(double num);
	//��������
	~fraction();
	//������
	friend fraction operator+(const fraction&a,const fraction&b);
	friend fraction operator-(const fraction&a, const fraction&b);
	friend fraction operator*(const fraction&a, const fraction&b);
	friend fraction operator/(const fraction&a, const fraction&b);
	friend fraction operator>(const fraction&a, const fraction&b);
	friend fraction operator<(const fraction&a, const fraction&b);
	friend fraction operator>=(const fraction&a, const fraction&b);
	friend fraction operator<=(const fraction&a, const fraction&b);
	friend fraction operator==(const fraction&a, const fraction&b);
	friend fraction operator!=(const fraction&a, const fraction&b);
	fraction operator+();
	fraction operator-();
	//ת������
	operator double();
	operator long();
	operator int();
	operator float();
	operator integer();
	//���cout������cin
	friend std::ostream & operator<< (std::ostream &os, fraction &st)
    {
		if (st.denominator == (integer)0)		//��ĸΪ0
			printf("��");
		else if (st.denominator == (integer)1)		//��ĸΪ1	//printf("%lld", st.numerator);
			st.numerator.Print();
		else
		{
			if (st.denominator < (integer)0)		//�����ж�		//printf("%lld/%lld", -st.numerator, -st.denominator);
			{
				st.numerator.Print();
				printf("/");
				st.denominator.Print();
			}
		}
       return os;
	}

	//����
	int simplify()
	{
		//�����Լ��
		integer a = numerator;
		integer b = denominator;
		integer temp;

		if (a < b)
		{
			temp = a;
			a = b;
			b = temp;
		}

		while (b>(integer)0)
		{
			temp=a%b;
			a = b;
			b = temp;
		}
		numerator = numerator/a ;
		denominator = denominator/a;
		return 0;
	}
	//���
	int print();
private:
	integer numerator;		//����
	integer denominator;		//��ĸ

	
};


#endif
