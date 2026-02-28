//双向链表
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
//初始化头节点
Node* initlist()
{
    Node* head = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("链表为空");
    }
    head->next = NULL;
    head->prev = NULL;
    return head;
}
//头插法
void inserthead(Node* head,int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = head->next;
    newnode->prev = head;
    if(head->next != NULL)
    {
        head->next->prev = newnode;
    }
    head->next = newnode;
}
//尾插法
void inserttail(Node* head,int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->prev = p;
}
//指定位置插入

void printlist(Node* head)
{
    Node* p = head->next;
    printf("正向链表：");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node* list = initlist();
    inserthead(list,10);
    inserthead(list,20);
    inserthead(list,30);
    inserttail(list,40);
    inserttail(list,60);
    inserttail(list,50);
    printlist(list);
    return 0;
}