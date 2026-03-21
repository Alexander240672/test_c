//递归-函数自己调用自己
#include <stdio.h>
int fun(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return fun(n - 1) + n;
    }
}
int main()
{
    int m = 5;
    int i = fun(m);
    printf("%d",i);
    return 0;
}