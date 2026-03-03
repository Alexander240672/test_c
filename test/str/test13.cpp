//二叉树-链式结构
//树的性质：
//1.树中结点的总数等于所有结点的度数之和加1
//2.对于度为m的树，第i层最多有m^(i-1)个节点。
//二叉树的性质：
//1.第 i 层上的节点数目最多为 2^(i-1)（i≥1）。
//2.深度为 k 的二叉树至多有 2^k - 1 个节点（k≥1）。
//3.在任意一棵二叉树中，若终端节点的个数为 n0，度为 2 的节点数为 n2，则 n0 = n2 + 1。
#include <stdio.h>
#include <stdlib.h>
typedef char elemtype;
typedef struct treenode
{
    elemtype data;
    struct treenode* lchild;
    struct treenode* rchild;
}treenode;
typedef treenode* bitree;
char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;
void createtree(bitree* t)
{
    elemtype ch;
    ch = str[idx++];
    if(ch == '#')
    {
        *t = NULL;
    }
    else
    {
        *t = (bitree)malloc(sizeof(treenode));
        (*t)->data = ch;
        createtree(&(*t)->lchild);
        createtree(&(*t)->rchild);
    }
}
//前序遍历
void preorder(bitree t)
{
    if(t == NULL)
    {
        return;
    }
    printf("%c ",t->data);
    preorder(t->lchild);
    preorder(t->rchild);
}
//中序遍历
void inorder(bitree t)
{
    if(t == NULL)
    {
        return;
    }
    inorder(t->lchild);
    printf("%c ",t->data);
    inorder(t->rchild);
}
//后序遍历
void postorder(bitree t)
{
    if(t == NULL)
    {
        return;
    }
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%c ",t->data);
}
int main()
{
    bitree t;
    createtree(&t);
    preorder(t);
    printf("\n");
    inorder(t);
    printf("\n");
    postorder(t);
    printf("\n");
    return 0;
}