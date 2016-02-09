#pragma once
class integer
{
public:
	//���캯��
	integer();
	integer(int);
//	integer(int num,int len);
	integer(long);
	integer(long long);
	//��������
	~integer();
	//���ƹ��캯��
	integer(const integer&a);
	//�����޷��ż���
	static integer plus(const integer &a, const integer &b);
	static integer min(const integer &a, const integer &b);
	static integer mul(const integer &a, const integer &b);
	static integer div(const integer &a, const integer &b);
	//���ز�����
	//��interger
	integer operator =(const integer &a);//��ֵ
	integer operator +()const;//��
	integer operator -()const;//��
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
	//���ೣ����ѧ����
	static integer fabs(const integer &numtemp);
	//����λ������
	long long size(void)const
	{
		return elen;
	}
	//��������
	int PAndN()const
	{
		return (pn>=0 ?  0 : 1);
	}
	//��ȡ��������
	int Read(int i)const
	{
		return num[elen-i-1];
	}
	//������Чλ��
	int EffNum()
	{
		return elen;
	}
	//����10
	integer DivTen()
	{
		for (int i=1; i < elen; i++)
		{
			num[i - 1] = num[i];
		}
		elen--;
	}
	//����10
	integer MulTen()
	{
		//���ռ��Ƿ��㹻
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
	//���·����С
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
	//���·����С
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
	//ǿ������ת��
	operator float();
	operator double();
	operator long double();
	operator int();
	operator long();
	operator long long();
	//���
	void Print()const;
private:
	long long elen;		//��Ч����
	long long llen;		//���Ƴ���
	int pn;		//����
	char *num;		//�������
};

