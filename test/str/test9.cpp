//枚举
#include <stdio.h>
// typedef enum ->与结构体相似
// {
//     mon = 1,tue,wed,fri,sat,sun
// }weekday;
enum weekday
{
    mon = 1,tue,wed,fri,sat,sun//如果mon不赋值，那么从0开始往后数
};
int main()
{
    enum weekday a;
    //weekday a；
    a = mon;
    enum weekday b;
    b = tue;
    printf("%d\n",a);
    printf("%d\n",b);
    return 0;
}