#include<cstdlib>
#include<string>
#include<iostream>
#include "integer.h"
//构造函数
integer::integer()
{
	//分配内存
	num = (char *)malloc(sizeof(char)*sizeof(int));
	if (num==NULL)
	{
		printf("构造失败\n");
	}
	elen = 0;
	llen = sizeof(int);
	pn = 0;
}
integer::integer(int numtemp)
{
	int i = 0;
	//分配内存
	num = (char *)malloc(sizeof(char)*sizeof(int)*2);
	if (num == NULL)
	{
		printf("构造失败\n");
	}
	while (numtemp != 0)
	{
		num[i] = numtemp%10;
		numtemp = numtemp / 10;
		i++;
	}
	elen = i;
	llen = sizeof(int)+sizeof(int);
	(num >= 0) ? pn = 0: pn = 1;
}
/*integer::integer(int num,int len)//注意len是十进制位数
{
	
}*/
integer::integer(long numtemp)
{
	int i = 0;
	//分配内存
	num = (char *)malloc(sizeof(char)*(sizeof(long) + sizeof(int)));
	if (num == NULL)
	{
		printf("构造失败\n");
	}
	while (numtemp != 0)
	{
		num[i] = numtemp % 10;
		numtemp = numtemp / 10;
		i++;
	}
	elen = i;
	llen = sizeof(long) + sizeof(int);
	(num >= 0) ? pn = 0 : pn = 1;
}
integer::integer(long long numtemp)
{
	int i = 0;
	//分配内存
	num = (char *)malloc(sizeof(char)*(sizeof(long long) + sizeof(int)));
	if (num == NULL)
	{
		printf("构造失败\n");
	}
	while (numtemp != 0)
	{
		num[i] = numtemp % 10;
		numtemp = numtemp / 10;
		i++;
	}
	elen = i;
	llen = sizeof(long long) + sizeof(int);
	(num >= 0) ? pn = 0 : pn = 1;
}
//析构函数
integer::~integer()
{
	free(num);
}
//复制构造函数
integer::integer(const integer&a)
{
	char *temp;
	if (llen > a.elen)
	{
		elen = a.elen;
		llen = a.llen;
		pn = a.pn;
		for (int i = 0; i < elen;i++)
		{
			num[i] = a.num[i];
		}
	}
	else
	{
		temp = (char *)realloc(num,a.elen*2);
		if (temp == NULL)
		{
			printf("复制失败\n");
		}
		else
		{
			num = temp;
		}
		elen = a.elen;
		llen = a.elen*2;
		pn = a.pn;
		for (int i = 0; i < elen; i++)
		{
			num[i] = a.num[i];
		}
	}
}
//重载操作符
integer integer::operator =(const integer &a)
{
	char *temp;
	if (llen > a.elen)
	{
		elen = a.elen;
		llen = a.llen;
		pn = a.pn;
		for (int i = 0; i < elen; i++)
		{
			num[i] = a.num[i];
		}
	}
	else
	{
		temp = (char *)realloc(num, a.elen * 2);
		if (temp == NULL)
		{
			printf("复制失败\n");
		}
		else
		{
			num = temp;
		}
		elen = a.elen;
		llen = a.elen * 2;
		pn = a.pn;
		for (int i = 0; i < elen; i++)
		{
			num[i] = a.num[i];
		}
	}
}
integer integer::operator +()const//正
{
	return *this;
}
integer integer::operator -()const//负
{
	integer temp(*this);
	temp.pn = -temp.pn;
	return temp;
}

integer integer::fabs(const integer &numtemp)
{
	integer temp = numtemp;
	temp.pn = 0;
	return temp;
}

integer integer::plus(const integer & a, const integer & b)		//确保两边是正的
{
	int i=0;
	int temp=0;
	int maxflag;
	long long resultlen;
	integer result;

	//判断有效数据长度
	if (a.elen>b.elen)
	{
		maxflag = 1;
	}
	else
	{
		maxflag = 0;
	}
	//计算结果的大小
	resultlen = ((maxflag) ? a.elen : b.elen) * 2;
	//分配result大小
	result.ReSize(resultlen);
	//计算前半部分
	for (i = 0; i < ((!maxflag) ? a.elen : b.elen);i++)
	{
		temp += a.num[i] + b.num[i];
		if (temp>=10)
		{
			result.num[i] = temp - 10;
			temp = 1;		//进位
		}
		else
		{
			result.num[i] = temp;
			temp = 0;		//进位
		}
	}
	//后半部分
	for (i = ((!maxflag) ? a.elen : b.elen) + 1; i < ((maxflag) ? a.elen : b.elen);i++)
	{
		temp += ((maxflag) ? a.num[i] : b.num[i]);
		if (temp >= 10)
		{
			result.num[i] = temp - 10;
			temp = 1;		//进位
		}
		else
		{
			result.num[i] = temp;
			temp = 0;		//进位
		}
	}
	if (temp==0)
	{
		//设定长度
		result.pn = 0;
		result.elen = ((maxflag) ? a.elen : b.elen);
	}
	else if (temp==1)
	{
		//设定长度
		result.pn = 0;
		result.elen = ((maxflag) ? a.elen : b.elen)+1;
	}
	else
	{
		printf("未知错误\n");
	}

	return result;
}

integer integer::min(const integer & a, const integer & b)		//要确保a>b且确保两边是正的
{
	int i = 0;
	int temp = 0;
	int maxflag;
	long long resultlen;
	integer result;
	//相等
	if (a==b)
	{
		return 0;
	}
	//计算结果的大小
	resultlen = a.elen * 2;
	//分配result大小
	result.ReSize(resultlen);
	//计算前半部分
	for (i = 0; i < b.elen; i++)
	{
		temp += a.num[i] - b.num[i];
		if (temp < 0)
		{
			result.num[i] = temp + 10;
			temp = -1;		//借位
		}
		else
		{
			result.num[i] = temp;
			temp = 0;		//借位
		}
	}
	//后半部分
	for (i = b.elen + 1; i < a.elen ; i++)
	{
		temp += a.num[i];
		if (temp < 0)
		{
			result.num[i] = temp + 10;
			temp = -1;		//借位
		}
		else
		{
			result.num[i] = temp;
			temp = 0;		//借位
		}
	}
	//计算长度从后向前遍历
	for (i = a.elen; i > 0;i++)
	{
		if (result.num[i]!=0)
		{
			//设定长度
			result.pn = 0;
			result.elen = a.elen-i;
			break;
		}
	}
	return result;
}

integer integer::mul(const integer & a, const integer & b)
{
	return integer();
}

integer integer::div(const integer & a, const integer & b)
{
	return integer();
}

 integer operator +(const integer &a,const integer &b)
 {
	 if (a.pn==0&&b.pn==0)
	 {
		 return integer::plus(a, b);
	 }
	 else if (a.pn == 1 && b.pn == 0)
	 {
		 if (-a>b)		//二者绝对值进行比较
		 {
			 return -integer::min(-a, b);
		 }
		 else
		 {
			 return integer::min(b, -a);
		 }
	 }
	 else if (a.pn == 0 && b.pn == 1)
	 {
		 if (a>-b)		//二者绝对值进行比较
		 {
			 return integer::min(a, -b);
		 }
		 else
		 {
			 return -integer::min(-b, a);
		 }
	 }
	 else if (a.pn == 1 && b.pn == 1)
	 {
		 return -integer::plus(a,b);
	 }
	 else
	 {
		 printf_s("发生意外错误\n");
	 }
 }
 integer operator -(const integer &a,const integer &b)
 {
	 if (a.pn == 0 && b.pn == 0)
	 {
		 if (a>b)		//二者绝对值进行比较
		 {
			 return integer::min(a, b);
		 }
		 else
		 {
			 return integer::min(b, a);
		 }
	 }
	 else if (a.pn == 1 && b.pn == 0)
	 {
			 return -integer::plus(a, b);
	 }
	 else if (a.pn == 0 && b.pn == 1)
	 {
			 return integer::plus(a, b);
	 }
	 else if (a.pn == 1 && b.pn == 1)
	 {
		 if (-a>-b)		//二者绝对值进行比较
		 {
			 return -integer::min(a, b);
		 }
		 else
		 {
			 return integer::min(b, a);
		 }
	 }
	 else
	 {
		 printf_s("发生意外错误\n");
	 }
 }
 integer operator *(const integer &a,const integer &b)
 {
	 integer result(0);
	 integer sum(0);
	 integer temp=0;
	 char add=0;
	 int i, j;
	 //分配空间
	 result.ReSize((a.elen + b.elen) * 2);
	 sum.ReSize((a.elen + b.elen) * 2);
	 //计算乘法
	 for (i = 0; i < a.elen;i++)
	 {
		 for (j = 0; j < b.elen;j++)
		 {
			 temp.num[j] = a.num[i]*b.num[j]+add;
			 if (temp.num[j]>=10)
			 {
				 add = temp.num[j] / 10;
				 temp.num[j] %= 10;
			 }
			 else
			 {
				 add = 0;
			 }
		 }
		 //设置长度
		 if (add != 0)
		 {
			 temp.num[j] = add;
			 temp.elen = j+1;
		 }
		 else
		 {
			 temp.elen = j;
		 }
		 //累加
		 for (int m = 0; m < i; m++)
		 {
			 temp.MulTen();
		 }
		 sum = sum + temp;
	 }
	 return sum;
 }
 integer operator /(const integer &a,const integer &b)
 {
	 return ;
 }
 bool operator >(const integer &a,const integer &b)
 {
	 if (a.elen>b.elen)
	 {
		 return 1;
	 }
	 else if (a.elen<b.elen)
	 {
		 return 0;
	 }
	 else
	 {
		 for (int i = a.elen; i > 0;i--)
		 {
			 if (a.num[i]>b.num[i])
			 {
				 return 1;
			 }
			 else if (a.num[i]<b.num[i])
			 {
				 return 0;
			 }
		 }
		 return 0;
	 }
 }
 bool operator <(const integer &a,const integer &b)
 {
	 if (a.elen>b.elen)
	 {
		 return 0;
	 }
	 else if (a.elen<b.elen)
	 {
		 return 1;
	 }
	 else
	 {
		 for (int i = a.elen; i > 0; i--)
		 {
			 if (a.num[i]>b.num[i])
			 {
				 return 0;
			 }
			 else if (a.num[i]<b.num[i])
			 {
				 return 1;
			 }
		 }
		 return 0;
	 }
 }
 bool  operator >=(const integer &a,const integer &b)
 {
	 if (a.elen>b.elen)
	 {
		 return 1;
	 }
	 else if (a.elen<b.elen)
	 {
		 return 0;
	 }
	 else
	 {
		 for (int i = a.elen; i > 0; i--)
		 {
			 if (a.num[i]>b.num[i])
			 {
				 return 1;
			 }
			 else if (a.num[i]<b.num[i])
			 {
				 return 0;
			 }
		 }
		 return 1;
	 }
 }
 bool  operator <=(const integer &a,const integer &b)
 {
	 if (a.elen>b.elen)
	 {
		 return 0;
	 }
	 else if (a.elen<b.elen)
	 {
		 return 1;
	 }
	 else
	 {
		 for (int i = a.elen; i > 0; i--)
		 {
			 if (a.num[i]>b.num[i])
			 {
				 return 0;
			 }
			 else if (a.num[i]<b.num[i])
			 {
				 return 1;
			 }
		 }
		 return 1;
	 }
 }
 bool  operator ==(const integer &a,const integer &b)
 {
	 if (a.elen!=b.elen)
	 {
		 return 0;
	 }
	 else
	 {
		 for (int i = a.elen; i > 0; i--)
		 {
			 if (a.num[i]!=b.num[i])
			 {
				 return 0;
			 }
		 }
		 return 1;
	 }
 }
 bool  operator !=(const integer &a,const integer &b)
 {
	 if (a.elen != b.elen)
	 {
		 return 1;
	 }
	 else
	 {
		 for (int i = a.elen; i > 0; i--)
		 {
			 if (a.num[i] != b.num[i])
			 {
				 return 1;
			 }
		 }
		 return 0;
	 }
 }

 integer &operator <<(integer &a, const int &b)
 {
	 int temp = b;
	 while (temp>0)
	 {
		a.MulTen();
		temp /= 10;
	 }
	 return a;
 }
 integer &operator >>(integer &a, const int &b)
 {
	 int temp = b;
	 while (temp>0)
	 {
		 a.MulTen();
		 temp /= 10;
	 }
	 return a;
 }
 //强制类型转换
 integer::operator float()
 {
	 float result=0.0;
	 for (int i = 0; i < elen;i++)
	 {
		 result = result * 10 + num[i];
	 }
	 return result;
 }
 integer::operator double()
 {
	 double result = 0.0;
	 for (int i = 0; i < elen; i++)
	 {
		 result = result * 10 + num[i];
	 }
	 return result;
 }
 integer::operator long double()
 {
	 long double result = 0.0;
	 for (int i = 0; i < elen; i++)
	 {
		 result = result * 10 + num[i];
	 }
	 return result;
 }
 integer::operator int()
 {
	 int result = 0;
	 for (int i = 0; i < elen; i++)
	 {
		 result = result * 10 + num[i];
	 }
	 return result;
 }
 integer::operator long()
 {
	 long result = 0;
	 for (int i = 0; i < elen; i++)
	 {
		 result = result * 10 + num[i];
	 }
	 return result;
 }
 integer::operator long long()
 {
	 long long result = 0;
	 for (int i = 0; i < elen; i++)
	 {
		 result = result * 10 + num[i];
	 }
	 return result;
 }
 //输出
 void integer::Print()const
 {
	 int i = 0;
	 for (i = 0; i < elen;i++)
	 {
		 printf("%d",num[elen-i-1]);
	 }
 }