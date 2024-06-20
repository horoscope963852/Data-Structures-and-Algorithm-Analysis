// 联通分量个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//无向图G采用邻接矩阵存储，求其连通分量的个数。
//输入：
//第一行为一个整数n，表示顶点的个数（顶点编号为0到n - 1），
// 接下来是为一个n * n大小的整数矩阵，表示图的邻接关系，数字0表示不邻接，1表示邻接。
//输出：
//连通分量的个数。
//输入样例：
//5
//0 1 0 0 0
//1 0 1 0 0
//0 1 0 1 0
//0 0 1 0 0
//0 0 0 0 0
//输出：
//2

#include <stdio.h>

#define MAX_SIZE 100

int visited[MAX_SIZE];

void dfs(int graph[MAX_SIZE][MAX_SIZE], int n, int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int countComponents(int graph[MAX_SIZE][MAX_SIZE], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, n, i);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX_SIZE][MAX_SIZE];

    // 读取邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // 初始化visited数组
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // 计算连通分量个数
    int components = countComponents(graph, n);

    printf("%d\n", components);

    return 0;
}
