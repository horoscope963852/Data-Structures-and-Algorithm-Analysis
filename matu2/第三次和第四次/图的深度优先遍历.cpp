// 图的深度优先遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//分别用邻接矩阵和邻接链表两种数据结构实现图的深度优先遍历算法，输出遍历的结点序列，并分析算法的时间复杂度。

//提交格式：
//邻接矩阵数据结构实现void solveA(int n, int m, int e[][2], int out[])函数。
//邻接链表数据结构实现void solveB(int n, int m, int e[][2], int out[])函数。
//参数n为结点个数，m为边条数，e为所有边，out为输出序列。1 <= n <= 3000, 1 <= m <= 100000, 0 <= e[i][j] < n。
//    遍历的起始结点为0，邻接矩阵数据结构中按行从左到右遍历邻居结点，邻接链表数据结构中按存储顺序遍历邻居结点，图为无向图。
//    请不要printf输出任何内容。
//
//    输入样例：
//    n = 5, m = 10, e = { {2,4},{3,0},{0,2},{3,1},{4,1},{0,1},{3,4},{2,3},{1,2},{0,4} }
//    输出样例：
//    solveA：out = { 0,1,2,3,4 }
//    solveB：out = { 0,3,1,4,2 }

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;//链接的端点
    Node* next;//下一个端点的指针
};
typedef struct stack {
    int top;
    int data[500];
};

void solveA(int n, int m, int e[][2], int out[]);
void solveB(int n, int m, int e[][2], int out[]);
//前置深度优先搜索DFS函数
void dfs_A(int v, int* out, int** map, int n, int j)
//v是开始节点，out是输出矩阵，map是邻接矩阵，n是端点数量,j是用来标记谁先被访问的
{
    if (out[v] == 0)
    {
        out[v] = j++; // 标记为已访问
    }
    for (int i = 0; i < n; i++)
    {
        if (map[v][i] && !out[i])
        {
            dfs_A(i, out, map, n, j);
        }
    }
}
void solveA(int n, int m, int e[][2], int out[])
{
    int* visited;
    visited = (int*)malloc(sizeof(int) * n);
    if (!visited) return;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    //设置已遍历数组
    int** map;
    map = (int**)malloc(sizeof(int*) * n);
    if (!map) return;
    for (int i = 0; i < n; i++)
    {
        map[i] = (int*)malloc(sizeof(int) * n);
        if (!map[i]) return;
    }
    //分配邻接矩阵map的存储空间
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
    //初始化邻接矩阵map（赋0）
    for (int i = 0; i < m; i++)
    {
        map[e[i][0]][e[i][1]] = 1;
    }
    int i, u, v;

    // 构建邻接矩阵map
    for (i = 0; i < m; i++) {
        u = e[i][0];
        v = e[i][1];
        if (u >= n || v >= n || u < 0 || v < 0)
        {
            return;
        }
        map[u][v] = 1;
        map[v][u] = 1; // 因为是无向图
    }

    int* _out;
    _out = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        _out[i] = 0;
    }
    // 从顶点0开始DFS
    dfs_A(0, _out, map, n, 1);
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (_out[j] == i)
            {
                out[num++] = j;
            }
        }
    }


}

void dfs_B(int v, int* out, int n, int j, Node** adjList)
//v是开始节点，out是输出矩阵，adjList是邻接矩阵，n是端点数量,j是用来标记谁先被访问的
{
    if (out[v] == 0)
    {
        out[v] = j++; // 标记为已访问
    }
    Node* temp = adjList[v];
    while (temp)
    {
        if (!out[temp->vertex])
        {
            dfs_B(temp->vertex, out, n, j, adjList);
        }
        temp = temp->next;
    }
}

void solveB(int n, int m, int e[][2], int out[]) {
    Node** adjList; // 这是邻接链表，每一个点都有一个链表，里面存的是相邻的顶点信息
    adjList = (Node**)malloc(sizeof(Node*) * (n + 1));//节点1对应的邻接链表为adjList[1],而非[0]
    int* visited;
    visited = (int*)malloc(sizeof(int) * n);
    if (!visited) return;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    //设置已遍历数组
    int i, u, v;

    // 初始化邻接链表为有头节点的邻接链表
    for (i = 0; i <= n; i++) {
        adjList[i] = (Node*)malloc(sizeof(Node));
        adjList[i]->next = NULL;
    }

    // 构建邻接链表
    for (i = 0; i < m; i++) {
        u = e[i][0];
        v = e[i][1];
        Node* newNode = (Node*)malloc(sizeof(Node));
        Node* lastNode = adjList[u];//用于查找末尾节点
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        newNode->vertex = v;
        newNode->next = NULL;
        lastNode->next = newNode;//尾插法插入新节点(U->V这条边)


        newNode = (Node*)malloc(sizeof(Node));
        lastNode = adjList[v];
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        newNode->vertex = u;
        newNode->next = NULL;
        lastNode->next = newNode;//尾插法插入新节点(V->U这条边)
         // 因为是无向图,需要插入两次
    }

    for (int i = 0; i < n; i++)
    {
        adjList[i] = adjList[i]->next;
    }

    //设置未处理的out数组
    int* _out;
    _out = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        _out[i] = 0;
    }

    // 从顶点0开始DFS
    dfs_B(0, _out, n, 1, adjList);
    //这里输出的_out数组是"0,2,4,1,3"
    //意思是，第0个节点第一个被访问，第3个节点第二个被访问，第1个节点第三个被访问......
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (_out[j] == i)
            {
                out[num++] = j;
            }
        }
    }

}

int main()
{
    int e[5][2]= { {2,4},{3,0},{0,2},{3,1},{4,1} };
    int n = 5;
    int m = 5;
    int out[5] = { 0 };
    solveA(n, m, e, out);
    printf("solveA:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", out[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        out[i] = 0;
    }
    solveB(n, m, e, out);
    printf("solveB:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", out[i]);
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
