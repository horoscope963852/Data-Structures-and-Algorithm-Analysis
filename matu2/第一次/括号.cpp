// 括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编写一个函数，实现以下功能：
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//1.	左括号必须用相同类型的右括号闭合。
//2.	左括号必须以正确的顺序闭合。
//3.	每个右括号都有一个对应的相同类型的左括号。
//函数原型为：void isValid(const char* s)
//
//示例 1：
//当 s = "()"
//函数输出：true
//示例 2：
//当 s = "()[]{}"
//输出：true
//示例 3：
//当 s = "(]"
//输出：false
//提示：s不超过20个字符，错误输入，函数输出error
//只提交函数和相应的编译预处理指令，无需提交主函数

#include <stdio.h>
#include<malloc.h>
#include<string.h>

#define Maxsize 21

typedef struct
{
    char* base;
    char* top;
    int stacksize;
}Stack;

Stack* createstack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->base = (char*)malloc(sizeof(char) * Maxsize);
    s->top = s->base;
    s->stacksize = Maxsize;
    return s;
}//创建一个栈

int Push(Stack* s, char ch)
{
    *(s->top) = ch;
    s->top++;
    return 0;
}//压栈

int Pop(Stack* s, char* ch)
{
    *ch = *(s->top-1);
    s->top--;
    
    if (s->top < s->base)
        return -1;
    return 0;
}

int Destorystack(Stack* s)
{
    free(s->base);
    s->top = NULL;
    s->base = NULL;
    s->stacksize = 0;
    return 0;
}

//void isValid(const char* s)
//{
//    if (s == NULL)
//    {
//        printf("error");
//        return;
//    }
//    int len=strlen(s);
//    
//    if (len > 20)
//    {
//        printf("error");
//        return;
//    }
//    Stack* sta = createstack();
//    for (int n = 0; n < len; n++)
//    {
//        char ch;
//        ch = s[n];
//        if (ch == NULL)
//        {
//            break;
//        }
//        if (ch == '(' ||ch== '[' ||ch== '{')
//        {
//            Push(sta, ch);
//
//        }
//        else if (ch == ')' || ch == ']' || ch == '}')
//        {
//            char* ch_com=(char*)malloc(sizeof(char));
//            if (ch_com == NULL)
//            {
//                return;
//            }
//            if (Pop(sta, ch_com) == -1)
//            {
//                printf("false");
//                Destorystack(sta);
//                return;
//            }
//            if ((*ch_com == '(' && ch != ')') ||
//                (*ch_com == '[' && ch != ']') ||
//                (*ch_com == '{' && ch != '}'))
//            {
//                printf("false");
//                Destorystack(sta);
//                return;
//            }
//        }
//        else
//        {
//            printf("false");
//            return;
//        }
//    }
//    if (sta->top == sta->base)
//    {
//        printf("true");
//        return;
//    }
//    else
//    {
//        printf("false");
//        return;
//    }
//    Destorystack(sta);
//    return;
//}
#include <stdio.h>
#include<malloc.h>
#include<string.h>

void isValid(const char* s)
{
    if (s == NULL)
    {
        printf("error");
        return;
    }
    int len=strlen(s);
    if (len % 2 != 0)
    {
        printf("false");
        return;
    }
    if (len > 20)
    {
        printf("error");
        return;
    }
    char* ch;
    int top = 0;
    ch = (char*)malloc(sizeof(char)*len);
    for (int i = 0; i < len; i++)
    {
        if (*(s + i) == '(' || *(s + i) == '[' || *(s + i) == '{')
        {
            ch[top] = *(s + i);
            top++;
        }
        else
        {
            if (*(s + i) == ']' || *(s + i) == ')' || *(s + i) == '}')
            {
                if (top <= 0)
                {
                    printf("false");
                    return;
                }
                char ch_com;
                ch_com = ch[top-1];
                top--;
                if ((ch_com == '(' && *(s + i) != ')') ||(ch_com == '[' && *(s + i) != ']') ||(ch_com == '{' && *(s + i) != '}'))
                {
                    printf("false");
                    return;
                }
            }
            else
            {
                printf("false");
                return;
            }
        }
    }
    if (top != 0)
    {
        printf("false");
        return;
    }
    printf("true");
    return;
}

int main()
{
    const char* example1 = "))";
    const char* example2 = "()[]{}";
    const char* example3 = "(]";
    const char* example4 = "([)]";
    const char* example5 = "{}{{";

    isValid(example1);  // 输出: false
    isValid(example2);  // 输出: true
    isValid(example3);  // 输出: false
    isValid(example4);  // 输出: false
    isValid(example5);  // 输出: false

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
