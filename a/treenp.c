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
void inOrder(Node* r)
{
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%d ",r->id);
    inOrder(r->rightChild);
}
void preOrder(Node* r)
{
    if(r == NULL) return;
    printf("%d ",r->id);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
void postOrder(Node* r)
{
    if(r == NULL) return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
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
            if (strcmp(s,"AddLeft") == 0)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                addLeft(v,u);
            }
        else
            if (strcmp(s,"AddRight") == 0)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                addRight(v,u);
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
