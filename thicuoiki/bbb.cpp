#include <iostream>
#include <cmath>
using namespace std;
double silnia(int n)
{
    int k=1;
    if(n==0 || n==1) return 1;
    else{
    for(int i=1;i<=n;i++)
    {
        k*=i;
    }
    return k;
    }
}

int main()
{
    int n=1;
    double e=0;
    while (n>10)
    {
        e+=1/silnia(n);
        n++;
    }
    cout<<e;
    return 0;
}
