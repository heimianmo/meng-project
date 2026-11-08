//队列是先进先出，后进后出
#include <stdio.h>
#include <windows.h>

typedef struct queue
{
	int sq[6];//用数组存数据，最多存6个
	int front;//队首，负责出队
	int rear;//队尾，负责入队
}Queue;

void init_queue(Queue* q);
void in_queue(Queue* q, int value);
int out_queue(Queue* q);
int is_full(Queue* q);
int is_empty(Queue* q);

int main()
{
	Queue q1;
	int result;
	init_queue(&q1);
	in_queue(&q1, 34);
	result = out_queue(&q1);
	printf("%d", result);

	return 0;
}
void init_queue(Queue* q)//队列初始化
{
	q->front = 0;//对首，管出队
	q->rear = 0;//队尾，管入队
}
void in_queue(Queue* q, int value)//入队函数
{
	if (is_full(q))//满吗？满也就是1，不可以入队
	{
		printf("队已满，不可以入队！\n");
		exit(-1);
	}
	else//不满，为0
	{
		q->sq[q->rear] = value;//把数据存进数组
		q->rear = (q->rear+1) % 6;//先往后挪一个，对应相除取余，这样可以循环，到第6个的时候回到最开始
	}
}
int out_queue(Queue* q)//出队函数
{
	int result;
	if (is_empty(q))//是空的吗，是空的就为1，执行不了
	{
		printf("队空，无法出队！\n");
		exit(-1);
	}
	else//不空
	{
		result = q->sq[q->front];
		q->front = (q->front+1) % 6;
	}
	return result;
}
int is_full(Queue* q)//判断队是否满
{
	if ((q->rear+1) % 6 == q->front)
		return 1;//满了返回1
	else
		return 0;//不满返回0
}
int is_empty(Queue* q)
{
	if (q->rear  == q->front)
		return 1;//空了返回1
	else
		return 0;//不空返回0
}