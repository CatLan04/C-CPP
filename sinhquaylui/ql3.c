// Liet ke hoan vi
#include<stdio.h>
int n,m,a[10001],cx[10001];
void xuat()
{
    for (int i = 1; i <= n; i++)
        printf("%d",a[i]);
    printf("\n");
}
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    if (cx[j]==0)
    {
        a[i] = j;
        cx[j] = 1;
        if (i == n) xuat();
        else Try(i+1);
        cx[j] = 0;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) cx[i]=0;
    Try(1);
}