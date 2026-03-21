//位段-节省空间
//跨平台的问题
//1.位段最大位的数目不确定->16位机器为16，32位机器为12
//2.int位段被当成有符号还是无符号数是不确定的
//3.位段中的成员在内存中从右到左分配还是从左到右分配标准尚未定义
//4.当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是舍弃还是利用剩余的位，是不确定的
#include <stdio.h>
struct A
{
    int _a : 2;//->bit
    int _b : 5;
    int _c : 10;
    int _d : 30;
};
struct S
{
    char a : 3;
    char b : 4;
    char c : 5;//011补零->00011
    char d : 4;
};
int main()
{
    printf("%zu\n",sizeof(struct A));
    struct S s = {0};
    printf("%zu\n",sizeof(struct S));//浪费了一个bit位
    s.a = 10;//1010只能放进010
    s.b = 12;//1100能全部放
    s.c = 3;
    s.d = 4;
    return 0;
}