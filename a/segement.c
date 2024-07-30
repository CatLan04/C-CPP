#include<stdio.h>

typedef struct Node
{
    char name[256];
    struct Node* leftChild;
    struct Node* rightSibling;
}Node;
Node *roof;

Node* makeNode(char *name)
{
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->leftChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* Find(Node* r, char *name)
{
    if (r == NULL) return NULL;
    if (strcmp(r->name,name)==0) return r;
    Node* p = r->leftChild;
    while(p != NULL)
    {
        Node* q = Find(p,name);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
}
Node* addLast(Node* p, char *name)
{
    if (p == NULL) return makeNode(name);
    p->rightSibling = addLast(p->rightSibling,name);
    return p;
}
void addChild(char *name, char * child)
{
    Node* r = Find(roof,name);
    if (r == NULL) return;
    //printf("%s %s\n",name,child);
    r->leftChild = addLast(r->leftChild,child);
}
void printfTree(Node* r)
{
    if (r == NULL) return;
    printf("%s: ",r->name);
    Node* p = r->leftChild;
    while (p!=NULL)
    {
        printf("%s ",p->name);
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
    printf("free node %s\n",r->name);
    free(r);
    r = NULL;
}
void processLoad()
{
    int d = 1;
    char cha[100];
    while(1)
    {
        char s[100];
        scanf("%s",s);
        if(strcmp(s,"$$")==0) break;
        if (d == 1) strcpy(cha,s);
        if (roof == NULL) roof = makeNode(cha);
        if (strcmp(s,"$")==0) d = 1;
        else
        {
            if(d!=1) addChild(cha,s);
            d++;
        }
    }
}
void processFind()
{
    char s[100];
    scanf("%s",s);
    Node *p = Find(roof,s);
    if (p == NULL)
        printf("Not Found %s\n",s);
    else
        printf("Found %s\n",s);
}
int main()
{
    while(1)
    {
        printf("Enter command: ");
        char s[100];
        scanf("%s",s);
        if (strcmp(s,"Quit")==0) break;
        else
            if (strcmp(s,"Load")==0) processLoad();
        else
            if (strcmp(s,"AddChild")==0)
            {
                char cha[100],child[100];
                scanf("%s%s",cha,child);
                addChild(cha,child);
            }
        else
            if (strcmp(s,"FindChild")==0)
            {
                char s[100];
                scanf("%s",s);
                Node *p = Find(roof,s);
                printf("%s: ",p->name);
                Node *q = p->leftChild;
                while(q!=NULL)
                {
                    printf("%s ",q->name);
                    q = q->rightSibling;
                }
                printf("\n");
            }
        else
            if (strcmp(s,"Print")==0)
            {
                printfTree(roof);
            }
        else
            if (strcmp(s,"Height")==0)
            {
                char s[100];
                scanf("%s",s);
                Node *p = Find(roof,s);
                printf("Found david having height = %d\n",height(p));
            }
        else
            if (strcmp(s,"Count")==0) printf("Number of members is %d\n",count(roof));
        else
            if (strcmp(s,"Find")==0) processFind();
    }
    freeTree(roof);
}
