#include<stdio.h>
#define N 100
int a[N],n,m;
int res;
int s = 0;
void Try(int i, int *p, int *cnt)
{
    for (int j = 1; j <= m/(*(p+i)); j++)
    {
        printf("i: %d j: %d\n",i,j);
        s+=*(p+i)*j;
        //printf("sum: %d\n",s);
        if (i == n)
        {
            printf("res: %d\n",s);
            if (s == m) {*cnt+=1;return;}
        }
        else Try(i+1,p,cnt);
        s-=*(p+i)*j;
        printf("sum quay: %d\n",s);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    res = 0;
    Try(1,&a,&res);
    printf("%d",res);
    return 0;
}
