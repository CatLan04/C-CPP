// Liet ke to hop chap m cu n phan tu
#include<stdio.h>
int n,m,a[10001];
void xuat()
{
    for (int i = 1; i <= m; i++)
        printf("%d",a[i]);
    printf("\n");
}
void Try(int i)
{
    for (int j = a[i-1]+1; j <= n-m+i; j++)
    {
        a[i] = j;
        if (i == m) xuat();
        else Try(i+1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    Try(1);
}