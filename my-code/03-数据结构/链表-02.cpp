#include <stdio.h>
#include <malloc.h>

typedef struct sqlist
{
	int* elem;//指针
	int length;//链表当前存储的元素个数
	int listsize;//链表能存多少元素个数
}SqList;

int initList(SqList* p_sq1);
int insertElem(SqList* p_sq1, int i, int score);
void listLength(SqList* p_sq1);
int appendElem(SqList* p_sq1, int score);
int Delete (SqList* p_sq1, int i);

int main()
{
	SqList sq1;

	int tag,tag_app,tag_in;
	tag = initList(&sq1);//通过tag来判断内存分配是否成功
	if (tag == 1)
		printf("表格已建立!\n");
	else
		printf("系统内存不足!\n");

	tag_app = appendElem(&sq1, 90);//判断90有没有追加进去
	if (tag_app == 1)
		printf("数据追加成功!\n");
	else
		printf("数据追加失败!\n");

	tag_app = appendElem(&sq1, 92);
	if (tag_app == 1)
		printf("数据追加成功!\n");
	else
		printf("数据追加失败!\n");

	tag_in = insertElem(&sq1, 1, 89);
	if (tag_in == 1)
		printf("插入成功!\n");
	else
		printf("插入失败!\n");
	printf("%d,%d,%d\n", sq1.elem[0], sq1.elem[1], sq1.elem[2]);

	//initList(&sq1);
	//insertElem(&sq1, 89);
	//insertElem(&sq1, 90);
	//printf("%d,%d\n", sq1.elem[0], sq1.elem[1]);
	//listLength(&sq1);
}
int initList(SqList* p_sq1)//建立一个链表
{
	p_sq1->elem = (int*)malloc(100 * sizeof(int));//先分配内存
	if (!p_sq1->elem)//判断p_sq1->elem指针是否为空指针，等价于p_sq1->elem==NULL，返回NULL即为分配失败，NULL代表0
		return 0;//说明分配错误
	else
	{
		p_sq1->length = 0;
		p_sq1->listsize = 100;
		return 1;//说明分配成功
	}
}
int insertElem(SqList* p_sq1,int i, int score)//重点！！！在表的第i个位置插入一个新元素score
{
	//i是插入的位置
	int j;
	if (i<0 || i>p_sq1->length + 1)//位置不对，一个是负数位置，一个是超出目前范围了，顺序表应该按顺序存储，不能一个有下一个就是空的
	{
		printf("不合法的位置输入!\n");
		return 0;
	}
	if (p_sq1->length >= 100)//如果表已经满了是不能存进去的
	{
		printf("线性表溢出!\n");
		return 0;
	}
	for (j = p_sq1->length - 1; j >= i - 1; --j)
	{
		p_sq1->elem[j + 1] = p_sq1->elem[j];
	}
	p_sq1->elem[i - 1] = score;
	p_sq1->length++;
	return 1;
}
void listLength(SqList* p_sq1)
{
	printf("当前元素个数为%d\n", p_sq1->length);
}
int appendElem(SqList* p_sq1, int score)//把一个新的元素放在顺序表的末尾，追加
{
	if (p_sq1->length >= 100)//看看目前元素个数有没有超过100，超过就发出提示
	{
		printf("线性表溢出!\n");
		return 0;
	}
	else
	{
		p_sq1->elem[p_sq1->length] = score;//把新元素写入数组的第length个位置，第一个元素放在第零个格子上
		p_sq1->length++;
		return 1;
	}
}
int Delete (SqList* p_sq1, int i)//删除元素，i代表要删除的是第i个元素
{
	int k;//循环索引
	int x;//用来保存将被删除的元素值
	if (p_sq1->length == 0)//长度为0没办法删除元素
	{
		printf("线性表为空!\n");
		return 0;
	}
	else if (i<1 || i>p_sq1->length)//针对已有元素，就是1到length
	{
		printf("要删除的数据元素不存在!\n");
		return 0;
	}
	else
	{
		x = p_sq1->elem[i - 1];//数组下标等于i-1
		for (k = i;k < p_sq1->length;k++)//被删位置后面的每个元素都向左移动一位，填补被删元素留下的空位，保持元素连续
			p_sq1->elem[k - 1] = p_sq1->elem[k];
		p_sq1->length--;
		return (x);//展示刚刚删掉了哪个值
	}
}