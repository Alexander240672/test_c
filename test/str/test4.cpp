//头插法出栈入栈
//栈可以看成一种特殊的节点结构
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 100
typedef  int elemtype ;
//定义结构体栈
typedef struct stack
{
    elemtype data[Max];
    int top;
}stack;
//初始化栈
stack* initstack()
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(s == NULL)
    {
        printf("内存分配失败！\n");
        return 0;
    }
    s->top = -1;
    return s;
}
//判断栈是否为空
bool isempty(stack* s)
{
    return s->top == -1;
}
//判断栈是否已满
bool isfull(stack* s)
{
    return s->top == Max-1;
}
//进栈
elemtype push(stack* s,elemtype n)
{
    if(isfull(s))
    {
        printf("栈为空，无法入栈！\n");
        return 0;
    }
    s->data[++s->top] = n;
    return 1;
}
//出栈
elemtype pop(stack* s)
{
    if(isempty(s))
    {
        printf("栈为空，无法出栈！\n");
        return 0;
    }
    return s->data[s->top--];
}
//获取栈顶元素
elemtype peek(stack* s)
{
    if(isempty(s))
    {
        printf("栈为空！\n");
        return 0;
    }
    return s->data[s->top];
}
//打印栈内容
void printstack(stack* s)
{
    if(isempty(s))
    {
        printf("栈为空！\n");
        return;
    }
    printf("栈内容(从栈底到栈顶):");
    for(int i = 0;i < s->top;i++)
    {
        printf("%d ",s->data[i]);
    }
    printf("\n");
}
int main()
{
    stack* s = initstack();
    printf("栈初始化成功！\n");
    //入栈
    printf("\n----测试入栈----\n");
    isempty(s);
    for(int i = 1;i <= 5;i++)
    {
        printf("入栈：%d\n",i);
        push(s,i);
        printf("当前栈顶：%d\n",s->top);
    }
    printstack(s);
    //测试出栈
    printf("\n----测试出栈----\n");
    while(!isempty(s))
    {
        printf("出栈：%d\n",pop(s));
        printf("当前栈顶:%d\n",s->top);
    }
    //释放内存
    free(s);
    return 0;
}