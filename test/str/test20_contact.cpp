//通讯录的实现->函数
#include "test20_tong_xun_lu.h"
//初始化通讯录
//静态版本
// void initcontact(contact* pc)
// {
//     assert(pc);
//     pc->count = 0;
//     memset(pc->data,0,sizeof(pc->data));
// }

//动态版本
int initcontact(contact* pc)
{
    assert(pc);
    pc->count = 0;
    pc->data = (peoinfo*)calloc(default_sz,sizeof(peoinfo));
    if(pc->data == NULL)
    {
        printf("initcontact::%s\n",strerror(errno));
        return 1;
    }
    pc->capacity = default_sz;
    return 0;
}

//添加联系人
//静态版本
// void addcontact(contact* pc)
// {
//     assert(pc);
//     if(pc->count == max)
//     {
//         printf("通讯录已满，无法添加\n");
//         return;
//     }
//     //输入
//     printf("请输入名字：");
//     scanf("%s",pc->data[pc->count].name);
//     printf("请输入年龄：");
//     scanf("%d",&(pc->data[pc->count].age));
//     printf("请输入性别：");
//     scanf("%s",pc->data[pc->count].sex);
//     printf("请输入电话：");
//     scanf("%s",pc->data[pc->count].tele);
//     printf("请输入地址：");
//     scanf("%s",pc->data[pc->count].addr);
//     pc->count++;
//     printf("增加成功\n");
// }

//动态版本
void checkcapacity(contact* pc)
{
    if(pc->count == pc->capacity)
    {
        peoinfo* ptr = (peoinfo*)realloc(pc->data,(pc->capacity + inc_sz)* sizeof(peoinfo));
        if(ptr == NULL)
        {
            printf("addcontact::%s\n",strerror(errno));
            return;
        }
        else
        {
            pc->data = ptr;
            pc->capacity += inc_sz;
            printf("增容成功\n");
        }
    }
}
void addcontact(contact* pc)
{
    assert(pc);
    //增容
    checkcapacity(pc);
    //输入
    printf("请输入名字：");
    scanf("%s",pc->data[pc->count].name);
    printf("请输入年龄：");
    scanf("%d",&(pc->data[pc->count].age));
    printf("请输入性别：");
    scanf("%s",pc->data[pc->count].sex);
    printf("请输入电话：");
    scanf("%s",pc->data[pc->count].tele);
    printf("请输入地址：");
    scanf("%s",pc->data[pc->count].addr);
    pc->count++;
    printf("增加成功\n");
}

//打印通讯录
void showcontact(const contact* pc)
{
    assert(pc);
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","名字","年龄","性别","电话","地址");
    for(int i = 0;i < pc->count;i++)
    {
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",pc->data[i].name,pc->data[i].age,pc->data[i].sex,
            pc->data[i].tele,pc->data[i].addr);
    }
}
static int findname(contact* pc,char name[])
{
    assert(pc);
    int i = 0;
    for(i = 0;i < pc->count;i++)
    {
        if(strcmp(pc->data[i].name,name) == 0)
        {
            return i;
        }
    }
    return -1;
}
//删除联系人
void delcontact(contact* pc)
{
    char name[max_name];
    assert(pc);
    int i = 0;
    if(pc->count == 0)
    {
        printf("通讯录为空");
        return;
    }
    printf("请输入要删除联系人名字：");
    scanf("%s",name);
    //删除
    //1.查找
    int pos = findname(pc,name);
    if(pos == -1)
    {
        printf("要删除的人不存在");
        return;
    }
    //2.删除
    for(i = pos;i < pc->count-1;i++)
    {
        pc->data[i] = pc->data[i+1];
    }
    pc->count--;
    printf("删除成功");
}
//查找联系人
void searchcontact(contact* pc)
{
    char name[max_name];
    assert(pc);
    int i = 0;
    if(pc->count == 0)
    {
        printf("通讯录为空");
        return;
    }
    printf("请输入要查找联系人名字：");
    scanf("%s",name);
    //查找
    int pos = findname(pc,name);
    if(pos == -1)
    {
        printf("要查找的人不存在");
        return;
    }
    //打印
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","名字","年龄","性别","电话","地址");
    printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",pc->data[pos].name,pc->data[pos].age,pc->data[pos].sex,
            pc->data[pos].tele,pc->data[pos].addr);
    
}
//修改联系人
void modifycontact(contact* pc)
{
    char name[max_name];
    assert(pc);
    int i = 0;
    if(pc->count == 0)
    {
        printf("通讯录为空");
        return;
    }
    printf("请输入要修改联系人名字：");
    scanf("%s",name);
    //查找
    int pos = findname(pc,name);
    if(pos == -1)
    {
        printf("要修改的人不存在");
        return;
    }
    printf("要修改的人的信息找到，接下来开始修改\n");
    //修改
    printf("请输入名字：");
    scanf("%s",pc->data[pos].name);
    printf("请输入年龄：");
    scanf("%d",&(pc->data[pos].age));
    printf("请输入性别：");
    scanf("%s",pc->data[pos].sex);
    printf("请输入电话：");
    scanf("%s",pc->data[pos].tele);
    printf("请输入地址：");
    scanf("%s",pc->data[pos].addr);
    printf("修改成功\n");
}
//排序联系人
//按照名字排序
int cmp_peo_name(const void* e1,const void* e2)
{
    return strcmp(((peoinfo*)e1)->name,((peoinfo*)e2)->name);
}
void sortcontact(contact* pc)
{
    assert(pc);
    qsort(pc->data,pc->count,sizeof(peoinfo),cmp_peo_name);
    printf("排序成功");
}
//销毁通讯录
void destroycontact(contact* pc)
{
    assert(pc);
    free(pc->data);
    pc->data = NULL;
    pc = NULL;
}