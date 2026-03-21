//单向链表
#include <stdio.h>
#include <stdlib.h>
//定义结构体
typedef struct Node
{
    int data;
    struct Node* link;
}Node;
//初始化头结点
Node* initlist()
{
    Node* head = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("链表为空");
    }
    head->link = NULL;
    return head;
}
//头插法
void insertlist(Node* head,int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        return;
    }
    newnode->data = data;
    newnode->link = head->link;
    head->link = newnode;
}
//打印链表
void printlist(Node* head)
{
    printf("链表内容：");
    Node* p = head->link;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->link;
    }
    printf("\n");
}
//删除结点
int deleteNode(Node* head,int data)
{
    Node* L = head;
    Node* k = head->link;
    while(k != NULL)
    {
        if(k->data == data)
        {
            L->link = k->link;
            free(k);
            printlist(head);
            return 1;
        }
        L = k;
        k = L->link;
    }
    return 0;
}
//尾插法
void inserttail(Node* head,int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    Node* m = head;
    while(m->link != NULL)
    {
        m = m->link;
    }
    m->link = newNode;
}
//中间位置插入
int insertsort(Node* head,int data,int po)
{
    if(po < 1)
    {
        return 0;
    }
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->link = NULL;
    NewNode->data = data;
    //找到position-1的结点
    Node* pr = head;
    int count = 0;
    while(pr != NULL && count < po-1)
    {
        pr = pr->link;
        count++;
    }
    //检查位置是否合法
    if(pr == NULL)
    {
        printf("位置%d超出链表长度\n",po);
        free(NewNode);
        return 0;
    }
    NewNode->link = pr->link;
    pr->link = NewNode;
    return 1;
}
int main()
{
    Node* list = initlist();
    insertlist(list,20);
    insertlist(list,30);
    insertlist(list,40);
    inserttail(list,50);
    inserttail(list,60);
    inserttail(list,70);
    insertsort(list,80,2);
    insertsort(list,90,4);
    insertsort(list,100,5);
    insertsort(list,110,12);
    printlist(list);
    deleteNode(list,20);
    deleteNode(list,60);
    deleteNode(list,100);
    return 1;
}