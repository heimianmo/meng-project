#include <stdio.h>
#include <malloc.h>

typedef struct BOOK
{
	int id;
	float price;
	BOOK* next;
}Book;

Book* create_List(int n);
Book* key_List(Book* L, int key);
Book* add_List(Book* L, int key, float price);
Book* delete_List(Book* L, int key);
void show_List(Book* L);
void modify(Book* L, int key, float price);

int main()
{
	int num, n, input, input1, input3, input4;
	float input2, input5;
	Book* L;
	L = create_List(5);

	printf("欢迎进入图书管理系统!\n");
	printf("按1代表查询\n");
	printf("按2代表添加记录\n");
	printf("按3代表删除记录\n");
	printf("按4代表修改记录\n");
	printf("按5代表退出\n");
	show_List(L);

	while (1)
	{
		printf("请输入数字指令：\n");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			printf("请输入你想要查询的图书的编号：\n");
			scanf_s("%d", &input);
			key_List(L, input);
			show_List(L);
			break;
		case 2:
			printf("请输入你想要增加的图书编号和该书的价格：\n");
			scanf_s("%d", &input1);
			scanf_s("%f", &input2);
			add_List(L, input1, input2);
			show_List(L);
			break;
		case 3:
			printf("请输入你想要删除的图书编号：\n");
			scanf_s("%d", &input3);
			delete_List(L, input3);
			show_List(L);
			break;
		case 4:
			printf("请输入你想要修改的图书编号和价格：\n");
			scanf_s("%d", &input4);
			scanf_s("%f", &input5);
			modify(L, input4, input5);
			break;
		case 5:
			printf("退出成功！\n");
			return 0;
		default:
			printf("执行错误！请您输入正确的指令\n");
			break;
		}
	}
	return 0;
}
Book* create_List(int n)//创建链表
{
	int id[] = { 10001,10002,10003,10004,10005 };
	float price[] = { 19.8,25.0,12.5,39.9,15.6 };

	Book* head, * p, * q;
	head = p = (Book*)malloc(sizeof(Book));
	p->next = NULL;
	int i = 0;

	for (i = 0;i < n;i++)
	{
		q = (Book*)malloc(sizeof(Book));
		q->id = id[i];
		q->price = price[i];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head;
}
void show_List(Book* L)
{
	Book* p;
	int i = 0;
	p = L->next;
	while (p != NULL)
	{
		printf("%d\n", p->id);
		p = p->next;
		i++;
	}
	printf("当前书架上有：这%d本书\n",i);

}
Book* key_List(Book* L, int key)//通过图书编号值来查找图书
{
	Book* p, * q;
	int i = 1;

	p = L->next;
	while (p != NULL && p->id != key)
	{
		p = p->next;
		i++;
	}
	if (p != NULL)//查找成功
	{
		printf("编号为%d的书在书架上的第%d位，价格为%.1f\n", key, i, p->price);
		return p;
	}
	else
	{
		printf("查询失败！您所查询的图书不在书架中！\n");
		return NULL;
	}
}
Book * add_List(Book* L, int key, float price)//插入编号进去
{
	Book* p, * q;
	p = L;

	while (p->next != NULL)
		p = p->next;

		q = (Book*)malloc(sizeof(Book));
		q->next = NULL;
		q->id = key;
		q->price = price;
		p->next = q;
		printf("插入成功！编号为%d，价格为%.1f的书已经成功添加到书架上\n", key, price);

		return L;
}
Book* delete_List(Book* L, int key)
{
	Book* p, * q;
	p = L;
	q = L->next;
	while (q != NULL && q->id != key)
	{
		p = q;
		q = q->next;
	}
	if (q != NULL && q->id == key)
	{
		p->next = q->next;
		free(q);
		printf("删除成功！编号为%d的书已经被删除！\n",key);
	}
	else
	{
		printf("删除失败！您所输入的编号所对应的书在书架中没有被找到！\n");
	}
	return L;
}
void modify(Book* L,int key,float price)
{
	Book* p;
	p = L->next;
	while (p != NULL && p->id != key)
		p = p->next;
	if (p != NULL)
	{
		p->price = price;
		printf("修改成功！编号为%d的书价格已经改为%.1f\n", key, price);
	}
	else
	{
		printf("修改失败！\n");
	}
}