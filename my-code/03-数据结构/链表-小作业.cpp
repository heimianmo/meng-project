#include <stdio.h>
#include <malloc.h>

typedef struct Lnode
{
	int data;
	Lnode* next;
}LNode;

LNode* create_LinkList(int n);
int Locate_Node(LNode* L, int key);
LNode* Get_Elem(LNode* L, int n);
LNode* insertElem(LNode* L, int num, int n);
LNode* Order_Delete(LNode* L, int i);
LNode* Key_Delete(LNode* L, int key);
void show_List(LNode* L);

int main()
{
	LNode* list1, * p, * q, * L;
	int input, input1, input2;
	int num, n, i = 1;

	list1 = create_LinkList(4);
	p = list1;
	L = list1;

	printf("请输入您想要查询的分数排在第几个：\n");
	scanf_s("%d", &input);
	q = Get_Elem(list1, input);
	if (q != NULL)
		printf("%d\n", q->data);

	printf("请输入您想要查找的数字：\n");
	scanf_s("%d", &input1);
	i = Locate_Node(list1, input1);
	printf("%d在第%d位\n", input1, i);

	printf("请输入你想插入到表中的数字和位置：\n");
	scanf_s("%d", &num);
	scanf_s("%d", &n);
	L = insertElem(L, num, n);
	show_List(L);

	printf("请输入您想要删除的数字的值：\n");
	scanf_s("%d", &input2);
	p = L;
	while (p->next != NULL)
		p = p->next;
	Key_Delete(L, input2);
	show_List(L);

	printf("请输入你想要删除数字的序号：\n");
	scanf_s("%d", &i);
	p = L;
	while (p->next != NULL)
		p = p->next;
	Order_Delete(L, i);
	show_List(L);
	return 0;
}
LNode* create_LinkList(int n)//尾插法创建链表
{
	LNode* head, * p, * q;
	int data, i;
	head = p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
	printf("请输入您想要存进链表中的数字：\n");
	for (i = n;i > 0;--i)
	{
		scanf_s("%d", &data);
		q = (LNode*)malloc(sizeof(LNode));
		q->data = data;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return(head);
}
int Locate_Node(LNode* L, int key)//按照值查找，要输入里面有的内容
{
	int i = 1;
	LNode* p = L->next;
	while (p != NULL && p->data != key)
	{
		p = p->next;
		i++;
	}
	if (p != NULL)
		return i;
	else
	{
		printf("您所要查找的节点不存在\n");
		return (NULL);
	}
}
LNode* Get_Elem(LNode* L, int n)//按照序号查找，排在第几位
{
	int j = 1;
	LNode* p = L->next;
	while (p != NULL && j < n)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > n)
	{
		return NULL;
		printf("您所输入的序号超出链表长度!\n");
	}
	else
		return p;
}
LNode* insertElem(LNode* L, int num, int n)//num是用户传进来的数字，n是用户想插入的位置//插入函数
{
	LNode* p, * q;
	int i = 0;//计数器

	p = L;
	q = (LNode*)malloc(sizeof(LNode));
	q->data = num;

	while (i < n - 1 && p->next != NULL)//用循环让p停在n-1的位置，然后再进行链接，插入
	{
		i += 1;
		p = p->next;
	}
	if (i < n - 1)
	{
		printf("插入失败！您所输入的位置超过了链表的位数！");
		free(q);
	}
	else
	{
		q->next = p->next;
		p->next = q;
		printf("插入成功!第%d个位置为%d\n", n, num);
	}
	return L;
}
LNode* Order_Delete(LNode* L, int i)//按序号(位置)删除
{
	LNode* p, * q;
	int j = 0;
	p = L;//要删除第一个元素的时候，p正好在n-1的位置，所以不能p=L->next

	while (j < i - 1 && p->next != NULL)
	{
		p = p->next;
		j += 1;
	}
	if (p->next == NULL)
	{
		printf("删除失败！位置超过链表长度\n");
	}
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		printf("删除成功！\n");
	}
	return L;//必须要有返回值
}
LNode* Key_Delete(LNode* L, int key)
{
	LNode* p, * q;
	p = L;

	while (p->next != NULL && p->next->data != key)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		printf("删除失败！要查找的值不存在\n");
	}
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		printf("%d删除成功!\n", key);
	}
	return L;
}
void show_List(LNode* L)
{
	LNode* p = L->next;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}