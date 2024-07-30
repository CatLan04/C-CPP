#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Sinh xau khong co 2 phan tu 1 canh nhau

int main() {
    int n;
    int a[10000];
    scanf("%d", &n);
    a[0]=0;
    for(int i=1; i <= n; i++) a[i]=0;
    while(1)
    {
        for(int i=1; i <= n; i++) printf("%d",a[i]);
        printf("\n");
        int i = n;
        while (i>0)
        {
            if(a[i]==0&&a[i-1]==0)
            {
                a[i]=1;
                for (int j = i+1;j<=n;j++)
                    a[j] = 0;
                break;
            }
            i--;
        }
        if(i < 1) break;
    }
        return 0;
    }