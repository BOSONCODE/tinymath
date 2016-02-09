#pragma once
#ifndef FRACTION
#define FRACTION
//#include "calculator.h"
#include<iostream>
#include"integer.h"
class fraction
{
public:
	//构造函数
	fraction();
	fraction(int num);
	fraction(long num);
	fraction(long long num);
	fraction(integer num1, integer num2);
	fraction(float num);
	fraction(double num);
	//析构函数
	~fraction();
	//操作符
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
	//转换类型
	operator double();
	operator long();
	operator int();
	operator float();
	operator integer();
	//输出cout与输入cin
	friend std::ostream & operator<< (std::ostream &os, fraction &st)
    {
		if (st.denominator == (integer)0)		//分母为0
			printf("∞");
		else if (st.denominator == (integer)1)		//分母为1	//printf("%lld", st.numerator);
			st.numerator.Print();
		else
		{
			if (st.denominator < (integer)0)		//正负判断		//printf("%lld/%lld", -st.numerator, -st.denominator);
			{
				st.numerator.Print();
				printf("/");
				st.denominator.Print();
			}
		}
       return os;
	}

	//化简
	int simplify()
	{
		//求最大公约数
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
	//输出
	int print();
private:
	integer numerator;		//分子
	integer denominator;		//分母

	
};


#endif
