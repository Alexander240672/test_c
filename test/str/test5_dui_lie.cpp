//队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int elemtype;
//定义节点结构
typedef struct node
{
    elemtype data;
    struct node* next;
}node;
//定义队列结构
typedef struct queue
{
    node* front;
    node* rear;
}queue;
//初始化队列
queue* initqueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    if(q == NULL)
    {
        printf("内存分配失败！\n");
        return 0;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
//判断队列是否为空
bool isempty(queue* q)
{
    return q->front == NULL;
}
//入队（尾插法）
void enqueue(queue* q,elemtype data)
{
    if(q == NULL)
    {
        printf("队列不存在！\n");
    }
    //创造新节点赋值进去
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    //正式入队
    if(isempty(q))
    {
        //队列为空
        q->front = newnode;
        q->rear =newnode;
    }
    else
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    printf("%d 入队成功\n",data);
}
//出队（头删）
elemtype dequeue(queue* q)
{
    if(q == NULL || isempty(q))
    {
        printf("队列为空，无法出队\n");
        return -1;
    }
    //保存队头节点
    node* temp = q->front;
    elemtype value = temp->data;
    //队头指针后移
    q->front = q->front->next;
    //如果队列变空，需要更新rear指针
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    //释放原队头节点
    free(temp);
    printf("%d 出队成功\n",value);
    return value;
}
//打印队列
void printqueue(queue* q)
{
    if(q == NULL || isempty(q))
    {
        printf("队列为空\n");
        return;
    }
    printf("队列元素（从队头到队尾）:");
    node* current = q->front;
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}
//释放队列内存
void freequeue(queue* q)
{
    if(q == NULL)
    {
        return;
    }
    while(!isempty(q))
    {
        dequeue(q);
    }
    free(q);
    printf("队列已释放\n");
}
int main()
{
    queue* q = initqueue();
    if(q == NULL)
    {
        printf("初始化失败");
        return 1;
    }
    //测试入队
    printf("----测试入队----\n");
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    printqueue(q);
    //测试出队
    printf("\n----测试出队----\n");
    dequeue(q);
    printqueue(q);
    //测试空队列
    printf("\n----测试空队列----\n");
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printqueue(q);
    freequeue(q);
    return 0;
}