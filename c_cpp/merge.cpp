// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N=1e3+7;

typedef long long ll;
typedef pair<int,int> ii;

int m,n,c[N][N];
ll f[N][N][3];

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

void solve()
{
    f[1][1][0] = f[1][1][1] = c[1][1];
    fu(j,2,n)
    {
        f[1][j][1]=c[1][j];
        f[1][j][0]=min(f[1][j-1][0],f[1][j-1][1]+c[1][j]);
    }
    fu(i,2,m)
    {
        f[i][1][0]=c[i][1];
        f[i][1][1]=min(f[i-1][1][1],f[i-1][1][0]+c[i][1]);
    }
    fu(i,2,m)
    fu(j,2,n)
    {
        f[i][j][0]=min(f[i][j-1][0],f[i][j-1][1]+c[i][j]);
        f[i][j][1]=min(f[i-1][j][1],f[i-1][j][0]+c[i][j]);
    }
    cout<<min(f[m][n][0],f[m][n][1])<<'\n';
}

void ent()
{
int q;
    cin>>q;
    while(q--)
    {
        cin>>m>>n;
        fu(i,1,m)
        fu(j,1,n)
        cin>>c[i][j];
        solve();
    }
}

catlan()
{
#define name "merge"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    //solve();
}
