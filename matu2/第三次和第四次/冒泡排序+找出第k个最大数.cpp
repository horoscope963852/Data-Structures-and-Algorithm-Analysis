// 冒泡排序+找出第k个最大数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//冒泡

//#include<stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int a[10];
//    for (int i = 0; i < 10; i++)
//    {
//        scanf_s("%d", &a[i]);
//        getchar();
//    }
//    for (int i = 1; i < 10; i++)
//    {
//        for (int j = 0; j < 10 - i; j++)
//        {
//            if (a[j+1] < a[j])
//            {
//                int x = a[j];
//                a[j] = a[j+1];
//                a[j+1] = x;
//            }
//        }
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d", a[i]);
//    }
//    return 0;
//}

//请编写完整程序，在给定整数数组A[num]和整数 k，请返回数组中第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//输入：请按照第一个输入数组元素个数，依次输入各个元素，最后是k，元素个数最多不超过16个。
//输出：第K个最大元素的数值。
//例：
//输入：12 20 8 19 22 12 18 15 9 11 17 19 4 5
//表示有12个元素，需找出第5个最大元素
//输出：18

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	scanf_s("%d", &num);
	int* a;
	a = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            if (a[j+1] < a[j])
            {
                int x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
            }
        }
    }
	int x;
	scanf_s("%d", &x);
    printf("%d", a[num - x]);
    return 0;
}
