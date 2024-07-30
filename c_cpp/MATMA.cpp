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
#define name "MATMA"

using namespace std;
const int mn=1e5+7;
const int oo=1e9+9;

typedef pair <int,int> ii;
string s;
int k;
int d[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".INP","r",stdin);
    freopen(name".OUT","w",stdout);
    cin>>k;
    int x=0;
    s=" ";
    fo(i,1,k)
    {

        int u;
        cin>>u;
        if(u==0)
        {
            x++;
            char tmp;
            cin>>tmp;
            s=s+tmp;
        }
      else
        {
            int r;
            cin>>r;
            string l=s.substr(x-u+1,r);
            s=s+l;
            x+=r;
        }
    }
    fo(i,1,x)
    {
        int j=int(s[i]-96);
        d[j]++;
    }
    int res=0;char t;
    fo(i,1,30)
    if(res<d[i])
    {
        res=d[i];
        t=char(i+96);
    }
    cout<<t<<res;
}
