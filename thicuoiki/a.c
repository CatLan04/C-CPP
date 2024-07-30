#include <stdio.h>
typedef struct Node
{
    char key;
    struct Node* left;
    struct Node* right;
}Node;
Node* root;
Node* newNode(char val)
{
    //printf("%c",val);
    Node* p= (Node*)malloc(sizeof(Node));
    p->key=val;
    p->left=NULL;
    p->right=NULL;
    return p;
}
Node* buildBST(Node* r,char k)
{
    if(!r) {r=newNode(k);return r;}
    if(k==r->key) return r;
    if(k<r->key) r->left= buildBST(r->left,k);
    else r->right=buildBST(r->right,k);
    return r;
}
Node* findMin(Node* r)
{
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->left);
    if(lmin != NULL) return lmin;
    return r;
}
Node* findMin(Node* r)
{
    if(r == NULL) return NULL;
    while (r->left) r = r->left;
    return r;
}
Node* del(Node* r, char val)
{
    if(r == NULL) return NULL;
    if(val < r->key) r->left = del(r->left,val);
    else
        if(val > r->key) r->right = del(r->right,val);
    else
    {
        if(r->left != NULL && r->right != NULL)
        {
            Node* tmp = findMin(r->right);
            r->key=tmp->key;
            r->right = del(r->right,tmp->key);
        }
        else{
            Node* tmp = r;
            if(r->left == NULL) r = r->right;
            else r = r->left;
            free(tmp);
        }
    }
    return r;
}
void postOrder(Node* r)
{
    if(r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%c ",r->key);
}
int main()
{
    while(1)
    {
        char s[10];
        scanf("%s",s);
        if(strcmp(s,"#")==0) break;
        char n;
        scanf(" %c",&n);
        if(strcmp(s,"insert")==0) root= buildBST(root,n);
        if(strcmp(s,"del")==0) root=del(root,n);
    }
    if (!root) printf("NULL");
    else postOrder(root);
    return 0;
}
