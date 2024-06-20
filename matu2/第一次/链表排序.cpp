// 完成一个排序函数，将给定的单链表（不含头结点）按升序排列，并返回排序后的链表头指针。
//该函数的原型为：
//struct Node* SortList(struct Node* head);
//其中单链表的链点定义为：
//Node的定义为：
//struct Node {
//    int data;
//    struct Node* next;
//};
//注意，测试数据在创建单链表时，以 - 1为结束， - 1不属于单链表内容。

#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node* next;
};

//这个可以
struct Node* SortList(struct Node* head)
{
    struct Node* P = head;
    int count = 1;
    int num[1000];
    int n=0;
    int i,j,change;
    while (P->next != NULL)
    {
        count++;
        P = P->next;
    }
    
    P = head;
    for (i = 0; i < count; i++)
    {
        num[n] = P->data;
        P = P->next;
        n++;
    }//导出链表数据
    for (i = 1; i < count; i++)
    {
        for (j = 0; j < count - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                change = num[j];
                num[j] = num[j + 1];
                num[j + 1] = change;
            }
        }
    }//冒泡排序

    //
    //printf("\n\n");
    //for (int i = 0; i < count; i++)
    //{
    //    printf("%d  ", num[i]);
    //}
    //printf("\n\n");
    //
    //（冒泡排序正确）

    P = head;
    for (i = 0; i < count; i++)
    {
        P->data = num[i];
        P = P->next;
    }
    return head;
}

//换个思路：
//struct Node* SortList(struct Node* head)
//{
//    struct Node* P=head;
//    struct Node* Pmin=head;
//    struct Node* Pmin_com=head->next;
//    int i;
//    while (P != NULL)
//    {
//        Pmin = P;
//        Pmin_com = P->next;
//        while (Pmin_com)
//        {
//            if (Pmin_com->data < Pmin->data)
//            {
//                Pmin = Pmin_com;
//            }
//            if (Pmin_com->next == NULL)
//            {
//                break;
//            }
//            Pmin_com = Pmin_com->next;
//        }
//        i = Pmin->data;
//        Pmin->data = P->data;
//        P->data = i;
//        
//        P = P->next;
//    }
//    return head;
//}

int add(struct Node* head, int data0, int num)
{
    struct Node* P=head;
    for (int i = 0; i < num-1; i++)
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
    struct Node* P = head;
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
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        printf("error");
        return 0;
    }
    head->next = NULL;
    head->data = 11;
    for (int i = 0; i < 10; i++)
    {
        add(head, 10 - i, i + 1);
    }
    Printlist(head);
    SortList(head);
    Printlist(head);
}


// 
//逻辑有问题
//struct Node* SortList(struct Node* head)
//{
//    struct Node* P=head;
//    struct Node* Plast;
//    int count = 1;
//    while (P->next != NULL)
//    {
//        count++;
//        P = P->next;
//    }
//    Plast = P;//Plast是最后一个节点的指针，用于后面把最大值移至末尾
//    struct Node* Pmax_last=NULL;//上次循环遍历得到的最大值,初始设为NULL
//    for (int i = 0; i < count - 2; i++)
//    {
//        struct Node* Pmax;//遍历最大值
//        struct Node* Pmax_before=NULL;//最大值的前一个节点
//        P = head;
//        Pmax = P;
//        for (int j = 0; j < count - i; j++)
//        {
//            if (Pmax->data < P->next->data)
//            {
//                Pmax = P->next;
//                Pmax_before = P;
//            }
//            P = P->next;
//        }
//        if (Pmax_before == NULL)//证明此时的最大值是第一个节点
//        {
//            Plast->next = Pmax;
//            Pmax->next = Pmax_last;
//        }
//        else//此时最大值不是第一个节点
//        {
//            Pmax_before->next = Pmax->next;//保持原本链表完整！
//            Plast->next = Pmax;
//            Pmax->next = Pmax_last;
//        }
//        Pmax_last = Pmax;//更新“上次循环遍历得到的最大值”
//    }
//    return 
//}

