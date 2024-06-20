// 折半查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目3：输入n(n<100)个有序正数，请用折半查找算法，查找x在其中的位置。
//例如,
//输入:
//5
//1, 2, 3, 4, 5
//2
//输出 :
//    2
//    测试集合中，x数一定在正数数组中。即不用处理错误逻辑。


#include <stdio.h>
#include<malloc.h>
int main()
{
    int* nums;
    int a;
    scanf_s("%d", &a);
    getchar();
    nums = (int*)malloc(sizeof(int)*a);
    for (int i = 0; i < a; i++)
    {
        scanf_s("%d", &nums[i]);
        getchar();
    }
    int ans;
    int low=0,high=a;
    int mid = (high - low) / 2+low;
    scanf_s("%d", &ans); 
    while (nums[mid] != ans||low>high)
    {
        if (ans > nums[mid])
        {
            low = mid + 1;
        }
        if (ans < nums[mid])
        {
            high = mid - 1;
        }
        mid = (high - low) / 2+low;

    }
    printf("%d", mid+1);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
