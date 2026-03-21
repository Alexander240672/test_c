//通讯录相关的声明
#include <stdio.h>
#include <string.h>
#include <assert.h>
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
typedef struct contact
{
    peoinfo data[100];
    int count;//记录当前通讯录实际人的个数
}contact;
//初始化通讯录
void initcontact(contact* pc);
//添加联系人
void addcontact(contact* pc);
//打印通讯录信息
void showcontact(const contact* pc);
//删除指定联系人
void delcontact(contact* pc);