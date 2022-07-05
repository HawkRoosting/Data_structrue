//队列的链式实现--带头结点
#include <stdio.h>
#include <stdlib.h>

//节点结构
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;

//队列中队头队尾指针
typedef struct 
{
    LinkNode *front,*rear; //为什么这里的指针是结构体指针？
}LinkQueue;                         //因为队列中front，rear指向链式队列中节点

//队列初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//带头结点的情况，队列初始化为空，所以队头队尾节点都指向头节点
    //malloc返回的是所申请空间的指针，所以这里需要(LinkNode*)强制转换为你定义的数据元素类型的指针
    Q.front->next = NULL;
    //头节点的指针指向空
}

//判断是否为空
bool IsEmpty(LinkQueue &Q)
{
    if (Q.front == Q.rear)
    {
        printf("Queue is empty!\n");
        return true; //为空返回1
    }
    else
        return false;
}

//队列入队
void InQueue(LinkQueue &Q, int InElem)
{
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = InElem;
    s->next = NULL; //队列一端出一端进，新结点入队从队尾入（总是放在末尾）故需要置空
    Q.rear->next = s;//未入队之前的末尾元素内指针指向新结点
    Q.rear = s;//队尾指针更新为新入队的结点（rear总是指向队尾结点）
}

//队列出队
bool OutQueue(LinkQueue &Q, int &OutElem)
{
    //判断是否为空队列
    if (Q.front == Q.rear)
    {
        return false;
    }
    LinkNode *p = Q.front->next; //指针p指向需要出队的元素
    OutElem  = Q.front->data;  //OutElem将需要出队的元素的值带出来
    Q.front->next = p->next; //头节点指向需要出队元素的下一个元素（当队列中只剩最后一个元素时，指向NULL）
    if (Q.rear == p) //判断是否是最后一个元素出队
    {
        Q.rear = Q.front; //最后一个元素出队时，需修改rear
    }
    free(p);
    return true;
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    int InElem = 1;
    InQueue(Q, InElem);
    int OutElem;
    int out = OutQueue(Q, OutElem);
    printf("Outgoing element is %d", out);
}