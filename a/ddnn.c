#include<stdio.h>
// Tao vector
typedef struct Vector
{
    int v;
    int w;
    struct Node* sibling;
}Vector;
Vector* a[100000];
Vector* makeNodeV(int v, int w)
{
    Vector* p = (Vector*)malloc(sizeof(Vector));
    p->v = v;
    p->w = w;
    p->sibling = NULL;
    return p;
}
Vector* push_back(Vector* p, int v, int w)
{
    if (p == NULL) return makeNodeV(v,w);
    p->sibling = push_back(p->sibling,v,w);
}
Vector* Find(Vector* p, int v)
{
    if (p == NULL) return NULL;
    if (p->v == v) return p;
    while (p->sibling!=NULL)
    {
        Vector* q = Find(p->sibling,v);
        if (q!=NULL) return q;
        p = p->sibling;
    }
}
// Tao queue
typedef struct Node
{
    int u,v;
    int val;
    struct Node* next;
    struct Node* parent;
} Node;
Node *Head,*Tail;
int szlist = 0;
Node *listNode[100000];
Node* makeNode(int u, int v, int val, Node *parent)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->u = u;
    p->v = v;
    p->val = val;
    p->parent = parent;
    p->next = NULL;
}
void addList(Node *node)
{
    listNode[szlist] = node;
    szlist++;
}
void finalize()
{
    for (int i = 0; i < szlist; i++)
        free(listNode[i]);
}
int queueEmpty()
{
    return (Head==NULL&&Tail==NULL);
}
void pushQueue(Node* node)
{
    if (queueEmpty())
    {
        Head = node;
        Tail = node;
    }
    else
    {
        Tail->next = node;
        Tail = node;
    }
}
Node *popQueue()
{
    if (queueEmpty()) return NULL;
    Node *p = Head;
    Head = p->next;
    if (Head == NULL) Tail = NULL;
    return p;
}
Node *startNode,*finalNode;
int main()
{
    Head = NULL;
    Tail = NULL;
    int m,n;
    scanf("%d%d",&m,&n);
    for (int i = 1; i <= n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u] = push_back(a[u],v,w);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    while(a[s])
    {
        int v = a[s]->v;
        int w = a[s]->w;
        startNode = makeNode(s,v,w,NULL);
        addList(startNode);
        pushQueue(startNode);

    }
    while(!queueEmpty())
    {
        Node* p = popQueue();

        if (finalNode!=NULL) break;
    }
    Node *s = finalNode;
    while (s!=NULL)
    {
        printf("(%d,%d) ",s->x,s->y);
        s = s->parent;
    }
    //printf("%d",finalNode->step);
    finalize();
}
