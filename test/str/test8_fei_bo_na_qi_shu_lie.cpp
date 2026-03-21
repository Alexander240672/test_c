//斐波那契数列-递归
#include <stdio.h>
int fibonacci(int n)
{
    //n是项数
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    int m = 5;
    int i = fibonacci(m);
    printf("%d",i);
    return 0;
}