// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;

typedef  struct Node
{
    int data;
    Node *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    StackNode *top;
    int count = 0;
}LinkStack;

int push(LinkStack *S, int element)
{
    LinkStackPtr s = new Node;
    s->data = element;
    s->next = S->top;
    S->top = s;
    S->count++;

    return element;
}

int pop(LinkStack *S)
{
    int temp = 0;
    LinkStackPtr p;
    if ((S->count) <= 0)
    {
        cout << "栈空" << " ";
        return 0;
    }
    temp = S->top->data;
    p = S->top;
    S->top = S->top->next;
    delete p;
    S->count--;
    return temp;
}
int main()
{
    LinkStack linkStack;
    cout << "入栈10个元素" << endl;
    for (auto i = 0; i < 10; i++)
    {
        std::cout << push(&linkStack, i) << "  ";
    }
    cout << "\n";

    cout << "---分隔符---" << endl;
    cout << "出栈15个元素" << endl;
    for (auto i = 0; i < 15; i++)
    {
        cout << pop(&linkStack) << "  ";
    }
    cout << "\n";
    return 0;
}

