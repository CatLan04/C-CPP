#include<stdio.h>
typedef struct Node
{
    char c;
    struct Node* next;
}Node;
Node* sh1top, *sh2top, *sumtop;
void initStack()
{
    sh1top = NULL;
    sh2top = NULL;
    sumtop = NULL;
}
int stackEmpty(Node *top)
{
    return (top == NULL);
}
Node* makeNode(char x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x;
    p->next = NULL;
    return p;
}
Node* push(char x,Node *top)
{
    Node* p = makeNode(x);
    p->next = top;
    top = p;
    return top;
}
Node* pop(Node *top,char *x)
{
    if (!top) return NULL;
    *x = top->c;
    Node* tmp = top;
    top = top->next;
    free(tmp);
    return top;
}
int main()
{
    initStack();
    char c;
    while (1)
    {
        c = getchar();
        if (c == '\n') break;
        sh1top = push(c,sh1top);
    }
    while (1)
    {
        c = getchar();
        if (c == '\n') break;
        sh2top = push(c,sh2top);
    }
    int nho = 0;
    while(sh1top)
    {
        char x,y;
        sh1top = pop(sh1top,&x);
        //printf("%c ",x);
        if (!sh2top) y = '0';
        else
        {
            sh2top = pop(sh2top,&y);
        }
        int t;
        t = x + y - 96 + nho;
        nho = t/10;
        sumtop = push(t%10+48,sumtop);
    }
    if (nho) sumtop = push('1',sumtop);
    while(sumtop)
    {
        char x;
        sumtop = pop(sumtop,&x);
        printf("%c",x);
    }
    return 0;
}

