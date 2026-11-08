#include <stdio.h>
#include <malloc.h>

typedef struct sqlist
{
	int* elem;//指针
	int length;//链表当前存储的元素个数
	int listsize;//链表能存多少元素个数
}SqList;

void initList(SqList* p_sq1);
void insertElem(SqList* p_sq1, int score);
void listLength(SqList* p_sq1);

int main()
{
	SqList sq1;
	initList(&sq1);
	insertElem(&sq1, 89);
	insertElem(&sq1, 90);
	printf("%d,%d\n", sq1.elem[0], sq1.elem[1]);
	listLength(&sq1);
}
void initList(SqList *p_sq1)//建立一个链表
{
	p_sq1->elem = (int*)malloc(100 * sizeof(int));//动态内存分配管理函数，100为为函数分配100个格子，int是这100个格子的数据类型，强制类型转换，malloc默认是无类型的，要转换成int*类型
	p_sq1->length = 0;//初始化元素个数为0
	p_sq1->listsize = 100;//让链表一共能存100个元素
}
void insertElem(SqList *p_sq1,int score)
{
	p_sq1->elem[p_sq1->length] = score;//把分数存在链表里，第一个分数存在第零个格子里，第二个放在第一个格子里
	p_sq1->length++;//并且分数要不断增加，这样才能不断存不同位置
}
void listLength(SqList* p_sq1)
{
	printf("当前元素个数为%d\n", p_sq1->length);
}