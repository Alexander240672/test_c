//calloc
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
    //开辟十个整型的空间
    int* p = (int*)calloc(10,sizeof(int));
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    int i = 0; 
    for(i = 0;i < 10;i++)
    {
        printf("%d ",*(p + i));
    }
    free(p);
    p = NULL;
    return 0;
}