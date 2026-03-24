//通讯录相关的声明
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdlib.h>
#include <errno.h>
#define default_sz 3
#define inc_sz 2
#define max 100
#define max_name 20
#define max_sex 10
#define max_tele 12
#define max_addr 30
//人的信息
typedef struct peoinfo
{
    char name[max_name];
    int age;
    char sex[max_sex];
    char tele[max_tele];
    char addr[max_addr];
}peoinfo;
//通讯录
//静态版本
// typedef struct contact
// {
//     peoinfo data[100];
//     int count;//记录当前通讯录实际人的个数
// }contact;

//动态版本
typedef struct contact
{
    peoinfo* data;
    int count;//记录当前通讯录实际人的个数
    //当前通讯录的容量
    int capacity;
}contact;

//初始化通讯录
int initcontact(contact* pc);
//添加联系人
void addcontact(contact* pc);
//打印通讯录信息
void showcontact(const contact* pc);
//删除指定联系人
void delcontact(contact* pc);
//查找联系人
void searchcontact(contact* pc);
//修改联系人
void modifycontact(contact* pc);
//排序联系人
//按照名字排序
void sortcontact(contact* pc);
//销毁通讯录
void destroycontact(contact* pc);