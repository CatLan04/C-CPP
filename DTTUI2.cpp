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
#define name

using namespace std;
const int mn=1e2+7;
const int oo=1e9+9;

typedef pair <int,int> ii;
ll n,m,s[mn],l[mn][10007],w[mn],c[mn];

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //freopen(name".INP","r",stdin);
     //freopen(name".OUT","w",stdout);
     cin>>n>>m;
     fo(i,1,n)cin>>w[i]>>c[i]>>s[i];
     fo(i,1,n)
     fo(j,1,m)
     {
         l[i][j]=l[i-1][j];
         if(j>=w[i])
         {
             fo(k,0,s[i])
             if(j>=k*w[i])l[i][j]=max(l[i][j],l[i-1][j-k*w[i]]+c[i]*k);
             else break;
         }
     }
     cout<<l[n][m];
     return 0;
}
