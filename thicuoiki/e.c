#include<stdio.h>
typedef struct vec
{
    int v;
    int w;
    struct vec* next;
} vec;
vec *ke[100001];
typedef struct dequeue
{
    int v;
    int d;
} dequeue;
dequeue a[100001];
int d[100001];
int n,m,queue = 0;
int s,t;
void swap(dequeue *a, dequeue *b)
{
    dequeue tmp = *a;
    *a = *b;
    *b = tmp;
}
vec *newvec(int v, int w)
{
    vec* p = (vec*)malloc(sizeof(vec));
    p->v = v;
    p->w = w;
    p->next = NULL;
    return p;
}
void heapdown(dequeue a[], int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int min = i;
    if (l <= queue && a[l].d < a[min].d) min = l;
    if (r <= queue && a[r].d < a[min].d) min = r;
    if (min!=i)
    {
        swap(&a[i],&a[min]);
        heapdown(a,min);
    }
}
void heapup(int n)
{
    if (n <= 1) return;
    int parent = n/2;
    if (a[n].d < a[parent].d)
    {
        swap(&a[n],&a[parent]);
        heapup(parent);
    }
    return;
}
void push(int v, int d)
{
    queue++;
    a[queue].v = v;
    a[queue].d = d;
    heapup(queue);
}
dequeue pop()
{
    dequeue tmp = a[1];
    a[1] = a[queue];
    queue--;
    heapdown(a,1);
    return tmp;
}
void dijkstra()
{
    //printf("%d ",s);
    for (int i = 1; i <= n; i++) d[i] = 1000000;
    d[s] = 0;
    push(s,0);
    while (queue)
    {
        dequeue tmp = pop();
        //printf("%d",tmp.v);
        if (d[tmp.v]!=tmp.d) continue;
        int v = tmp.v;
        for (vec* x = ke[v]; x!=NULL; x = x->next)
        {
            int y = x->v;
            int w = x->w;
            //printf("%d %d %d\n",v,y,d[v]);
            if (d[y] > d[v]+w)
            {
                d[y] = d[v]+w;
                push(y,d[y]);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if (!ke[u]) ke[u] = newvec(v,w);
        else
        {
            vec* p = ke[u];
            while (p->next) p = p->next;
            p->next = newvec(v,w);
        }
    }
    scanf("%d%d",&s,&t);
    dijkstra();
    printf("%d",d[t]);
}


