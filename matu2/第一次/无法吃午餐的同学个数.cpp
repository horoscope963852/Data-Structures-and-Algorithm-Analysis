// 无法吃午餐的同学个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编写C函数实现如下功能：
//学校的自助午餐提供圆形和方形的三明治，分别用数字0和1表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。
//所有三明治都放在一个栈里，每一轮：
//•	如果队列最前面的学生喜欢栈顶的三明治，那么会拿走它并离开队列。
//•	否则，这名学生会 放弃这个三明治 并回到队列的尾部。
//这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。
//给你两个整数数组students和sandwiches ，其中 sandwiches[i] 是栈里面第i个三明治的类型（i = 0 是栈的顶部
//students[j]是初始队列里第 j 名学生对三明治的喜好（j = 0 是队列的最开始位置）。请你返回无法吃午餐的学生数量。
//当三明治的数量小于学生数量时，一定有学生无法吃午餐。
//函数原型为：
//int countStudentsnew(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
//students：学生数组；
//studentsSize：学生人数；
//sandwiches：三明治数组；
//sandwichesSize：三明治数量；
//返回值：无法吃午餐的学生人数；
//示例 1：
//输入：students = [1, 1, 0, 0], sandwiches = [0, 1, 0, 1]
//函数返回：0
//解释：
//- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1, 0, 0, 1]。
//- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0, 0, 1, 1]。
//- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [0, 1, 1]，三明治栈为 sandwiches = [1, 0, 1]。
//- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1, 1, 0]。
//- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1, 0]，三明治栈为 sandwiches = [0, 1]。
//- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0, 1]。
//- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1]，三明治栈为 sandwiches = [1]。
//- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = []，三明治栈为 sandwiches = []。
//所以所有学生都有三明治吃，返回0；
//示例 2：
//输入：students = [1, 1, 1, 0, 0, 1], sandwiches = [1, 0, 0, 0, 1, 1]
//函数返回：3
//提示：
//学生人数和三明治的都数量不超过50；
//只需要提交函数、用到的的数据结构定义，编译预处理命令等内容，不要提交主函数

//#include <stdio.h>
//#include<malloc.h>
//#define maxsize 50
//typedef struct Node {
//    int data;
//    Node* next;
//}Node;
//
//typedef struct queue {
//    Node* first;
//    Node* last;
//    //一个头指针，一个末指针，一开始需要malloc一个新节点，让first和last都指向它
//}queue;
//
//int enqueue(queue* que, int num)
//{
//    Node* p = (Node*)malloc(sizeof(Node));
//    if (p == NULL)
//    {
//        return 0;
//    }
//    //分配一个新节点
//    p->data = num;
//    p->next = NULL;
//    //赋值
//    que->last->next = p;
//    //加入队尾
//    que->last = p;
//    //调整队列的末指针位置
//    return 0;
//}
//
//int dequeue(queue* que, int* num)
//{
//    if (que->last == que->first)
//    {
//        printf("error0 ");
//        return -1;
//    }
//    //判断是否为空队列
//    Node* p = que->first->next;
//    //先设一个工作指针，指向要提取值的“第一个有效节点”
//    *num = p->data;
//    //提取值
//    que->first->next = p->next;
//    //把队头指向第二个有效节点
//    if (p->next == NULL)
//    {
//        que->first = que->last;
//    }
//    //如果只有一个有效节点的话，需要改变末尾指针的位置，其他情况下不用
//    free(p);
//    //把刚刚提取了值的节点free
//    return 0;    
//}
//
////上面是队列的定义部分
//
////下面是栈的定义部分
//
//typedef struct Stack {
//    int data[maxsize];
//    int top;
//}stack;
////初始化栈的时候需要令top=-1
//
//int pop(stack* sta, int* x)
//{
//    if (sta->top < 0)
//    {
//        printf("error1 ");
//        return -1;
//    }
//    //判断是否下溢
//    *x = sta->data[sta->top];
//    sta->top--;
//    return 0;
//}
//
//int push(stack* sta, int x)
//{
//    if (sta->top >= maxsize-2)
//    {
//        printf("error2 ");
//        return -1;
//    }
//    //判断是否上溢
//    sta->top++;
//    sta->data[sta->top] = x;
//    return 0;
//}
//
////下面是正经栈和队列
//int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
//{
//    Node* one;
//    one = (Node*)malloc(sizeof(Node));
//    queue* stu;
//    stu = (queue*)malloc(sizeof(queue));
//    stu->first = one;
//    stu->last = one;
//    for (int i = 0; i < studentsSize; i++)
//    {
//        enqueue(stu, *(students + i));
//    }
//
//    int i = 0;
//    while (sandwichesSize != 0)
//    {
//        int com;
//        int count = 0;//count用来判断是否循环了整个队列
//    loop:
//        if (count == studentsSize)
//        {
//            break;
//        }//如果count＝学生人数，那就循环了整个队列
//        dequeue(stu, &com);
//        if (com == sandwiches[i])
//        {
//            sandwichesSize--;
//            studentsSize--;
//            i++;
//            continue;
//        }
//        else
//        {
//            enqueue(stu, com);
//            count++;//每次判断一个学生那就count++
//
//            goto loop;
//        }
//    }
//    return studentsSize;
//}
//int main()
//{
//    int students[6] = { 1,1,1,0,0,1 };
//    int sandwiches[6] = { 1,0,0,0 ,1,1};
//    int studentnum =6;
//    int sandwichnum = 6;
//    int count = countStudents(students, studentnum, sandwiches, sandwichnum);
//    printf("%d", count);
//}

//下面是流氓算法（不用栈和队列）
//#include<stdio.h>
//int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
//{
//    int j = 0;
//    for (int i = 0; i < sandwichesSize;i++)
//    {
//        int point = j;
//        //point用于存储这一次循环的开始位置，如果循环了一圈的话，那就结束
//        loop:
//        if (j == studentsSize)
//        {
//           j = 0;
//        }
//        //如果到了队列尾，那就返回队列头部
//        if (sandwiches[i] == students[j])
//        {
//            students[j] = -1;
//            sandwiches[i] = -1;
//            j++;
//            continue;
//        }
//        //如果学生和三明治的标签一样，那就都赋值为-1，意思是人和三明治一起滚蛋了
//        j++;
//        if (j == point)
//        {
//            break;
//        }
//        //point用于存储这一次循环的开始位置，如果point=j，那就循环了一圈，结束，开始统计
//        goto loop;
//    }
//    int count=0;
//    for (int i = 0; i < studentsSize; i++)
//    {
//        if (*(students + i) == 0 || *(students + i) == 1)
//        {
//            count++;
//        }
//    }
//    //统计没饭吃的人数
//    return count;
//}





#include <stdio.h>
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
{
    int uneat = studentsSize;
    int top = 0;//栈顶
    int front = 0, rear = studentsSize - 1;//队头和队尾
    int count = 0;
    while (1)
    {
        if (students[front] != sandwiches[top])
        {
            front = (front + 1) % studentsSize;
            rear = (rear + 1) % studentsSize;
            if (students[front] == -1)
            {
                while (students[front] == -1)
                {
                    front = (front + 1) % studentsSize;
                    //printf("c");
                    if (front == rear) {
                        break;
                    }
                }
            }
            if (students[rear] == -1)
            {
                while (students[rear] == -1)
                {
                    rear = (rear + 1) % studentsSize;
                    //printf("c");
                    if (front == rear) {
                        break;
                    }
                }
            }
        }
        if (students[front] == sandwiches[top])
        {
            uneat--;
            top++;
            students[front] = -1;
            if (front == rear) {
                break;
            }
            front = (front + 1) % studentsSize;
        }
        if (top == sandwichesSize) { break; }
        count++;
        if (count > studentsSize) {
            break;
        }
    }
    return uneat;
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
