//删除有序数组中的重复项
//给你一个非严格递增排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度。元素的相对顺序应该保持一致 。然后返回nums中唯一元素的个数。
//数组元素个数不超过20个，从键盘输入数组元素个数以及数组元素，用空格分开；
//输出先输出删除后数组的新长度，然后输出删除后数组的元素，用空格分开；
//例如：
//输入：4 1 1 2 2回车
//输出：2 1 2

#include <stdio.h>
#include<malloc.h>

int main()
{
    int time;
    scanf_s("%d", &time);
    int num_out[20];
    int count=0;
    for (int i = 0; i < time; i++)
    {
        int num;
        scanf_s("%d", &num);
        int j;
        for (j = 0; j < count; j++)
        {
            if (num_out[j] == num)
            {
                break;
            }
        }
        if (j == count)
        {
            num_out[count] = num;
            count++;
        }
    }
    printf("%d", count);
    for (int i = 0; i < count; i++)
    {
        printf(" %d", num_out[i]);
    }
    return 0;
}
