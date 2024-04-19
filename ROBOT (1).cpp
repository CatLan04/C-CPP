#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ms(f,a) memset(f,a,sizeof f)
#define pb push_back
#define pf push_front
#define pb1 pop_back
#define pf1 push_front
#define fo(x,a,b) for(int x=a;x<=b;x++)
#define fo1(x,a,b) for(int x=a;x>=b;x--)
#define name "ROBOT"

using namespace std;
const int mn=1e5+7;
const int oo=1e9+9;

typedef pair <int,int> ii;

template <typename T> inline void read(T &x)
{
x=0;
    char c=getchar();
    int tmp=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
    {
        tmp*=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+int(c-48);
        c=getchar();
    }
    x*=tmp;
}

string s;
int n;

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen(name".INP","r",stdin);
     freopen(name".OUT","w",stdout);
     cin>>n;
     cin>>s;
     fo(i,0,n-1)
     if(s[i]!=s[n-i-1])
     {
         cout<<"KHONG";
         return 0;
     }
     cout<<"CO";
     return 0;
}
