// Liet ke xau nhi phan do dai n
#include<stdio.h>
int n,a[10001];
void xuat()
{
    for (int i = 1; i <= n; i++)
        printf("%d",a[i]);
    printf("\n");
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
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