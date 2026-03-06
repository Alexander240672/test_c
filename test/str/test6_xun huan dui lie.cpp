//循环队列
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef int elemtype;
//定义队列结构体
typedef struct queue
{
    elemtype* data;
    int front;
    int rear;
}queue;
//初始化队列
queue* initqueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->data = (elemtype*)malloc(sizeof(elemtype) * maxsize);
    q->front = 0;
    q->rear = 0;
    return q;
}
//判断队列是否为空
int isempty(queue* q)
{
   if(q->front == q->rear)
   {
    printf("空的\n");
    return 1;
   }
   else
   {
        return 0;
   }
}
//进队
int enqueue(queue* q,elemtype n)
{
    if((q->rear + 1)%maxsize == q->front)
    {
        printf("满了\n");
        return 0;
    }
    q->data[q->rear] = n;
    q->rear = (q->rear + 1)%maxsize;
    return 1;
}
//出队
int dequeue(queue* q,elemtype *n)
{
    if(q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *n = q->data[q->front];
    q->front = (q->front + 1)%maxsize;
    return 1;
}
int gethead(queue* q,elemtype* n)
{
    if(q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *n = q->data[q->front];
    return 1;
}
int main()
{
    queue* q = initqueue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    elemtype n;
    dequeue(q,&n);
    printf("%d\n",n);
    dequeue(q,&n);
    printf("%d\n",n);
    gethead(q,&n);
    printf("%d\n",n);
    return 0;
}