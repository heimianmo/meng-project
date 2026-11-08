#include <stdio.h>
#include <malloc.h>

typedef struct Book
{
	int id;
	float price;
	Book* next;
}book;

book* create_List();
book* search_Book(book* L, int key);

int main()
{
	book* L;
	L = create_List();
	printf("欢迎进入图书管理系统！\n");
	printf("按1查询图书\n");
	printf("按2增加图书记录\n");
	printf("按3删除图书记录\n");
	printf("按4修改图书记录\n");
	printf("请您输入数字指令：\n");
	int num;
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
	{
		int key;
		printf("请输入图书编号：（目前书架里有10101,10102,10103,10104,10105五本书）\n");
		scanf_s("%d", &key);
		search_Book(L, key);
		break;
	}
	default:
		printf("输出数字无效！请重新输入！\n");
	}
	return 0;
}
book* create_List()//尾插法创建链表
{
	int ids[] = { 10101,10102,10103,10104,10105 };
	double price[] = {19.8,25.0,32.5,28.0,45.0};
	int n = 5, i;

	book* head;
	head = (book*)malloc(sizeof(book));
	head->next = NULL;

	book* p, * q;
	q = head;

	for (i = 0;i < n;++i)
	{
		p = (book*)malloc(sizeof(book));
		p->id = ids[i];
		p->price = price[i];
		p->next = NULL;

		q->next = p;
		q = p;
	}
	return head;
}
book* search_Book(book *L,int key)//按照书的值查找书籍，书架L和编号key
{
	book* p;

	p = L->next;


	while (p != NULL && p->id != key)
		p = p->next;//遍历查找，挪动p

	if (p == NULL)
	{
		printf("查询失败！您所输入的编号在系统中查询不到\n");
		return NULL;
	}
	else
	{
		printf("查询成功！这本书编号%d，价格为%.1f元\n", p->id, p->price);
		return p;
	}
}