//qsort函数可以排序任意类型的数据
//void qsort(void* base,->你要排序的起始位置
//             size_t num,->待排序的数据元素个数
//             size_t width,->待排序的数据元素的大小（单位是字节）
//             int (*cmp)(const void* e1,const void* e2)->函数指针-比较函数   
// ) *e1 > *e2->return 1;*e1 == *e2 ->return 0;*e1 == *e2 ->return -1
//void* ->无具体类型的指针，可以接受任意类型的地址，不能解引用操作，也不能加减整数
//字符串比较大小用strcmp，strcmp返回1，0，-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp_int(const void* e1,const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}
//整型数组
void test1()
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    int i = 0;
    for(i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
}
//非整型
 typedef struct student
{
    char name[20];
    int age;
}stu;
int cmp_stu_by_name(const void* e1,const void* e2)
{
    //strcmp返回1，0，-1
    return strcmp(((stu*)e1)->name,((stu*)e2)->name);
}
void test2()
{
    stu s[] = {{"zhangsan",15},{"lisi",30},{"wangwu",25}};
    int sz = sizeof(s)/sizeof(s[0]);
    qsort(s,sz,sizeof(s[0]),cmp_stu_by_name);
}
int main()
{
    test1();
    test2();
    return 0;
}