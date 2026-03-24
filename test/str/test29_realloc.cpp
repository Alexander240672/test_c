//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
    int* p = (int*)malloc(40);
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    //放1-10
    int i = 0;
    for(i = 0;i < 10;i++)
    {
        *(p + i) = i + 1;
    }
    //扩容
    int* ptr = (int*)realloc(p,80);
    if(ptr != NULL)
    {
        p = ptr;
    }
    //使用
    for(i = 0;i < 10;i++)
    {
        printf("%d ",*(p + i));
    }
    free(p);
    p = NULL;
    return 0;
}