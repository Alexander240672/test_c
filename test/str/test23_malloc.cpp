//动态内存
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
int main()
{
    int arr[10] = {0};
    //动态内存开辟
    int* p = (int*)malloc(40);
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    //使用
    int i = 0;
    for(i = 0;i < 10;i++)
    {
        *(p + i) = i;
    }
    for(i = 0;i < 10;i++)
    {
        printf("%d ",*(p + i));
    }
    free(p);
    p = NULL;
    return 0;
}