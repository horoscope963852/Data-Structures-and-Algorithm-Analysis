// 完成一个函数，用头插法建立带头节点的单链表，函数原型为：
//Node* CreatList(); 函数返回单链表头结点地址；
//Node的定义为：
//struct Node {
//    int data;
//    struct Node* next;
//};
//在CreatList里面输入整数，当输入 - 1时，表示单链表结束（注意， - 1不是单链表的数据元素）
//完成一个函数，判断带头节点的单链表中是否存在环。函数原型为：void IsCir(Node * first);
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则输出“true”。否则，输出“false”。注意：只需要提交这两个函数即可。

//#include <stdio.h>
//#include <malloc.h>
//struct Node 
//{
//    int data;
//    struct Node* next;
//};
//
//Node* CreatList()
//{
//    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    head->next = NULL;
//    int num=0;
//    while (num != -1)
//    {
//        if (scanf_s("%d", &num) == 0)
//        {
//            return NULL;
//        }
//        if (num != -1)
//        {
//            struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//            if (newnode == NULL)
//            {
//                return NULL;
//            }
//            newnode->next = head->next;
//            head->next = newnode;
//            newnode->data = num;
//        }
//        else
//        {
//            return head;
//        }
//    }
//}
//
//void IsCir(Node* first)
//{
//    if (first == NULL)
//    {
//        printf("false");
//        return;
//    }
//    first = first->next;
//    
//    while (first)
//    {
//        struct Node* P=first;
//        while (P->next)
//        {
//            P = P->next;
//            if (P == first)
//            {
//                printf("true");
//                return;
//            }
//        }
//        first = first->next;
//    }
//    printf("false");
//    return;
//}
//
//int Printlist(struct Node* head)
//{
//    struct Node* P = head->next;
//    while (P->next)
//    {
//        printf("%d  ", P->data);
//        P = P->next;
//    }
//    printf("%d  ", P->data);
//    printf("\n");
//    return 0;
//}
//
//int main()
//{
//    struct Node* head;
//    head= CreatList();
//    Printlist(head);
//
//}


//下面是chatgpt快慢指针



//Node* CreatList(); 函数返回单链表头结点地址；
//Node的定义为：
//struct Node {
//    int data;
//    struct Node* next;
//};
//在CreatList里面输入整数，当输入 - 1时，表示单链表结束（注意， - 1不是单链表的数据元素）
//完成一个函数，判断带头节点的单链表中是否存在环。函数原型为：void IsCir(Node * first);
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则输出“true”。否则，输出“false”。注意：只需要提交这两个函数即可。
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* CreatList()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        return NULL;
    }
    head->next = NULL;
    int num = 0;
    while (num != -1)
    {
        if (scanf_s("%d", &num) == 0)
        {
            return NULL;
        }
        if (num != -1)
        {
            struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
            if (newnode == NULL)
            {
                return NULL;
            }
            newnode->next = head->next;
            head->next = newnode;
            newnode->data = num;
        }
        else
        {
            return head;
        }
    }
}

void IsCir(Node* first) {
    Node* slow = first, * fast = first;

    while (fast && fast->next) {
        slow = slow->next;  // slow每次前进一步
        fast = fast->next->next;  // fast每次前进两步

        if (slow == fast) {
            printf("true");
            return;
        }
    }

    printf("false");
}

