#include <stdio.h>
#include <malloc.h>
#include <windows.h>

typedef struct Qnode
{
	int data;//排队号码
	struct Qnode* next;//指向下一个人
	//在结构体定义内部，QNode 这个简写名字还没生效，所以必须用全称 struct Qnode。等整个 typedef 结束后（分号之后），你才能在别的地方用 QNode*。
}QNode;

typedef struct link_queue
{
	QNode* front, * rear;
}Link_Queue;

Link_Queue* Init_LinkQueue(void);
void Insert_CirQueue(Link_Queue* Q, int e);
void Out_LinkQueue(Link_Queue* Q, int* x);

int main()
{
	Link_Queue* LQ;
	int result;
	LQ = Init_LinkQueue();

	Insert_CirQueue(LQ, 90);
	Insert_CirQueue(LQ, 98);
	Insert_CirQueue(LQ, 67);

	Out_LinkQueue(LQ, &result);
	printf("请%d号办理业务\n", result);

	Out_LinkQueue(LQ, &result);
	printf("请%d号办理业务\n", result);

	Out_LinkQueue(LQ, &result);
	printf("请%d号办理业务\n", result);

	return 0;
}
Link_Queue* Init_LinkQueue(void)
{
	Link_Queue* Q;//Q是队列头指针，算是管理员
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));//给p申请内存
	p->next = NULL;//要让p成为最后一个节点，后面没人
	Q = (Link_Queue*)malloc(sizeof(Link_Queue));
	Q->front = Q->rear = p;//管理员的两个手指都指向头结点
	return(Q);
}
void Insert_CirQueue(Link_Queue* Q, int e)//入队
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));//先申请空间
	p->data = e;//把号码放进去
	p->next = NULL;//让它成为最后一个
	Q->rear->next = p;//移动rear节点到下一个
	Q->rear = p;//这一步是"挪位"，让 rear 永远指向最后一个节点
}
void Out_LinkQueue(Link_Queue* Q, int* x)//出队
{//把队头第一个人放走，让他的下一个人变成新的排头，同时管理员的 front 往后挪一步。
	QNode* p;
	if (Q->front == Q->rear)
	{
		printf("队已空，无法出队\n");
		exit(-1);
	}
	p = Q->front->next;
	*x = p->data;//保存数据，把出队的数据"带回"给调用者，去 x 指向的那个地址（0x1000）里写东西
	Q->front->next = p->next;
	if (p == Q->rear)//这是边界情况：如果队列里只有一个元素，出队后队列变空，rear 必须退回头结点
		Q->rear = Q->front;//这样可以恢复成空对状态
	free(p);
}/*如果只用 return 返回数据，就没法告诉调用者"这次出队失败了"。所以常见做法是：
用 return 1 / 0 表示成功或失败。
用指针参数 * x 把数据"捎带"出去。*/