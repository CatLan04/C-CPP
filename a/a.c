#include<stdio.h>

typedef struct Node
{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root;

Node* makeNode(int id)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}
Node* Find(Node* r,int id)
{
    if (r == NULL) return NULL;
    if (r->id == id) return r;
    Node* p = Find(r->leftChild,id);
    if (p!=NULL) return p;
    return Find(r->rightChild,id);
}
void addLeft(int u, int left)
{
    Node* p = Find(root,u);
    if (p == NULL || p->leftChild != NULL) return;
    p->leftChild = makeNode(left);
}
void addRight(int u, int right)
{
    Node* p = Find(root,u);
    if (p == NULL || p->rightChild != NULL) return;
    p->rightChild = makeNode(right);
}
int ok = 0,sum = 0,targetsum;
void path(Node* r)
{
    if (r == NULL) return;
    if (ok == 1) return;
    sum+=r->id;
    //printf("%d %d\n",sum,r->id);
    if (!r->leftChild && !r->rightChild)
    {
        if (sum == targetsum) ok = 1;
        sum-=r->id;
        return;
    }
    path(r->leftChild);
    path(r->rightChild);
    sum-=r->id;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int u;
        scanf("%d",&u);
        if (root == NULL) root = makeNode(u);
        int l,r;
        scanf("%d%d",&l,&r);
        if (l > -1) addLeft(u,l);
        if (r > -1) addRight(u,r);
    }
    scanf("%d",&targetsum);
    path(root);
    printf("%d",ok);
}
/*
9
5 4 8
4 11 -1
8 13 3
11 7 2
13 -1 -1
3 -1 1
7 -1 -1
2 -1 -1
1 -1 -1
26
*/
