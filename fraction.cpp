#include "fraction.h"

fraction::fraction()
{
	numerator = 0;
	denominator = 1;
}


fraction::~fraction()
{

}

fraction::fraction(int num)
{
	numerator = num;
	denominator = 1;
}
fraction::fraction(long num)
{
	numerator = num;
	denominator = 1;
}
fraction::fraction(long long num)
{
	numerator = num;
	denominator = 1;
}

fraction::fraction(float num)
{
	numerator = (integer)num*1e6;
	denominator = 1e6;

}
fraction::fraction(double num)
{
	numerator = num*1e6;
	denominator = 1e6;

}

fraction::fraction(integer num1, integer num2)
{
	numerator = num1;
	denominator = num2;
	simplify();
}
//各种操作
fraction operator+(const fraction&a, const fraction&b)
{
	/*fraction m(a.numerator*b.denominator, a.denominator*b.denominator);
	fraction n(b.numerator*a.denominator, a.denominator*b.denominator);*/
	return fraction(a.numerator*b.denominator+ b.numerator*a.denominator, a.denominator*b.denominator);

}
fraction operator-(const fraction&a, const fraction&b)
{
	return fraction(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
}
fraction operator*(const fraction&a, const fraction&b)
{
	return fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}
fraction operator/(const fraction&a, const fraction&b)
{
	return fraction(a.numerator * b.denominator, a.denominator * b.numerator);
}
fraction operator>(const fraction&a, const fraction&b)
{
	fraction temp(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
	if (temp.numerator*temp.denominator > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
fraction operator<(const fraction&a, const fraction&b)
{
	fraction temp(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
	if (temp.numerator * temp.denominator < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
fraction operator>=(const fraction&a, const fraction&b)
{
	fraction temp(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
	if (temp.numerator * temp.denominator >= (integer)0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
fraction operator<=(const fraction&a, const fraction&b)
{
	fraction temp(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
	if (temp.numerator * temp.denominator <= (integer)0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
fraction operator==(const fraction&a, const fraction&b)
{
	if (a.numerator == b.numerator&&a.denominator == b.denominator)
		return 1;
	else
		return 0;
}
fraction operator!=(const fraction&a, const fraction&b)
{
	if (a.numerator != b.numerator||a.denominator != b.denominator)
		return 1;
	else
		return 0;
}
fraction fraction::operator+()
{
	return *this;
}
fraction fraction::operator-()
{
	numerator = numerator;
	return *this;
}

//强制类型转换
fraction::operator double()
{
	return (double)numerator / (double)denominator;
}
fraction::operator long()
{
	return numerator / denominator;
}
fraction::operator int()
{
	return numerator / denominator;
}
fraction::operator float()
{
	return (float)numerator / (float)denominator;
}
fraction::operator integer()
{
	return numerator / denominator;
}
int fraction::print()
{
	if (denominator == (integer)0)		//分母为0
		printf("∞");
	else if (denominator == (integer)1)		//分母为1
		printf("%lld", numerator);
	else
	{
		if(denominator<(integer)0)		//正负判断
		printf("%lld/%lld", -numerator, -denominator);
	}
		
	return 0;
}



