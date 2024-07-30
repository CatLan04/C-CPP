#include <stdio.h>
#include <string.h>
const long long modulo = 1e9 + 7;
long long M[1001][1001]={0};
int k,n;
long long C(int k, int n)
{
    if (k == n || k == 0) M[k][n] = 1;
    else
        if (M[k][n] == 0)
            M[k][n] = (C(k-1,n-1)%modulo + C(k,n-1)%modulo)%modulo;
    return M[k][n];
}
int main()
{
    scanf("%d%d",&k,&n);
    printf("%lld",C(k,n));
    return 0;
}
