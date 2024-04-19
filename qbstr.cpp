#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int f[N][N],m,n;
string a,b;
main()
{
	#define name "qbstr"
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
	cin>>a>>b;
	n=a.size();
	m=b.size();
	a=" "+a;
	b=" "+b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i][j-1],f[i-1][j]);
		}
	cout<<f[n][m];
}