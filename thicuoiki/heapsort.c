#include<stdio.h>
typedef struct ds
{
    char name[256];
    char mail[256];
    int id;
} ds;
ds a[100001];
int n;
void swap(ds *a, ds *b)
{
    ds tmp = *a;
    *a = *b;
    *b = tmp;
    //strcpy(tmp,a->name);
    //strcpy(a,b);
    //strcpy(b,tmp);
}
void heapify(ds a[], int i, int n)
{
    int l = i*2;
    int r = i*2+1;
    int max = i;
    if (l <= n && strcmp(a[l].name,a[max].name)>0)
        max = l;
    if (r<= n && strcmp(a[r].name,a[max].name)>0)
        max = r;
    if (max!=i)
    {
        swap(&a[max],&a[i]);
        heapify(a,max,n);
    }
}
void buildHeap(ds a[], int n)
{
    for (int i = n/2; i >= 1; i--)
        heapify(a,i,n);
}
void heapSort()
{
    buildHeap(a,n);
    for (int i = n; i > 1; i--)
    {
        swap(&a[1],&a[i]);
        heapify(a,1,i-1);
    }
}
void insert(char* name, char* mail)
{
    int i = n-1;
    while(i >= 0)
    {
        int c = strcmp(a[i].name,name);
        if(c == 0)
        {
            printf("Name %s exists, do not insert\n",name);
            return;
        }
        else if(c > 0)
        {
            a[i+1] = a[i];
            i--;
        }
        else break;
    }
    i++;
    strcpy(a[i].name,name);
    strcpy(a[i].mail,mail);
    n++;
    printf("%d ",i);
}
int main()
{
    while (1)
    {
        char s1[256],s2[256];
        scanf("%s%s",s1,s2);
        if (!strcmp(s1,"NULL")&&!strcmp(s1,"NULL")) break;
        insert(s1,s2);
    }
}
/*
long long@
van van@
hoang hoang@
NULL NULL*/
