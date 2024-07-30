#include <bits/stdc++.h>
#define fo(x,a,b) for(int x=a;x<=b;x++)
#define fo1(x,a,b) for(int x=a;x>=b;x--)
#define fi first
#define se second
#define ll long long
#define name

using namespace std;

const int mn=1e5+7;
const int oo= 1e9+7;
typedef pair <int,int> ii;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

int n,a[21],f[1000],l[1000];
int tr[1000];
map <int,int> m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin>>n;
    fo(i,1,20)a[i]=i*i;
    f[0]=1;
    fo(i,1,20)
    {
        fo(j,1,n)if(j>=a[i])f[j]+=f[j-a[i]];
    }
    int mm=f[n];
    fo(i,1,n)tr[i]=i;
    memset(l,oo,sizeof l);
    l[0]=0;
    fo(i,1,20)
    {
        fo(j,1,n)
        {
            if(j>=a[i])
            {
                if(l[j-a[i]]!=-1)
                {
                    if(l[j]>l[j-a[i]]+1)
                       {
                           l[j]=l[j-a[i]]+1;
                            tr[j]=i;
                       }
                }
            }
        }
    }
    int i=n;
    while(i!=0)
    {
        m[tr[i]]++;
        i-=tr[i]*tr[i];
    }
    cout<<m.size()<<endl;
    for(auto t:m)
        cout<<t.se<<" "<<t.fi<<endl;
    return 0;
}
