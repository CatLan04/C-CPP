#include<stdio.h>
#include<string.h>
long long Pow[1000001];
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    Pow[0] = 1;
    for (int i = 1; i <= m; i++)
        Pow[i] = ((Pow[i-1]%m)*(256%m))%m;
    while(n--)
    {
        char s[201];
        scanf("%s",s);
        long long H = 0;
        int k = strlen(s);
        for (int i = 0; i < k; i++)
            {
                H += (s[i]%m*Pow[k - i - 1]%m)%m;
                H = H % m;
            }
        printf("%lld\n",H%m);
    }
    return 0;
}
