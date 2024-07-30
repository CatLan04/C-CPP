// Liet ke xau nhi phan khong co 2 so 1 lien tiep
#include<stdio.h>
int n,a[10001];
void xuat()
{
    for (int i = 1; i <= n; i++)
        printf("%d",a[i]);
    printf("\n");
}
int check(int u,int v)
{
    if (a[u-1]==1&&v==1) return 0;
    return 1;
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    if (check(i,j))
    {
        a[i] = j;
        if (i == n) xuat();
        else Try(i+1);
    }
}
int main()
{
    scanf("%d",&n);
    Try(1);
}