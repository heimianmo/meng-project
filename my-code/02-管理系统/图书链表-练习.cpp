#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Booknode
{
    int number;   // 图书编号
    float price;  // 图书价格
    struct Booknode *next;
} BookNode;

BookNode *create_LinkList(int a);
void PrintList(BookNode *L);
BookNode *Locate_Node(BookNode *L, float key); 
int Get_Elem(BookNode *L,int i);
void Inser_BookNode(BookNode *L);
void Delete_BookNode(BookNode *L,int i);
void Modify_BookNode(BookNode *L,int i);
int main()
{
    int n,m,s,x;
    float search_price;
    BookNode *L;
    BookNode *result = NULL; // 用来接收查询结果
    
    printf("欢迎进入图书馆\n");
    printf("请输入你的原始图书数量: ");
    scanf("%d", &n);
    
    L = create_LinkList(n);
    PrintList(L);
    while(1)
    {
        printf("======图书管理系统======");
        printf("1.按编号查询图书\n");
        printf("2.按价格查询图书\n");
        printf("3.增加新记录\n");
        printf("4.删除记录\n");
        printf("5.修改记录\n");
        printf("0.退出系统\n");
        printf("请输入指令：");
        scanf("%d",&m);
        
        
        if(m==1)
        {
            printf("图书编号：");
            scanf("%d",&x);
            s=Get_Elem(L,x);
        }
        else if(m==2)
        {
            printf("\n请输入你要查询的图书价格(关键字): ");
            scanf("%f", &search_price);
            result = Locate_Node(L, search_price);//给result赋值
            if (result != NULL) 
            {
                printf("查询成功！\n");
                printf("价格为 %.2f 的图书编号是: %d\n", result->price, result->number);
                
            }
            else 
            {
                printf(" 查无此书：价格为 %.2f 的图书不存在！\n", search_price);
            }
        }
        else if(m==3)
        {
            Inser_BookNode(L);
            PrintList(L);
        }
        else if(m==4)
        {
            printf("请输入删除的图书编号：");
            scanf("%d",&x);
            Delete_BookNode(L,x);
            PrintList(L);
        }
        else if(m==5)
        {
            printf("请输入修改的图书编号：");
            scanf("%d",&x);
            Modify_BookNode(L,x);
            PrintList(L);
        }
        else if(m==0)
        {
            printf("结束使用！\n");
            break;
        }
        else
        {
            printf("指令错误！");
        }
    }
    return 0;
}

// 建立初始链表
BookNode *create_LinkList(int a)
{
    int i;
    BookNode *head, *p, *q;
    
    head = p = (BookNode *)malloc(sizeof(BookNode));
    p->next = NULL;
    
    for(i = 0; i < a; i++)
    {
        q = (BookNode *)malloc(sizeof(BookNode));
        q->next = NULL;
        
        printf("请输入第 %d 本书的信息(格式: 编号 价格): ", i + 1);
        scanf("%d %f", &q->number, &q->price);
        
        p->next = q;
        p = q;
    }
    return head;
}

void PrintList(BookNode *L)//打印
{
    BookNode *p = L->next;
    
    if(p == NULL)
    {
        printf("书库为空！\n");
        return;
    }
    printf("\n--- 图书列表 ---\n");
    while(p != NULL)
    {
        printf("图书编号: %d, 价格: %.2f\n", p->number, p->price);
        p = p->next;
    }
}
BookNode *Locate_Node(BookNode *L, float key)
{
    BookNode *p = L->next; 
    
    while (p != NULL)
    {
        // 浮点数比较不能写 p->price == key
        // 必须用差值小于一个很小的数（比如 0.00001）来判断相等
        if (p->price - key>-0.00001 && p->price - key<0.00001) 
        {
            return p; 
        }
        p = p->next; // 没找到就继续看下一本
    }
    
    return NULL; 
}
int Get_Elem(BookNode *L,int i)
{
    BookNode *p=L->next;
    while(p!=NULL)
    {
        if(p->number==i)
        {
            printf("查询成功！\n");
            printf("编号为%d的图书价格是：%.2f\n",i,p->price);
            return 1;
        }
       p= p->next;
    }
    printf("查询失败，未找到该编号\n",i);
    return 0;
}
void Inser_BookNode(BookNode *L)
{
    BookNode *p=L;
    BookNode *q;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    q=(BookNode*)malloc(sizeof(BookNode));
    q->next=NULL;
    printf("请输入新图书的信息：");
    scanf("%d %f",&q->number,&q->price);
    p->next=q;
    printf("插入成功\n");
}
void Delete_BookNode(BookNode *L,int i)
{
    BookNode *p=L;
    BookNode *q;
     while(p->next!=NULL&&p->next->number!=i)
    {
        p=p->next;
    }
    if(p->next==NULL)
    {
        printf("删除失败，未找到该编号%d图书\n",i);
    }
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);
        printf("删除成功！编号为%d的图书已经被移除。\n",i);
    }
}
void Modify_BookNode(BookNode *L,int i)
{
    BookNode *p=L->next;
    while(p!=NULL&&p->number!=i)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("修改失败：未查询到编号为%d的图书\n",i);
    }
    else
    {
        printf("找的图书，请修改！\n");
        printf("请输入新的编号：\n");
        scanf("%d",&p->number);
        printf("请输入新的价格：\n");
        scanf("%f",&p->price);
        printf("修改成功\n");
    }
}