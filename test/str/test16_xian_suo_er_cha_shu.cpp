//线索二叉树
#include <stdio.h>
#include <stdlib.h>
typedef char elemtype;
typedef struct threadnode
{
    elemtype data;
    struct threadnode* lchild;
    struct threadnode* rchild;
    int ltag;
    int rtag;
}threadnode;
typedef threadnode* threadtree;
char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;
threadtree prev;
// 前向声明
void threading(threadtree t);
//创建树
void createtree(threadtree* t)
{
    elemtype ch;
    ch = str[idx++];
    if(ch == '#')
    {
        *t = NULL;
    }
    else
    {
        //threadtree相当于threadnode*
        *t = (threadtree)malloc(sizeof(threadnode));
        (*t)->data = ch;
        createtree(&(*t)->lchild);
        if((*t)->lchild != NULL)
        {
            (*t)->ltag = 0;
        }
        createtree(&(*t)->rchild);
        if((*t)->rchild != NULL)
        {
            (*t)->rtag = 0;
        }
    }
}
//开始线索化
void inorderthreading(threadtree* head,threadtree t)
{
    //头节点
    *head = (threadtree)malloc(sizeof(threadnode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);
    if(t == NULL)
    {
        (*head)->lchild = *head; 
    }
    else
    {
        (*head)->lchild = t;
        prev = (*head);
        threading(t);
        //最后一个节点线索化
        prev->rchild = *head;
        prev->rtag = 1;
        //头节点右孩子指向最后一个节点
        (*head)->rchild = prev;
    }
}
//具体线索化
void threading(threadtree t)
{
    if(t != NULL)
    {
        threading(t->lchild);
        if(t->lchild == NULL)
        {
            t->ltag = 1;
            t->lchild = prev;
        }
        if(prev->rchild == NULL)
        {
            prev->rtag = 1;
            prev->rchild = t;
        }
        prev = t;
        threading(t->rchild);
    }
}
//使用线索进行中序遍历
void inorder(threadtree t)
{
    threadtree curr;
    curr = t->lchild;
    while(curr != t)
    {
        while(curr->ltag == 0)
        {
            curr = curr->lchild;
        }
        printf("%c",curr->data);
        while(curr->rtag == 1 && curr->rchild != t)
        {
            curr = curr->rchild;
            printf("%c",curr->data);
        }
        curr = curr->rchild;
    }
    printf("\n");
}
int main()
{
    threadtree head;
    threadtree t;
    //创建
    createtree(&t);
    //线索化
    inorderthreading(&head,t);
    //基于线索遍历
    printf("中序遍历的结果：");
    inorder(head);
    return 0;
}