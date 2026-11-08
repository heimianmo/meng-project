#include <stdio.h>
#include <malloc.h>

typedef struct Lnode
{
	int data;
	struct Lnode* next;
}LNode;

LNode* create_reverseList(int n);
LNode* create_LinkList(int n);
LNode *Link(LNode* new_list1, LNode* new_list2);

int main()
{
	LNode* new_list1, * new_list2,*p;
	new_list1 = create_LinkList(4);
	new_list2 = create_LinkList(5);

	p = new_list1;
	while (p->next != NULL)
		p = p->next;

	Link(new_list1, new_list2);
	
	printf("%d\n", p->next->data);
	return 0;
}
LNode* create_reverseList(int n)
{
	int data, i;
	LNode* head, * p;
	head = (LNode*)malloc(sizeof(LNode));//创造一个头节点
	head->next = NULL;
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &data);
		p = (LNode*)malloc(sizeof(LNode));//创造一个p节点
		p->data = data;
		p->next = head->next;
		head->next = p;
	}
	return(head);
}
LNode* create_LinkList(int n)
{
	int data, i;
	LNode* head, * p, * q;
	head = p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
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
LNode *Link(LNode* new_list1,LNode *new_list2)
{
	LNode* p,*q,*head;
	p = new_list1;
	q = new_list2;
	while (p->next !=  NULL)
		p = p->next;
	p->next = q->next;
	return(new_list1);
}