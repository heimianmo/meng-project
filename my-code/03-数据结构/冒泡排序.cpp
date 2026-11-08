//从小到大排
#include <stdio.h>
int main()
{
	int i, j,t;
	int a[10] = { 3,6,1,9,5,4,7,2,0,8};

	for(i=0;i<10;i++)
		for (j = 0;j < 10 - 1 - i;j++)
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	printf("排好序的数字为:\n");
	for (i = 0;i < 10;i++)
		printf("%d", a[i]);
	return 0;
}