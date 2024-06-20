// 层次遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一二叉树，输出其节点值的层序遍历。（即逐层地，从左到右访问所有节点）。
//先输入节点数，再输入节点值，null按 - 1输入也算节点数
//如下图所示给定一二叉树：
//3
/// \
//9  20
/// \
//15   7
//输入：7 回车
//3 9 20 -1 -1 15 7
//输出：3, 9 20, 15 7

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int count;//总节点数
    scanf_s("%d", &count);
    int* nums;//顺序存放二叉树
    nums = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
    {
        scanf_s("%d", nums + i);
    }//输入二叉树数据
    int times;//二叉树有times层
    int n=2;//辅助判断二叉树层数的变量
    for (times = 0; count >= n-1; times++)
    {
        n = n * 2;
    }//到这里判断好了二叉树的层数
    int m = 2;
    int k = 0;//辅助遍历的变量
    printf("%d ,", nums[0]);
    k++;
    for (int i = 1; i < times; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[k] != -1)
            {
                printf("%d ", nums[k]);
            }
            k++;
        }
        m *= 2;
        printf(",");
    }
    loop:
    printf("\b");
    return 0;
}

////下面是gpt跑的,依托勾使。。。。。
//#include <stdio.h>
//#include <stdlib.h>
//
//// 定义二叉树的节点结构
//typedef struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//// 定义队列节点结构
//typedef struct QueueNode {
//    TreeNode* data;
//    struct QueueNode* next;
//} QueueNode;
//
//// 定义队列结构
//typedef struct {
//    QueueNode* front;
//    QueueNode* rear;
//} Queue;
//
//// 初始化队列
//void initQueue(Queue* q) {
//    q->front = q->rear = NULL;
//}
//
//// 入队
//void enqueue(Queue* q, TreeNode* val) {
//    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//    newNode->data = val;
//    newNode->next = NULL;
//    if (q->rear == NULL) {
//        q->front = q->rear = newNode;
//    }
//    else {
//        q->rear->next = newNode;
//        q->rear = newNode;
//    }
//}
//
//// 出队
//TreeNode* dequeue(Queue* q) {
//    if (q->front == NULL) {
//        return NULL;
//    }
//    QueueNode* temp = q->front;
//    TreeNode* val = temp->data;
//    q->front = q->front->next;
//    free(temp);
//    if (q->front == NULL) {
//        q->rear = NULL;
//    }
//    return val;
//}
//
//// 层序遍历二叉树
//void levelOrder(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    Queue q;
//    initQueue(&q);
//    enqueue(&q, root);
//    while (q.front != NULL) {
//        int levelSize = q.rear - q.front + 1;
//        for (int i = 0; i < levelSize; i++) {
//            TreeNode* node = dequeue(&q);
//            printf("%d", node->val);
//            if (i != levelSize - 1) {
//                printf(", ");
//            }
//            if (node->left) {
//                enqueue(&q, node->left);
//            }
//            if (node->right) {
//                enqueue(&q, node->right);
//            }
//        }
//        if (q.front != NULL) {
//            printf(", ");
//        }
//    }
//}
//
//// 创建二叉树
//TreeNode* createBinaryTree(int* vals, int size) {
//    if (size == 0) {
//        return NULL;
//    }
//    TreeNode** nodes = (TreeNode**)malloc(size * sizeof(TreeNode*));
//    for (int i = 0; i < size; i++) {
//        if (vals[i] == -1) {
//            nodes[i] = NULL;
//        }
//        else {
//            nodes[i] = (TreeNode*)malloc(sizeof(TreeNode));
//            nodes[i]->val = vals[i];
//            nodes[i]->left = nodes[i]->right = NULL;
//        }
//    }
//    for (int i = 0; i < size; i++) {
//        if (nodes[i] != NULL) {
//            int leftIdx = 2 * i + 1;
//            int rightIdx = 2 * i + 2;
//            if (leftIdx < size) {
//                nodes[i]->left = nodes[leftIdx];
//            }
//            if (rightIdx < size) {
//                nodes[i]->right = nodes[rightIdx];
//            }
//        }
//    }
//    TreeNode* root = nodes[0];
//    free(nodes);
//    return root;
//}
//
//int main() {
//    int n;
//    scanf_s("%d", &n);
//    int* vals = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &vals[i]);
//    }
//    TreeNode* root = createBinaryTree(vals, n);
//    levelOrder(root);
//    free(vals);
//    return 0;
//}
// 
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
