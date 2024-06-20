// 建立排序二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//1、功能需求：
//根据一个给定的整数序列，生成二叉排序树，然后用先序遍历（验证二叉排序树是否成功建立）。
//二叉排序树中，左子树小于或等于树根，右子树大于树根。
//建议二叉树的结构定义：
//typedef int elemtype;
//struct node_type {
//    elemtype data;
//    struct node_type Lchild; //左孩子
//    struct node_type Rchild;//右孩子
//};
//2、输入要求
//从键盘输入的是整数序列，以空格或逗号间隔，以 - 1为结束， - 1不是树上的节点，如：
//23 45 34 12 78 24 - 1
//3、输出要求
//输出打印的先序遍历顺序也以空格或逗号间隔每个数字，如果是逐个打印，请记得在打印格式中加上空格或逗号。
//遍历并输出完成后，请记得到打印一个回车换行符：
//printf(“\n”);

#include <stdio.h>
#include <malloc.h>
typedef int elemtype;

typedef struct node_type {
    int data;
    struct node_type* lchild; // 指向左孩子的指针
    struct node_type* rchild; // 指向右孩子的指针
} node;

node* createtree()//最简洁的生成二叉树的方法，不调用参数，用递归
{
    int newdata;
    scanf_s("%d", &newdata);
    if (newdata == -1)
    {
        return NULL;
    }
    node* root = (node*)malloc(sizeof(node));
    root->data = newdata;
    root->lchild=createtree();
    root->rchild=createtree();
    return root;
}
//创建一个二叉树，以-1结束（需要很多个-1）
//上面的函数这个程序中用不到

node* addnode(node* root,int newdata)
{
    if (root == NULL)
    {
        node* newnode;
        newnode = (node*)malloc(sizeof(node));
        if (!newnode)
        {
            printf("malloc fail");
            return 0;
        }
        newnode->data = newdata;
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        return newnode;
    }
    else
    {
        if (newdata <= root->data)
        {
            root->lchild=addnode(root->lchild, newdata);
        }
        else
        {
            root->rchild=addnode(root->rchild, newdata);
        }//比树根的值小放左面，大就放右面
    }
    return root;
}

int preprinttree(node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preprinttree(root->lchild);
        preprinttree(root->rchild);
    }
    return 0;
}

int main()
{
    node* root = NULL;
    root=createtree();
    /*int newdata;
    scanf_s("%d", &newdata);
    while (newdata != -1)
    {
        root=addnode(root, newdata);
        scanf_s("%d", &newdata);
    }*/
    preprinttree(root);
    printf("\n");
}

