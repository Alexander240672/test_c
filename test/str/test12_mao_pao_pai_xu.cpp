//冒泡排序-只能排序整型
#include <stdio.h>
void bubble_sort(int arr[],int sz)
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
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,sz);
    int i = 0;
    for(i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}