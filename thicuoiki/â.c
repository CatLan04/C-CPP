#include<stdio.h>
typedef struct bo
{
    int ngay;
    char name[101];
    int sl;
} bo;
bo a[101];
typedef struct Node
{
    char name[101];
    int sl;
    struct Node* next;
}Node;
Node *b;
Node* makeNode(char x[], int sl)
{
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,x);
    p->sl = sl;
    p->next = NULL;
    return p;
}
Node* find(Node* r, char x[])
{
    Node *p = r;
    while (p!=NULL)
    {
        if (strcmp(p->name,x)==0) return p;
        p = p->next;
    }
    return p;
}
void swap(bo *a, bo *b)
{
    bo tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubleSort(bo a[], int n)
{
    int tmp = 0;
    while(tmp == 0)
    {
        tmp = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i].ngay > a[i+1].ngay)
            {
                swap(&a[i],&a[i+1]);
                tmp = 0;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d %s %d",&a[i].ngay,a[i].name,&a[i].sl);
    bubleSort(a,n);
    for (int i = 1; i <= n; i++)
        {
            if (b == NULL) b = makeNode(a[i].name,a[i].sl);
            else
            {
                Node *p = find(b,a[i].name);
                if (p == NULL) p = makeNode(a[i].name,a[i].sl);
                p->sl+=a[i].sl;
            }
        }
    while (b!=NULL)
    {
        printf("%s %d\n",b->name,b->sl);
        b = b->next;
    }
}
