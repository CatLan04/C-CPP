// author : Than Cat Ngoc Lan - Tink29CBG
// ʕง•ᴥ•ʔง
// Nekoran
#include <bits/stdc++.h>
using namespace std;
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define Fu(i,a) fu(i,0,a-1)
#define rep(i,a) for (auto i : (a))
#define Sz(a) (a.size())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define dao(a) reverse(all(a))
#define ER(a) a.resize(unique(all(a))-begin(a))
#define ll long long
//--------------------------------
// Bit
#define Bit(X,i) ((X>>i)&1)
#define On(X,i) (X|(1<<i))
#define Off(X,i) (X^(1<<i))
#define cnt_bit(X) __builtin_popcountll(X)
//--------------------------------
inline void read() {;}
template <typename H, typename ...T>
inline void read(H &x, T &...y)
{
	x = 0;
	char c = getchar();
	bool am = false;
	while (!isdigit(c)) am|=(c=='-'), c = getchar();
	while (isdigit(c))
		x = x*10 + c - '0', c = getchar();
	if (am) x = -x;
	read(y...);
}
//--------------------------------
// debug
inline void show(){;}
inline void prinf(int x) {cerr << x;}
inline void prinf(long x) {cerr << x;}
inline void prinf(float x) {cerr << x;}
inline void prinf(double x) {cerr << x;}
inline void pfinf(unsigned x) {cerr << x;}
inline void prinf(long long x) {cerr << x;}
inline void prinf(long double x) {cerr << x;}
inline void prinf(unsigned long long x) {cerr << x;}
inline void prinf(char x) {cerr << "\'" << x << "\'";}
inline void prinf(string x) {cerr << '\"' << x << '\"';}
inline void prinf(bool x) {cerr << (x ? "True" : "False");}
template<typename T, typename H>
inline void prinf(pair<T,H> x) {cerr<<"(";prinf(x.first);cerr<< ":";prinf(x.second);cerr<<")";}
template<typename T>
inline void prinf(T vec)
{
	int cnt = 0;
	cerr << "{";
	for (auto i : vec) cerr << (cnt++?",":""), prinf(i);
	cerr << "}";
}
template<typename Now, typename ...Next>
inline void show(Now now, Next ...next)
{
	prinf(now);
	if (sizeof ...(next)) cerr << ",";
	show(next...);
}
#define debug(x...) cerr<<"Line "<<__LINE__ <<": ["<<#x<<"] = [";show(x);cerr<<"]\n";
//---------------------------------
// random
mt19937_64 rd(chrono :: steady_clock :: now().time_since_epoch().count());
long long random(long long l, long long r) {return rd()%(r-l+1)+l;}
// time
inline void time() {cerr << "Time: " << clock()/1000.00 << "s\n";}
// min-max
template<typename T, typename H> inline bool maximize(T &a, H b) {if (a < b) {a=b;return true;} else return false;}
template<typename T, typename H> inline bool minimize(T &a, H b) {if (a > b) {a=b;return true;} else return false;}
//--------------------------------
const int N = 1e6+7;
const int M = 5e3+7;
const int oo = 1e9+7;
const ll inf = 1e18+7;
//--------------------------------
int n,m,p,k;
bool a[M][M];
string s;
void ent()
{
    cin >> m >> n >> p >> k;
    cin >> s;
    fu(i,1,p)
    {
        int x,y;
        cin >> x >> y;
        a[x][y] = true;
    }
}
namespace sub1
{
    void sol()
    {
        int mask = (1<<k)-1;
        int res = oo;
        for (int i = 0; i <= mask; i++)
        {
            int x,y;
            x = y = 1;
            for (int j = 0; j < k; j++)
                if (Bit(i,j))
            {
                if (s[j] == 'U'&&x>1) x-=1;
                if (s[j] == 'D'&&x<n) x+=1;
                if (s[j] == 'L'&&y>1) y-=1;
                if (s[j] == 'R'&&y<n) y+=1;
                if (a[x][y])
                {
                    if (s[j] == 'U') x+=1;
                    if (s[j] == 'D') x-=1;
                    if (s[j] == 'L') y+=1;
                    if (s[j] == 'R') y-=1;
                    break;
                }
            }
            if (x == m && y==n)
                res = min(res, cnt_bit(i));
        }
        if (res == oo) cout << "-1" <<'\n';
        else cout << k-res<<'\n';
    }
}
namespace sub3
{
    ll f[1001][1001][201],res;
    ll calc(int x, int y, int pos)
    {
        if (f[x][y][pos]!=-1) return f[x][y][pos];
        if (pos == k)
        {
            if (x == m && y == n)
                return 0;
            else return inf;
        }
        ll ans = 0, ans1 = 0;
        if (s[pos]=='U' && a[x-1][y] == 0 && x>1)
            ans = calc(x-1,y,pos+1);
        if (s[pos]=='D' && a[x+1][y] == 0 && x<n)
            ans = calc(x+1,y,pos+1);
        if (s[pos]=='L' && a[x][y-1] == 0 && y>1)
            ans = calc(x,y-1,pos+1);
        if (s[pos]=='R' && a[x][y+1] == 0 && y<n)
            ans = calc(x,y+1,pos+1);
        ans1 = calc(x,y,pos+1);
        f[x][y][pos] = min(ans1,ans+1);
        //debug(x,y,pos,f[x][y][pos]);
        return f[x][y][pos];
    }
    void sol()
    {
        memset(f,-1,sizeof(f));
        ll res = calc(1,1,0);
        cout << res <<'\n';
    }
}
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
	#define name ""
	freopen (name".inp", "r", stdin);
	freopen (name".out", "w", stdout);
    ent();
    if (k <= 20) sub1 :: sol();
    //sub3 :: sol();
	time();
}
