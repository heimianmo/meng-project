//这个文档中遇到的问题：
#include <stdio.h>

typedef struct kongtiao
{
	int state;//这里先不能给state赋值，这里只是规定类型
	double temperature;
	int mode;
}KT;

void switch_on(KT* ps);//函数语句要放在结构体定义的下面
void switch1(int input, KT* ps);
void tup(double target, KT* ps);
void tdown(double target, KT* ps);

int main()
{
	KT kt;
	kt.state = 0;
	kt.temperature = 26;
	int input, input1;
	double target;

	printf("请输入1来开机，0来关机\n");
	scanf_s("%d", &input);
	switch1(input, &kt);
	if (kt.state == 1)
	{
		printf("请输入您想要调整的目标温度：\n");
		scanf_s("%lf", &target);
		while (target > kt.temperature)
			tup(target, &kt);
		while (target < kt.temperature)
			tdown(target, &kt);
		printf("请您输入2代表制冷，3代表制热：\n");
		scanf_s("%d", &input1);
		if (input1 == 2)
			printf("当前模式为制冷\n");
		if (input1 == 3)
			printf("当前模式为制热\n");
	}
	return 0;
}

void switch_on(KT* ps)//这里的类型注意是KT
{
	ps->state = 1;
	printf("空调已打开，当前温度为26度，模式为制冷\n");
}//空调打开函数
void switch_off(KT* ps)
{
	ps->state = 0;
	printf("空调已关闭\n");
}//空调关闭函数
void switch1(int input, KT* ps)
{
	if (input == 1)
	{
		switch_on(ps);
	}
	if (input == 0)
	{
		switch_off(ps);
	}
}//判断用户调整空调开关的函数
void tup(double target, KT* ps)
{
	while (target > ps->temperature)
	{
		ps->temperature = ps->temperature + 0.5;
	}
	printf("温度已升高，当前温度为%.1f\n", ps->temperature);//注意是%.1f，保留一位小数

}
void tdown(double target, KT* ps)
{
	while (target < ps->temperature)
	{
		ps->temperature = ps->temperature - 0.5;
	}
	printf("温度已降低，当前温度为%.1f\n", ps->temperature);
}