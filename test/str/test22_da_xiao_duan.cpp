//大小端
#include <stdio.h>
// int check_sys()
// {
//     int a = 1;
//     return *(char*)&a; 
// }
int check_sys()
{
    union un
    {
        char c;
        int i;
    }u;
    u.i = 1;
    return u.c;
}
int main()
{
    //int a = 1;->0x 00 00 00 01   01是低地址
    //小端：低->高
    //01 00 00 00
    //大端: 高->低
    //00 00 00 01
    int ret = check_sys();
    if(ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}