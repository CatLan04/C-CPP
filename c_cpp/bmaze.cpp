// author : Than Cat Ngoc Lan - Tink29CBG
// ʕง•ᴥ•ʔง
// Nekoran
#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define Fu(i, a) fu(i, 0, a - 1)
#define rep(i, a) for (auto i : (a))
#define Sz(a) (a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define dao(a) reverse(all(a))
#define ER(a) a.resize(unique(all(a)) - begin(a))
#define ll long long
//--------------------------------
// Bit
#define Bit(X, i) ((X >> i) & 1)
#define On(X, i) (X | (1 << i))
#define Off(X, i) (X ^ (1 << i))
#define cnt_bit(X) __builtin_popcountll(X)
//--------------------------------
inline void read() { ; }
template <typename H, typename... T>
inline void read(H &x, T &... y) {
    x = 0;
    char c = getchar();
    bool am = false;
    while (!isdigit(c)) am |= (c == '-'), c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (am)
        x = -x;
    read(y...);
}
//--------------------------------
// debug
inline void show() { ; }
inline void prinf(int x) { cerr << x; }
inline void prinf(long x) { cerr << x; }
inline void prinf(float x) { cerr << x; }
inline void prinf(double x) { cerr << x; }
inline void pfinf(unsigned x) { cerr << x; }
inline void prinf(long long x) { cerr << x; }
inline void prinf(long double x) { cerr << x; }
inline void prinf(unsigned long long x) { cerr << x; }
inline void prinf(char x) { cerr << "\'" << x << "\'"; }
inline void prinf(string x) { cerr << '\"' << x << '\"'; }
inline void prinf(bool x) { cerr << (x ? "True" : "False"); }
template <typename T, typename H>
inline void prinf(pair<T, H> x) {
    cerr << "(";
    prinf(x.first);
    cerr << ":";
    prinf(x.second);
    cerr << ")";
}
template <typename T>
inline void prinf(T vec) {
    int cnt = 0;
    cerr << "{";
    for (auto i : vec) cerr << (cnt++ ? "," : ""), prinf(i);
    cerr << "}";
}
template <typename Now, typename... Next>
inline void show(Now now, Next... next) {
    prinf(now);
    if (sizeof...(next))
        cerr << ",";
    show(next...);
}
#define debug(x...)                                        \
    cerr << "Line " << __LINE__ << ": [" << #x << "] = ["; \
    show(x);                                               \
    cerr << "]\n";
//---------------------------------
// random
mt19937_64 rd(chrono ::steady_clock ::now().time_since_epoch().count());
long long random(long long l, long long r) { return rd() % (r - l + 1) + l; }
// time
inline void time() { cerr << "Time: " << clock() / 1000.00 << "s\n"; }
// min-max
template <typename T, typename H>
inline bool maximize(T &a, H b) {
    if (a < b) {
        a = b;
        return true;
    } else
        return false;
}
template <typename T, typename H>
inline bool minimize(T &a, H b) {
    if (a > b) {
        a = b;
        return true;
    } else
        return false;
}
//--------------------------------
const int N = 1e3 + 7;
const int M = 1e3 + 7;
const int mod = 1e9 + 7;
const ll inf = 1e18 + 7;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
#define ll long long
int m, n, k;
int P, Q, A, B, C;
bool ma[10000007];
ll f[N][N], a[N][N];
vector<int> vec;
long long res = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define name ""
     freopen (name".inp","r",stdin);
     freopen (name".out","w",stdout);

    cin >> m >> n >> k;
    cin >> P >> Q >> A >> B >> C;
    while (P-- > 0) {
        ma[Q] = true;
        ll x = (ll)((ll)Q * A + B) % C + 1;
        Q = x;
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) a[i][j] = i + (ll)(j - 1) * m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k; j++)
            if (ma[a[i][j]]) {
                int x = a[i][j];
                for (int ni = 1; ni <= n/k; ni++)
                    if (x + k*m*ni <= m*n) ma[x + k * m * ni] = true;
            }
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= m; i++)
            if (!ma[a[i][j]]) {
                if (j <= k)
                    f[i][j] = 1;
                if (!ma[a[i - 1][j - 1]])
                    f[i][j] = (f[i][j] % mod + f[i - 1][j - 1] % mod) % mod;
                if (!ma[a[i][j - 1]])
                    f[i][j] = (f[i][j] % mod + f[i][j - 1] % mod) % mod;
                if (!ma[a[i + 1][j - 1]])
                    f[i][j] = (f[i][j] % mod + f[i + 1][j - 1] % mod);
                f[i][j]%=mod;
            }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cout << f[i][j] << " \n"[j==n];
    for (int i = 1; i <= m; i++) {
        res += f[i][n];
        res %= mod;
    }
    cout << res << '\n';
}
