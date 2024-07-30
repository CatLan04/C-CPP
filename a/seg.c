#include<stdio.h>

typedef struct Node
{
    int id;
    struct Node* leftChild;
    struct Node* rightSibling;
}Node;
Node *root;

Node* makeNode(int id)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* Find(Node* r, int id)
{
    if (r == NULL) return NULL;
    if (r->id == id) return r;
    Node* p = r->leftChild;
    while(p != NULL)
    {
        Node* q = Find(p,id);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
}
Node* addLast(Node* p, int id)
{
    if (p == NULL) return makeNode(id);
    p->rightSibling = addLast(p->rightSibling,id);
    return p;
}
void addChild(int u, int child)
{
    Node* r = Find(root,u);
    if (r == NULL) return;
    //printf("%s %s\n",name,child);
    r->leftChild = addLast(r->leftChild,child);
}
void printfTree(Node* r)
{
    if (r == NULL) return;
    printf("%s: ",r->id);
    Node* p = r->leftChild;
    while (p!=NULL)
    {
        printf("%s ",p->id);
        p = p->rightSibling;
    }
    printf("\n");
    p = r->leftChild;
    while (p!=NULL)
    {
        printfTree(p);
        p = p->rightSibling;
    }
}
int height(Node* p)
{
    if (p == NULL) return 0;
    int maxH = 0;
    Node* q = p->leftChild;
    while(q!=NULL)
    {
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}
int count(Node* p)
{
    if (p == NULL) return 0;
    int cnt = 1;
    Node* q = p->leftChild;
    while(q!=NULL)
    {
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}
void freeTree(Node* r)
{
    if (r == NULL) return;
    Node *p = r->leftChild;
    while(p!=NULL)
    {
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }
    printf("free node %s\n",r->id);
    free(r);
    r = NULL;
}
void inOrder(Node* r)
{
    if(r == NULL) return;
    Node* p = r->leftChild;
    inOrder(p);
    printf("%d ",r->id);
    if(p != NULL)
    p = p->rightSibling;
    while(p != NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
}
void preOrder(Node* r)
{
    if(r == NULL) return;
    printf("%d ",r->id);
    Node* p = r->leftChild;
    while (p!=NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}
void postOrder(Node* r)
{
    if(r == NULL) return;
    Node* p = r->leftChild;
    while (p!=NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ",r->id);
}
int main()
{
    while (1)
    {
        char s[100];
        scanf("%s",s);
        if (strcmp(s,"*") == 0) break;
        else
            if (strcmp(s,"MakeRoot") == 0)
            {
                int u;
                scanf("%d",&u);
                root = makeNode(u);
            }
        else
            if (strcmp(s,"Insert") == 0)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                addChild(v,u);
            }
        else
            if (strcmp(s,"PreOrder") == 0)
            {
                preOrder(root);
                printf("\n");
            }
        else
            if (strcmp(s,"InOrder") == 0)
            {
                inOrder(root);
                printf("\n");
            }
        else
            if (strcmp(s,"PostOrder") == 0)
            {
                postOrder(root);
                printf("\n");
            }
    }
    return 0;
}


