// 链表合并.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编写一个函数，合并两个带头结点的递增有序单链表，合并后的单链表保持递增有序性。函数原型为：
//Node* merge_sorted_lists(Node* head1, Node* head2)，即合并单链表head1和单链表head2，返回合并后的单链表的头结点地址；
//编写一个函数，实现对带头结点的单链表排序，排序算法为简单选择法，函数原型为：
//void  List_sort(Node* head)，即对单链表head进行排序；
//结点数据定义为：
//struct Node {
//    int data;
//    struct Node* next;
//};

#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node* next;
};

void List_sort(struct Node* head)
{
    if (head == NULL)
    {
        printf("error");
        return;
    }
    struct Node* P=head->next;
    struct Node* Pmin=head->next;
    struct Node* Pmin_com=head->next->next;
    int i;
    while (P != NULL)
    {
        Pmin = P;
        Pmin_com = P->next;
        while (Pmin_com)
        {
            if (Pmin_com->data < Pmin->data)
            {
                Pmin = Pmin_com;
            }
            if (Pmin_com->next == NULL)
            {
                break;
            }
            Pmin_com = Pmin_com->next;
        }
        i = Pmin->data;
        Pmin->data = P->data;
        P->data = i;
        
        P = P->next;
    }
}

Node* merge_sorted_lists(Node* head1, Node* head2)
{
    Node* first = (Node*)malloc(sizeof(Node));
    if (!first)
    {
        return NULL;
    }
    Node* p = first;
    Node* p1 = head1->next;
    Node* p2 = head2->next;
    while (p1!= NULL && p2!= NULL)
    {
        if (p1->data > p2->data)
        {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        else
        {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
    }
    if (p1== NULL)
    {
        p->next = p2;
    }
    else
    {
        p->next = p1;
    }
    return first;
}

int add(struct Node* head, int data0, int num)
{
    struct Node* P = head;
    for (int i = 0; i < num - 1; i++)
    {
        P = P->next;
    }//此时P是要插入位置的前一个位置
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("error");
        return -1;
    }
    newnode->data = data0;
    newnode->next = P->next;
    P->next = newnode;
    return 0;
}

int Printlist(struct Node* head)
{
    struct Node* P = head->next;
    while (P->next)
    {
        printf("%d  ", P->data);
        P = P->next;
    }
    printf("%d  ", P->data);
    printf("\n");
    return 0;
}

int main()
{
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    if (head1 == NULL)
    {
        printf("error");
        return 0;
    }
    if (head2 == NULL)
    {
        printf("error");
        return 0;
    }
    head1->next = NULL;
    head2->next = NULL;
    for (int i = 0; i < 10; i++)
    {
        add(head2, i, i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        add(head1, i+10, i + 1);
    }
    Printlist(head1);
    Printlist(head2);
    Node* first=merge_sorted_lists(head1, head2);
    Printlist(first);
}
