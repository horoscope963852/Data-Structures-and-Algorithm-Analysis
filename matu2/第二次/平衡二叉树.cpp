// 平衡二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一二叉树，判断是否为平衡二叉树。如下图所示二叉树
//  3
// / \
//9  20
//   / \
//  15  7
//先输入节点总数（空节点也算）为7，再输入节点值（null为 - 1）
//输入：7 3 9 20 -1 -1 15 7
//输出：true

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int data;
    node* lchild;
    node* rchild;
}node;

node* createtree(int* datas, int num)//层序建立二叉树
//datas是包含二叉树数据的数组，-1代表NULL；num是二叉树包含的所有节点数，可以等于5或8，不一定要等于1 3 7
{
    node** nodes;
    int front = -1, rear = -1;
    int i = 0;//i是用来把数组数据传入二叉树里面的无意义变量
    nodes = (node**)malloc(sizeof(node*) * num);//辅助队列，用于创建层序二叉树
    if (nodes == NULL) { return NULL; }

    node* root;//创建一个根节点，用于返回
    root = (node*)malloc(sizeof(node));
    if (root == NULL) { return NULL; }

    nodes[++rear] = root;
    root->lchild = NULL;
    root->rchild = NULL;
    root->data = datas[i++];//root根节点入队
    while (i < num)
    {
        node* out_node = nodes[++front];//出队一个节点，下面还要把这个节点的左右子节点全部存入队列中

        //处理左子树，包括传入数据，入队，子树赋NULL
        
            out_node->lchild = (node*)malloc(sizeof(node));
            if (out_node->lchild == NULL) { return NULL; }
            out_node->lchild->lchild = NULL;
            out_node->lchild->rchild = NULL;
            out_node->lchild->data = datas[i];
            if (out_node->lchild == NULL) { return NULL; }
            nodes[++rear] = out_node->lchild;
        
        i++;

        //处理右子树，包括传入数据，入队，子树赋NULL
        if (i >= num)
        {
            break;
        }//处理之前，判断一下是否需要继续添加节点
        
            out_node->rchild = (node*)malloc(sizeof(node));
            if (out_node->rchild == NULL) { return NULL; }
            out_node->rchild->lchild = NULL;
            out_node->rchild->rchild = NULL;
            nodes[++rear] = out_node->rchild;
            if (out_node->rchild == NULL) { return NULL; }
            out_node->rchild->data = datas[i];
        
        i++;
    }
    free(nodes);
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
    if (root == NULL||root->data==-1)
    {
        return 0;
    }
    if ((root->lchild == NULL || root->lchild->data == -1) && (root->rchild == NULL || root->rchild->data == -1))
    {
        return 1;
    }
    return max(maxdeep(root->lchild), maxdeep(root->rchild)) + 1;
}//计算最大深度的程序

void printtree(node* root)
{
    if (root == NULL)
    {
        return;
    }
    printtree(root->lchild);
    printtree(root->rchild);
    return;
}

int judgetree(node* root,int* ans)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (fabs((double)(maxdeep(root->lchild) - maxdeep(root->rchild))) > 1)
        {
            *ans=0;
            return 0;
        }
    }
    judgetree(root->lchild, ans);
    judgetree(root->rchild, ans);
    return 0;
}

int main()
{
    int count;
    scanf_s("%d", &count);
    int* nums;
    nums = (int*)malloc(sizeof(int) * count);
    if (!nums)return 0;
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        scanf_s("%d", (nums + i));
    }
    node* root;
    root = createtree(nums, count);
    //printtree(root);  //（前序遍历打印）
    int ans = 1;
    judgetree(root,&ans);
    if (ans == 0)
    {
        printf("false");
    }
    else
    {
        printf("true");
    }
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
