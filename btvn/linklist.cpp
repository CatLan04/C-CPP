#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
Node *start,*last;
void inlist()
{
    start = NULL;
    last = NULL;
}
int listempty()
{
    return (start == NULL && last == NULL);
}
Node* makeNode(int v)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    return p;
}
void build(int v)
{
    Node *p = makeNode(v);
    if (listempty()) start = p,last = p;
    else
    {
        last->next = p; last = p;
    }
}
void printfList()
{
    for (Node* p = start; p!=NULL; p=p->next)
    {
        printf("%d ",p->val);
    }
    printf("\n");
}
void addlast(Node* h, int v)
{
    Node *p = h;
    while (h == NULL)
    {
        Node* q = makeNode(v);
        h->next = q;
    }
    while (p!=NULL)
    {
        if (p->val == v) return;
        p = p->next;
    }
    p = makeNode(v);
    last->next = p;
    last = p;
}
void addfirst(Node* h, int v)
{
    while (h == NULL)
    {
        Node* q = makeNode(v);
        h->next = q;
    }
    Node* p=h;
    while (p!=NULL)
    {
        if (p->val == v) return;
        p = p->next;
    }
    Node* q=makeNode(v);
    q->next = h;
    start = q;
}
void addafter(Node* h, int u, int v)
{
    Node* p=h;
    int ok = 0;
    while (p!=NULL)
    {
        if (p->val == u) return;
        if (p->val == v) ok = 1;
        p = p->next;
    }
    if (ok==0) return;
    while (h->val!=v)
    {
        h = h->next;
    }
    Node* q = makeNode(u);
    q->next = h->next;
    h->next = q;
}
void addbefore(Node* h, int u, int v)
{
    Node* p=h;
    int ok = 0;
    while (p!=NULL)
    {
        if (p->val == u) return;
        if (p->val == v) ok = 1;
        p = p->next;
    }
    if (ok==0) return;
    if (h->val==v)
    {
        Node* q = makeNode(u);
        q->next = h;
        start = q;
        return;
    }
    while (h->next->val!=v)
    {
        h = h->next;
    }
    Node* q = makeNode(u);
    q->next = h->next;
    h->next = q;
}
void removeKey(Node* h,int k)
{
    Node* p = h;
    int ok = 0;
    while (p!=NULL)
    {
        if (p->val == k) {ok = 1;break;}
        p = p->next;
    }
    if (ok==0) return;
    if (h->val == k)
    {
        start = h->next;
        free(h);
        return;
    }
    int dd = 0;
    while(h->next->val!=k)
    {
        h = h->next;
        if(h->next->next==NULL) last = h;
    }
    Node* q=h->next;
    h->next = h->next->next;
    free(q);
}
void reverseList(Node *h) {
	if(!h)		return;
	if(!h->next) return;
	Node *p = h;
	h = h->next;
	p->next = NULL;
	while(h->next) {
		Node *Next = h->next;
		h->next = p;
		p = h;
		h = Next;
	}
	h->next = p;
	start = h;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        build(a);
    }
    string query;
	while(cin >> query) {
		int k,u,v;
		if(query =="#")break;
		if(query == "addlast") {
			cin >> k;
			addlast(start,k);
			//printfList();
		}
		if(query == "addfirst") {
			cin >> k;
			addfirst(start,k);
			//printfList();
		}
		if(query == "addafter") {
			cin >> u >> v;
			addafter(start,u,v);
			//printfList();
		}
		if(query == "addbefore") {
			cin >> u >> v;
			addbefore(start,u,v);
			//printfList();
		}
		if(query == "remove") {
			cin >> k;
			removeKey(start,k);
			//printfList();
		}
		if(query == "reverse") {
			reverseList(start);
			//printfList();
		}
	}

    printfList();
}
