//测试通讯录功能
#include "test20_tong_xun_lu.h"
void menu()
{
    printf("**********************************\n");
    printf("*****  1.add       2.del     *****\n");
    printf("*****  3.search    4.modify  *****\n");
    printf("*****  5.show      6.sort    *****\n");
    printf("*****  0.exit                *****\n");
    printf("**********************************\n");
}
int main()
{
    int input = 0;
    contact con;//通讯录
    //初始化通讯录
    initcontact(&con);
    do
    {
        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                addcontact(&con);
                break;
            case 2:
                delcontact(&con);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                showcontact(&con);
                break;
            case 6:
                break;
            case 0:
                printf("退出通讯录\n");
                break;
            default:
                printf("选择错误\n");
        }
    } 
    while (input);
    return 0;
}