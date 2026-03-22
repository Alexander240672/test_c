//联合
#include <stdio.h>
//共用空间
union un
{
    int a;
    char c;
};
union on
{
    short arr[7];
    int i;
};
int main()
{
    union un u;
    union on n;
    printf("%d\n",sizeof(u));
    printf("%d\n",sizeof(n));
    printf("%p\n",&u);
    printf("%p\n",&(u.a));
    printf("%p\n",&(u.c));
}