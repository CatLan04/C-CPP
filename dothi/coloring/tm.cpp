#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define Fu(i,a) fu(i,0,a-1)
#define rep(i,a) for (auto i : (a))
#define Sz(a) (a.size())
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
const int N=10001;
vector<int> a[N];
int n,m;
pair<int,int> b[N];
int mau[N];
double start,endd,use_time;
bool comp(pair<int,int> a,pair<int,int> b){
   return a.se > b.se;
}
void docdothi()
{
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
	#define name "gc_1000_9"
	freopen (name".txt", "r", stdin);
	freopen (name"tomau.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
	    int u,v;
	    cin >> u >> v;
	    a[u].pb(v);
	    a[v].pb(u);
	    b[u].se++;
	    b[v].se++;
	}
	fu(i,1,n) b[i].fi=i;
	sort(b+1,b+n+1,comp);
	/*fu(i,1,n) cout << b[i].fi << " " << b[i].se << "\n";
	fu(i,1,n)
	{
	    for (int j = 0; j<a[i].size(); j++)
            cout << a[i][j] << " ";
        cout << '\n';
	}*/
}
int main()
{

	start = clock();
	docdothi();
	int color = 0;
    while(1)
    {
        mau[b[1].fi]=++color;
        for (int i = 2; i <= n; i++)
        {
            int u = b[i].fi;
            int ok = 0;
            for (int j = 0; j < a[u].size(); j++)
                if (mau[a[b[i].fi][j]]==color)
                {
                    ok = 1;
                    break;
                }
            if (ok == 0)  mau[b[i].fi]=mau[b[1].fi];
        }
        for(int i = 1; i <= n; i++)
            if(mau[b[i].fi])
        {
            b[i].fi = 0;
            b[i].se = -100000;
            //xoa[b[i].fi]=1;
            for (int j = 0; j < a[b[i].fi].size(); j++)
                   b[a[b[i].fi][j]].se--;
        }

        sort(b+1,b+n+1,comp);
        //fu(i,1,n) cout << b[i].fi << " " << b[i].se << "\n";
        if (b[1].fi==0 && b[1].se==-100000) break;
    }
    cout << color << '\n';
    for (int i = 1; i <= n; i++) cout << mau[i] << '\n';
    endd = clock();
    use_time = (endd-start)/CLOCKS_PER_SEC;
    cout << use_time << '\n';
	return 0;

}
