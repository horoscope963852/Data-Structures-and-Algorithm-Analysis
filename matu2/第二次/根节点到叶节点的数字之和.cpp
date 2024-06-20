// 根节点到叶节点的数字之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一二叉树，树中每个节点都存放有0-9之间的数字，每条从根节点到叶节点的路径都代表一个数字
// 叶节点是指没有子节点的节点。计算从根节点到叶节点生成的所有数字之和。（null按-1输入也算节点数）
//如下图所示二叉树：
//1
/// \
//2   3
//其表示的数字为12与13，和为25。先输入节点数，再输入各节点值。
//即输入：3
//1 2 3
//输出：25

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}node;

// 创建新节点
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node != NULL) {
        node->val = val;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

// 层序建立二叉树
struct TreeNode* buildTreeWithNull(int* nums, int node_count) {
    if (node_count <= 0) return NULL;

    // 创建根节点
    struct TreeNode* root = newTreeNode(nums[0]);
    if (root == NULL) return NULL;

    // 创建队列用于辅助层序遍历
    struct TreeNode** queue = (struct TreeNode**)malloc(node_count * sizeof(struct TreeNode*));
    if (queue == NULL) return NULL;
    int front = 0, rear = 0;

    queue[rear++] = root;  // 根节点入队
    int index = 1;  // 输入数组的索引
    int count = 1;  // 记录已处理的节点数量

    while (front < rear && count < node_count) {
        struct TreeNode* node = queue[front++];

        // 处理左子节点
        if (index < node_count && nums[index] != -1) {
            node->left = newTreeNode(nums[index]);
            if (node->left != NULL) {
                queue[rear++] = node->left;
                count++;
            }
        }
        index++;

        // 处理右子节点
        if (index < node_count && nums[index] != -1) {
            node->right = newTreeNode(nums[index]);
            if (node->right != NULL) {
                queue[rear++] = node->right;
                count++;
            }
        }
        index++;
    }

    free(queue);  // 释放队列内存

    return root;
}

// 释放二叉树内存
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);  // 先访问根节点
    preorderTraversal(root->left);  // 再递归访问左子树
    preorderTraversal(root->right);  // 最后递归访问右子树
}

int sumNumbersHelper(TreeNode* root, int prevSum) {
    if (root == NULL) {
        return 0;
    }
    // 计算当前路径上的数字之和
    int currentSum = prevSum * 10 + root->val;
    // 如果是叶节点，则返回当前路径的数字之和
    if (root->left == NULL && root->right == NULL) {
        return currentSum;
    }
    // 递归计算左右子树的数字之和，并将它们相加
    return sumNumbersHelper(root->left, currentSum) + sumNumbersHelper(root->right, currentSum);
}

// 计算根节点到叶节点的所有数字之和
int sumNumbers(TreeNode* root) {
    return sumNumbersHelper(root, 0);
}

int main() {
    int nums[100];
    int node_count;
    scanf_s("%d", &node_count);
    for (int i = 0; i < node_count; i++)
    {
        scanf_s("%d", &nums[i]);
    }
    // 根据输入数组建立二叉树
    struct TreeNode* root = buildTreeWithNull(nums, node_count);

    // 前序遍历并打印结果
    printf("%d", sumNumbers(root));
    // 释放二叉树内存
    freeTree(root);
    return 0;
}