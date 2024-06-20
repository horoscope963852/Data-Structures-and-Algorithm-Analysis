// 最大深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个二叉树 root ，输出其最大深度。二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。
//先输入节点数（空节点也算），再输入二叉树，输出最大深度。如以下示例。
//如二叉树：
//1
//\
//2
//节点数为3，最大深度为2
//示例：
//输入：3 1 null 2
//输出：2

#include <stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* createtree(int* nums,int count)//层序遍历顺序初始化
{
    node* root = (node*)malloc(sizeof(node));//根节点，要返回这个
    if (!root)return NULL;
    root->lchild = NULL;
    root->rchild = NULL;

    node** queue = (node**)malloc(sizeof(node*) * count);//辅助队列，用于层序遍历
    if (!queue)return NULL;

    int front = -1;
    int rear = -1;
    int index=-1;//索引，用于判断传入了多少个节点

    queue[++rear] = root;//根节点入队
    root->data = nums[++index];

    while (index < count-1 && front != rear)
    {

        node* node_out = NULL;
        node_out = queue[++front];//出队一个节点
        if (!node_out)return NULL;

        //处理这个节点的左子树，给它赋值并入队
        node_out->lchild = (node*)malloc(sizeof(node));
        if (!node_out->lchild)return NULL;
        node_out->lchild->lchild = NULL;
        node_out->lchild->rchild = NULL;
        queue[++rear] = node_out->lchild;
        node_out->lchild->data = nums[++index];

        //处理这个节点的右子树，给它赋值并入队
        if (index < count-1 && front != rear) 
        {
            node_out->rchild = (node*)malloc(sizeof(node));
            if (!node_out->rchild)return NULL;
            node_out->rchild->lchild = NULL;
            node_out->rchild->rchild = NULL;
            queue[++rear] = node_out->rchild;
            node_out->rchild->data = nums[++index];
        }
    }
    return root;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}//比较大小程序

int maxdeep(node* root)
{
    int count = 0;
    if (root->lchild == NULL||root->lchild->data==-1 && root->rchild == NULL|| root->rchild->data == -1)
    {
        return 1;
    }
    return max(maxdeep(root->lchild), maxdeep(root->rchild))+1;
}//计算最大深度的程序

void printtree(node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    printtree(root->lchild);
    printtree(root->rchild);
    return;
}

int main()
{
    int count;
    scanf_s("%d", &count);
    getchar();
    int* nums;
    nums = (int*)malloc(sizeof(int) * count);
    if (!nums)return 0; 
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        char ch;
        ch = getchar();
        if (ch == 'n')//输入的是null
        {
            getchar(); getchar(); getchar(); getchar();
            nums[index++] = -1;
        }
        else
        {
            nums[index++] = ch - '0';
            getchar();
        }
    }
    node* root;
    root=createtree(nums, count);
    //printtree(root);  （前序遍历打印）
    int ans = maxdeep(root);
    printf("%d", ans);
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
