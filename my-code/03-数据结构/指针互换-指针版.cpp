#include <stdio.h>
int main()
{
	int* p, * q;
	int a = 3, b = 5;
	int t;
	//赋初始值
	p = &a;
	q = &b;
	//互换
	t = *p;
	*p = *q;
	*q = t;

	printf("a = %d,b = %d\n", a, b);
	return 0;
}