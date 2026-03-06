//冒泡排序使用qsort排序-函数指针
#include <stdio.h>
int cmp_int(const void* e1,const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}
void swap(char* buf1,char* buf2,int width)
{
    int i;
    for(i = 0;i < width;i++)
    {
        char temp = *buf1;
        *buf1 = *buf2;
        *buf2 = temp;
        buf1++;
        buf2++;
    }
}
void bubble_sort(void* arr,int sz,int width,int (*cmp)(const void* e1,const void* e2))
{
    int i = 0;
    //趟数
    for(i = 0;i < sz-1;i++)
    {
        int flag = 1;//假设数组是已经排好序
        //一趟冒泡排序的过程
        int j;
        for(j = 0;j < sz-1-i;j++)
        {
            if(cmp((char*)arr + j*width,(char*)arr + (j+1)*width))
            {
                //交换
                swap((char*)arr + j*width,(char*)arr + (j+1)*width,width); 
                flag = 0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
}
int int_cmp(const void* e1, const void* e2)
{
    return (*(int*)e1 > *(int*)e2);
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, sz, sizeof(arr[0]), int_cmp);
    int i = 0;
    for(i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}