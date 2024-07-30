#include<stdio.h>
#include<string.h>
void reverse(char a[],int n)
{
    int l = 0, r = n-1;
    while (l<r)
    {
        char tmp;
        tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        ++l; r--;
    }
}
//Quy dinh a lon hon
void add(char a[], char b[])
{
    int n1=strlen(a); int n2=strlen(b);
    int z[n1+3];
    reverse(a,n1);reverse(b,n2);
    // printf("%s %s",a, b);
    for (int i = n2; i <n1; i++) b[i]='0';
    int nho = 0, n=0;
    for (int i = 0; i < n1; i++)
    {
        int tmp = a[i]+b[i]-96+nho;
        nho = tmp/10;
        tmp = tmp%10;
        z[++n] = tmp;
    }
    if(nho==1) z[++n]=1;
    for (int i = n; i>=1; i--) printf("%d",z[i]);
}
int main()
{
    char c[100],d[100];
    scanf("%s %s",c,d);
    if (strlen(c)>strlen(d)) add(c,d);
    else add(d,c);
    return 0;
}