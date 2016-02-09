#include<iostream>
#include"integer.h"
#include"fraction.h"
using namespace std;
int main()
{
	fraction a(-2.5), b(4);
	 a= b*a;
	cout << a;
	getchar();
	return 0;
}