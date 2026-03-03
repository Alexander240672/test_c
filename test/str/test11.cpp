//函数指针数组
#include <stdio.h>
#include <stdio.h>
int add(int x,int y)
{
    return x + y;
}
int sub(int x,int y)
{
    return x - y;
}
int mul(int x,int y)
{
    return x * y;
}
int div(int x,int y)
{
    return x / y;
}
int main()
{
    int (*arr[4])(int,int) = {add,sub,mul,div};//arr是函数指针的数组
    int i = 0;
    for(i = 0;i < 4;i++)
    {
        int ret = arr[i](8,4);
        printf("%d\n",ret);
    }
    return 0;
}