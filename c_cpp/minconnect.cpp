// minconnect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <math.h>
using namespace std;
int n, m, p[100007], num, cha[100007], f[100007], dem[100007];
struct Data
{
    int U, V, cost;
};
Data a[400007];
bool cmp(Data a, Data b) {
    return a.cost > b.cost;
}

int Find(int n) {
    if (cha[n] == n)return n;
    return Find(cha[n]);
}
void Match(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x == y)return;
    if (dem[x] >= dem[y]) {
        cha[y] = x;
        p[x] = min(p[x], p[y]);
        dem[x] += dem[y];
        f[dem[x]] = max(f[dem[x]], p[x]);
    }
    else {
        cha[x] = y;
        p[y] = min(p[x], p[y]);
        dem[y] += dem[x];
        f[dem[y]] = max(f[dem[y]], p[y]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream fi("minconnect.inp");
    ofstream fo("minconnect.out");
    fi >> n >> m;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++)fi >> p[i], cha[i] = i, dem[i] = 1, f[1]=max(f[1], p[i]);
    for (int i = 1; i <= m; i++) {
        int x, y;
        fi >> x >> y;
        if (p[x] > p[y]) {
            a[++num] = { x, y, p[y] };
        }
        else a[++num] = { y, x, p[x] };
    }
    sort(a + 1, a + num + 1, cmp);
    for (int i = 1; i <= num; i++) {
        Match(a[i].U, a[i].V);
    }
    int tmp = -1;
    for (int i = n; i >= 1; i--) {
        if (f[i] != -1)tmp = f[i];
        else f[i] = tmp;
    }
    for (int i = 1; i <= n; i++)fo << f[i] << " ";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
