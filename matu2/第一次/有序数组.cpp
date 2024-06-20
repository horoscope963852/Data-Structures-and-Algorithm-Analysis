// 给定一个元素不超过20的整数数组 numbers ，该数组已按非递减顺序排列，请你从数组中找出满足相加之和等于目标数 target 的两个数。
// 如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
// 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
//从键盘输入数组元素个数、数组元素以及目标整数，用空格分开；
//输出符合要求的两个整数的下标 index1 和 index2，输出用“, ”分开
//如果没有符合要求的结果，输出：No solution found.
//示例 1：
//输入：4 2 7 11 15 9
//输出：1, 2
//解释：数组元素4个，分别为：2 7 11 15，目标为9，2 与 7 之和等于目标数 9 。因此 输出 1, 2 。
//示例 2：
//输入：10 1 2 3 4 5 6 7 8 9 18 19
//输出：1, 10
//解释：数组元素10个，分别为：1 2 3 4 5 6 7 8 9 18，目标为19，1 与 18 之和等于目标数 19。因此 输出 1, 10 。
//示例 3：
//输入：10 1 2 3 4 5 6 7 8 9 18 28
//输出：No solution found.
//解释：数组元素10个，分别为：1 2 3 4 5 6 7 8 9 18，目标为28，没有符合要求的数。


#include <stdio.h>
#include<malloc.h>
int main()
{
    int *nums;
    int max = 0;
    scanf_s("%d", &max);
    if (max > 20)
    {
        printf("error");
        return 0;
    }
    nums = (int*)malloc(sizeof(int) * max);
    for (int i = 0; i < max; i++)
    {
        scanf_s("%d", &nums[i]);
    }
    int tar;
    scanf_s("%d", &tar);
    for (int i = 0; i < max; i++)
    {
        for (int j = 1+i; j < max; j++)
        {
            if (nums[i] + nums[j] == tar)
            {
                printf("%d,%d", i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("No solution found.");
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
