/*栈是先进后出，后进先出
ps是找到成员，*ps是找到成员后，顺着它里面存的地址找到那个格子
-> 本身就是“* 和 . 的合体
p->id      等价于  (*p).id*/
#include <stdio.h>
#include <malloc.h>

typedef struct sqstack
{
	int* bottom;//底部，固定不动，标识栈空间起点
	int* top;//顶部，浮动指针，始终指向“下一个可存放数据的位置”（而不是栈顶元素本身），所以入栈是“先存数据再移动指针”
	/*这里top类型名是int* ，ps->top指向的内容本身就是地址，而int id  p->id指向的内容是个数值，不是地址*/
	int stacksize;//栈的空间
}SqStack;

void init_stack(SqStack* ps, int N);
void push_stack(SqStack* ps, int result);
int pop_stack(SqStack* ps);

int main()
{
	SqStack s;//栈
	int n, val, i, key;

	printf("请输入所申请空间的大小：\n");
	scanf_s("%d", &n);
	init_stack(&s, n);//把栈初始化，把s的地址传下来

	for (i = 0;i < 5;i++)//压进去5个数据
	{
		printf("请输入数据：\n");
		scanf_s("%d", &val);
		push_stack(&s, val);
	}

	key = pop_stack(&s);
	printf("%d\n", key);//把第最后一个数弹出来，因为栈是后进先出

	return 0;
}
void init_stack(SqStack* ps, int N)//初始化栈
{
	ps->bottom = (int*)malloc(N * sizeof(int));//要n个int型的空间
	ps->top = ps->bottom;//栈顶等于栈底，目前是空栈
	ps->stacksize = N;//容量是N，让用户决定
}
void push_stack(SqStack* ps, int result)//压栈，接栈名和值，就是接受元素进栈
{
	*ps->top = result;//先把值存入top指向的位置
	ps->top++;//指针上移
}
int pop_stack(SqStack* ps)//弹栈，就是取出元素出栈
{
	int result;
	ps->top--;//指针先下移，指向栈顶元素
	result = *ps->top;//取出该元素
	return result;
}