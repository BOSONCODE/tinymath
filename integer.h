#pragma once
class integer
{
public:
	//构造函数
	integer();
	integer(int);
//	integer(int num,int len);
	integer(long);
	integer(long long);
	//析构函数
	~integer();
	//复制构造函数
	integer(const integer&a);
	//基础无符号计算
	static integer plus(const integer &a, const integer &b);
	static integer min(const integer &a, const integer &b);
	static integer mul(const integer &a, const integer &b);
	static integer div(const integer &a, const integer &b);
	//重载操作符
	//与interger
	integer operator =(const integer &a);//赋值
	integer operator +()const;//正
	integer operator -()const;//负
	friend integer operator +(const integer &a,const integer &b);
	friend integer operator -(const integer &a,const integer &b);
	friend integer operator *(const integer &a,const integer &b);
	friend integer operator /(const integer &a,const integer &b);
	friend  bool  operator >(const integer &a,const integer &b);
	friend  bool  operator <(const integer &a,const integer &b);
	friend  bool  operator >=(const integer &a,const integer &b);
	friend  bool  operator <=(const integer &a,const integer &b);
	friend  bool  operator ==(const integer &a,const integer &b);
	friend  bool  operator !=(const integer &a,const integer &b);
	friend integer &operator <<(integer &a, const int &b);
	friend integer &operator >>(integer &a, const int &b);
	//各类常用数学函数
	static integer fabs(const integer &numtemp);
	//测量位数长度
	long long size(void)const
	{
		return elen;
	}
	//测试正负
	int PAndN()const
	{
		return (pn>=0 ?  0 : 1);
	}
	//读取单个数字
	int Read(int i)const
	{
		return num[elen-i-1];
	}
	//计算有效位数
	int EffNum()
	{
		return elen;
	}
	//除以10
	integer DivTen()
	{
		for (int i=1; i < elen; i++)
		{
			num[i - 1] = num[i];
		}
		elen--;
	}
	//乘以10
	integer MulTen()
	{
		//检查空间是否足够
		if (elen>=llen-1)
		{
			ReSize(2*elen);
		}
		for (long long i = elen; i > 0; i--)
		{
			num[i+1] = num[i];
		}
		num[0] = 0;
		elen++;
	}
	//重新分配大小
	int ReSize(long long numtemp)
	{
		char *temp;
		temp = (char *)realloc(num,numtemp);
		if (temp == NULL)
		{
			return 1;
		}
		else
		{
			num = temp;
			return 0;
		}
	}
	//重新分配大小
	int ReSize()
	{
		char *temp;
		temp = (char *)realloc(num, elen*2);
		if (temp == NULL)
		{
			return 1;
		}
		else
		{
			num = temp;
			return 0;
		}
	}
	//强制类型转换
	operator float();
	operator double();
	operator long double();
	operator int();
	operator long();
	operator long long();
	//输出
	void Print()const;
private:
	long long elen;		//有效长度
	long long llen;		//限制长度
	int pn;		//正负
	char *num;		//存放数字
};

