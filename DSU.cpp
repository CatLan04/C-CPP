#include <iostream>
#include <cstring>
using namespace std;
int n, cha[1000007], Rank[1000007], m;
int root(int n) {
	return (cha[n] == n) ? n : cha[n] = root(cha[n]);
}
void join(int x, int y) {
	int u = root(x);
	int v = root(y);
	if (u == v)return;
	if (Rank[u] == Rank[v])Rank[u]++;
	if (Rank[u] > Rank[v])cha[v] = u;
	else cha[u] = v;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cha[i] = i;
	while (m--) {
		int tv, x, y;
		cin >> tv >> x >> y;
		if (tv == 1)join(x, y);
		else cout << (root(x) == root(y)) << endl;
	}
}