#include<stdio.h>
#include<string.h>
long long Pow[1000001];
typedef struct Node
{
    long long key;
    int cnt;
    char ss[100001];
    struct Node* left;
    struct Node* right;
} Node;
Node* r;
Node* newNode(long long val, char s[100001])
{
    Node* p= (Node*)malloc(sizeof(Node));
    p->key=val;
    p->cnt = 1;
    strcpy(p->ss,s);
    p->left=NULL;
    p->right=NULL;
    return p;
}
Node* buildBST(Node* r,long long k,char s[100001])
{
    if(!r) {r=newNode(k,s);return r;}
    if(k==r->key) return r;
    if(strcmp(s,r->ss)<1) r->left= buildBST(r->left,k,s);
    else r->right=buildBST(r->right,k,s);
    return r;
}
Node* find(Node* r,long long k)
{
    if(!r) return r;
    if(k==r->key) return r;
    if(k<r->key) return find(r->left,k);
    else return find(r->right,k);
}
int check(char a)
{
    return ((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'));
}
void inorder(Node *r)
{
    if (!r) return NULL;
    inorder(r->left);
    printf("%s %d\n",r->ss,r->cnt);
    inorder(r->right);
}
int main()
{
    int m = 997;
    Pow[0] = 1;
    for (int i = 1; i <= 100001; i++)
        Pow[i] = ((Pow[i-1]%m)*(31%m))%m;
    char s[100002];
    scanf("%[^\n]s",s);
    int n = strlen(s);
    long long H = 0;
    char word[100001];
    int end = 0;
    for (int i = 0; i <= n; i++)
    {
        if (!check(s[i]))
        {
            //printf("%d\n",H);
            Node *p = find(r,H);
            if (!p)
            r = buildBST(r,H,word);
            else p->cnt++;
            H = 0;
            end = 0;
        }
        else
        {
            H += (s[i]%m*Pow[n - end - 1]%m)%m;
            H = H % m;
            word[end++] = s[i];
        }
    }
    inorder(r);
}
